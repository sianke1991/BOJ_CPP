#include <iostream>

using namespace std;

int n;
int board[32768][20][20];
const int UP    = 1;
const int DOWN  = 2;
const int LEFT  = 3;
const int RIGHT = 4;
int dRow[] = {0, -1, 1, 0, 0};
int dCol[] = {0, 0, 0, -1, 1};
int globalMax = -1; //다섯 번 움직인 뒤에 나올 수 있는 값 중 최대치

/*
000 000 000 000 000
--- --- --- --- ---
 a   b   c   d   e
e: 첫 번째 움직임: (000: 움직이지 않음, 001: 위로 움직임, 010: 아래로 움직임, 011: 왼쪽으로 움직임, 100: 오른쪽으로 움직임)
d: 두 번째 움직임
c: 세 번째 움직임
b: 네 번째 움직임
a: 다섯 번째 움직임
*/

/**
 * boardFrom의 내용을 boardTo에 복사한다.
 */
void copyBoard(int boardTo, int boardFrom) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			board[boardTo][i][j] = board[boardFrom][i][j];
		}
	}
}

/**
 * boardTarget의 내용을 출력한다.
 */
void showBoard(int boardTarget) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << board[boardTarget][i][j] << ' ';
		}
		cout << '\n';
	}
}

/**
 * boardTarget에 있는 수 중 최대치를 반환한다.
 */
int getLocalMax(int boardTarget) {
	int result = -1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (board[boardTarget][i][j]>result) result = board[boardTarget][i][j];
		}
	}
	return result;
}

/**
 * boardFrom에서 위로 올린 결과를 boardTo에 저장한다.
 */
void moveUp(int boardTo, int boardFrom) {
	copyBoard(boardTo, boardFrom);
	for (int row=1; row<n; row++) {
		for (int col=0; col<n; col++) {
			int curRow = row;
			int curCol = col;
			if (board[boardTo][curRow][curCol]==0) continue; //비어있는 칸은 움직임을 고려할 필요가 없다.
			while (1) { //위로 여러 칸을 가야 하는 경우를 고려해야 하므로 반복문이 필요하다.
				int newRow = curRow + dRow[UP];
				int newCol = curCol + dCol[UP];
				if (newRow<0) break; //out of bounds
				int curVal = board[boardTo][curRow][curCol]; //보드 위의 특정 위치에 있는 값
				int newVal = board[boardTo][newRow][newCol];
				if (newVal==0) { //바로 위 칸이 빈 칸인 경우 해당 값은 위로 이동한다.
					board[boardTo][newRow][newCol] = curVal; //보드의 값을 변경하고,
					board[boardTo][curRow][curCol] = 0;
					curRow = newRow; //현재 고려하고 있는 칸의 위치도 변경한다.
					curCol = newCol;
					continue;
				} else if (newVal==curVal) { //바로 위 칸이 합쳐져야 할 경우-
					board[boardTo][newRow][newCol] = curVal+newVal; //합쳐지는 칸은 값이 더해지고,
					board[boardTo][curRow][curCol] = 0; //본래의 칸은 비게 된다.
					break; //합쳐진 이후 해당 칸의 이동은 없다.
				} else { //바로 위 칸의 값이 다른 경우-
					break;
				}
				
			} //while loop
		} //col loop
	} //row loop
}

/**
 * boardFrom에서 아래로 내린 결과를 boardTo에 저장한다.
 */
void moveDown(int boardTo, int boardFrom) {
	copyBoard(boardTo, boardFrom);
	for (int row=n-2; row>=0; row--) {
		for (int col=0; col<n; col++) {
			int curRow = row;
			int curCol = col;
			if (board[boardTo][curRow][curCol]==0) continue;
			while (1) {
				int newRow = curRow + dRow[DOWN];
				int newCol = curCol + dCol[DOWN];
				if (newRow>=n) break; //out of bounds
				int curVal = board[boardTo][curRow][curCol];
				int newVal = board[boardTo][newRow][newCol];
				if (newVal==0) {
					board[boardTo][newRow][newCol] = curVal;
					board[boardTo][curRow][curCol] = 0;
					curRow = newRow;
					curCol = newCol;
					continue;
				} else if (newVal==curVal) {
					board[boardTo][newRow][newCol] = curVal+newVal;
					board[boardTo][curRow][curCol] = 0;
					break;
				} else {
					break;
				}
			} //while loop
		} //col loop
	} //row loop (가장 큰 값에서 시작해야 한다.)
}

