#include <iostream>
#include <vector>

using namespace std;

int dCol[] = {0, 1, 0, -1};
int dRow[] = {-1, 0, 1, 0};

//1: up, 2: right, 4: down, 8: left
//각 타입에 해당하는 카메라가 볼 수 있는 방향 //첫 번째 인덱스는 카메라 종류
const int CAMERA_DIRECTIONS[6][4] = {
    {0, 0, 0, 0},
    {1, 2, 4, 8}, //1번 카메라는 {위}, {오른쪽}, {아래}, {왼쪽}을 볼 수 있다.
    {5, 10, 0, 0}, //2번 카메라는 {위, 아래}, {왼쪽, 오른쪽}을 볼 수 있다.
    {3, 6, 9, 12},
    {7, 11, 13, 14},
    {15, 0, 0, 0}
};

struct Camera {
    int type;
    int row;
    int col;
    int dirIndx;
};

vector <Camera> cameraList;
int N, M; //N: 행의 개수, M: 열의 개수
int board[9][9];
int boardBackup[9][9];
int minDeadArea = 100;

//boardBackup의 내용으로 board의 내용을 초기화함
void reset() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            board[i][j] = boardBackup[i][j];
        }
    }
}

/**현재 보드에서 0인 칸의 개수를 반환한다.*/
int getDeadArea() {
	int result = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (board[i][j]==0) result++;
		}
	}
	return result;
}

void showBoard(int camerasDirectionIdx) {
	cout << "\n-------------------\n";
	cout << "current camerasDirectionIdx: " <<camerasDirectionIdx<<'\n';
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-------------------\n";
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> boardBackup[i][j];
            if (boardBackup[i][j]>0 && boardBackup[i][j]<6) {
                Camera camera = {boardBackup[i][j], i, j, -1};
                cameraList.push_back(camera);
            }
        }
    }
    int numCameras = cameraList.size();
    for (int camerasDirectionIdx=0; camerasDirectionIdx<(1<<(2*numCameras)); camerasDirectionIdx++) {
        reset();
        
        for (int cameraIdx=0; cameraIdx<numCameras; cameraIdx++) {
        	Camera camera = cameraList[cameraIdx];
            int cameraDirection = CAMERA_DIRECTIONS[camera.type][(camerasDirectionIdx&(3<<(2*cameraIdx)))>>(2*cameraIdx)]; //카메라가 볼 수 있는 방향. 첫 번째 인덱스는 카메라의 종류, 두 번째 인덱스는 0-3 사이의 정수이다. (카메라가 회전이 가능하기 때문에 두 번째 인덱스를 둬서 서로 다른 방향을 보는 카메라를 구현한다.)
            int startingCol = cameraList[cameraIdx].col;
            int startingRow = cameraList[cameraIdx].row;
            
            if (cameraDirection&1) { //if the camera can watch up direction
                int currentCol = startingCol;
                int currentRow = startingRow;
                while (1) {
                    currentCol += dCol[0];
                    currentRow += dRow[0];
                    //빠져 나갈 조건
                    if (currentCol<0 || currentCol>=M) break;
                    if (currentRow<0 || currentRow>=N) break;
                    if (board[currentRow][currentCol]==6) break;
                    if (board[currentRow][currentCol]==0) board[currentRow][currentCol] = -1;
                } //while loop
            }
            
            if (cameraDirection&2) { //if the camera can watch right direction (몇몇 카메라들은 여러 방향을 동시에 보기 때문에 else if가 아닌 if 를 사용해야 한다.)
            	int currentCol = startingCol;
            	int currentRow = startingRow;
            	while (1) {
            		currentCol += dCol[1];
            		currentRow += dRow[1];
            		//빠져 나갈 조건
                    if (currentCol<0 || currentCol>=M) break;
                    if (currentRow<0 || currentRow>=N) break;
                    if (board[currentRow][currentCol]==6) break;
                    if (board[currentRow][currentCol]==0) board[currentRow][currentCol] = -1;
				} //while loop
			}
			
			if (cameraDirection&4) { //if the camera can watch down direction
				int currentCol = startingCol;
            	int currentRow = startingRow;
            	while (1) {
            		currentCol += dCol[2];
            		currentRow += dRow[2];
            		//빠져 나갈 조건
                    if (currentCol<0 || currentCol>=M) break;
                    if (currentRow<0 || currentRow>=N) break;
                    if (board[currentRow][currentCol]==6) break;
                    if (board[currentRow][currentCol]==0) board[currentRow][currentCol] = -1;
				} //while loop
			}
			
			if (cameraDirection&8) { //if the camera can watch left direction
				int currentCol = startingCol;
            	int currentRow = startingRow;
            	while (1) {
            		currentCol += dCol[3];
            		currentRow += dRow[3];
            		//빠져 나갈 조건
                    if (currentCol<0 || currentCol>=M) break;
                    if (currentRow<0 || currentRow>=N) break;
                    if (board[currentRow][currentCol]==6) break;
                    if (board[currentRow][currentCol]==0) board[currentRow][currentCol] = -1;
				} //while loop
			}
        } //cameraIdx loop
		int currentDeadArea = getDeadArea();
		if (currentDeadArea<minDeadArea){
			minDeadArea = currentDeadArea;
			//showBoard(camerasDirectionIdx);
		}
    } //최대 8개의 카메라 방향 루프
	cout << minDeadArea;
	return 0;
}