/**
 * boardFrom에서 왼쪽으로 이동한 결과를 boardTo에 저장한다.
 */
void moveLeft(int boardTo, int boardFrom) {
	copyBoard(boardTo, boardFrom);
	for (int col=1; col<n; col++) {
		for (int row=0; row<n; row++) {
			int curRow = row;
			int curCol = col;
			if (board[boardTo][curRow][curCol]==0) continue;
			while (1) {
				int newRow = curRow + dRow[LEFT];
				int newCol = curCol + dCol[LEFT];
				if (newCol<0) break; //out of bounds
				int curVal = board[boardTo][curRow][curCol];
				int newVal = board[boardTo][newRow][newCol];
				if (newVal==0) {
					board[boardTo][newRow][newCol] = curVal;
					board[boardTo][curRow][curCol] = 0;
					curRow = newRow;
					curCol = newCol;
					continue;
				} else if (newVal==curVal) {
					board[boardTo][newRow][newCol] = curVal+newVal;
					board[boardTo][curRow][curCol] = 0;
					break;
				} else {
					break;
				}
			} //while loop
		} //row loop
	} //col loop (이중 루프의 순서가 변경되어야 한다.)
}

/**
 * boardFrom에서 오른쪽으로 이동한 결과를 boardTo에 저장한다.
 */
void moveRight(int boardTo, int boardFrom) {
	copyBoard(boardTo, boardFrom);
	for (int col=n-2; col>=0; col--) {
		for (int row=0; row<n; row++) {			
			int curRow = row;
			int curCol = col;
			if (board[boardTo][curRow][curCol]==0) continue;
			while (1) {
				int newRow = curRow + dRow[RIGHT];
				int newCol = curCol + dCol[RIGHT];
				if (newCol>=n) break; //out of bounds
				int curVal = board[boardTo][curRow][curCol];
				int newVal = board[boardTo][newRow][newCol];
				if (newVal==0) {
					board[boardTo][newRow][newCol] = curVal;
					board[boardTo][curRow][curCol] = 0;
					curRow = newRow;
					curCol = newCol;
					continue;
				} else if (newVal==curVal) {
					board[boardTo][newRow][newCol] = curVal+newVal;
					board[boardTo][curRow][curCol] = 0;
					break;
				} else {
					break;
				}
			}
		} //row loop
	} //col loop (가장 큰 값에서 시작해야 한다.)
}

void recursion(int numMoves, int boardNumber) {
	if (numMoves==5) {
		int localMax = getLocalMax(boardNumber);
		if (localMax>globalMax) globalMax = localMax;
		return;
	}
	moveUp(boardNumber|(UP<<(3*numMoves)), boardNumber);
	recursion(numMoves+1, boardNumber|(UP<<(3*numMoves)));
	//boardNumber&=~(UP<<(3*numMoves));
	moveDown(boardNumber|(DOWN<<(3*numMoves)), boardNumber);
	recursion(numMoves+1, boardNumber|(DOWN<<(3*numMoves)));
	//boardNumber&=~(DOWN<<(3*numMoves));
	moveLeft(boardNumber|(LEFT<<(3*numMoves)), boardNumber);
	recursion(numMoves+1, boardNumber|(LEFT<<(3*numMoves)));
	//boardNumber&=~(LEFT<<(3*numMoves));
	moveRight(boardNumber|(RIGHT<<(3*numMoves)), boardNumber);
	recursion(numMoves+1, boardNumber|(RIGHT<<(3*numMoves)));
	//boardNumber&=~(RIGHT<<(3*numMoves));
}



int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[0][i][j];
		}
	}
	recursion(0, 0);
	cout << globalMax;
	
	return 0;
	
}