#include <iostream>
using namespace std;

int N;
long long numCases=0;
bool isRowUsed[15];
bool isMainDiagUsed[29];
bool isAntiDiagUsed[29];

/**주대각선(왼쪽 위에서 오른쪽 아래로 내려가는 대각선)의 인덱스를 반환한다.*/
int getMainDiagIdx(int row, int col) {
	return col-row+N-1;
}
/**부대각선(오른쪽 위에서 왼쪽 아래로 내려가는 대각선)의 인덱스를 반환한다.*/
int getAntiDiagIdx(int row, int col) {
	return row+col;
}

void recursive(int col) {
	//base case
	if (col==N) {
		numCases++;
		return;
	}
	
	for (int row=0; row<N; row++) {
		if (isRowUsed[row] || isMainDiagUsed[getMainDiagIdx(row, col)] || isAntiDiagUsed[getAntiDiagIdx(row, col)]) continue;
		isRowUsed[row] = true;
		isMainDiagUsed[getMainDiagIdx(row, col)] = true;
		isAntiDiagUsed[getAntiDiagIdx(row, col)] = true;
		recursive(col+1);
		isRowUsed[row] = false;
		isMainDiagUsed[getMainDiagIdx(row, col)] = false;
		isAntiDiagUsed[getAntiDiagIdx(row, col)] = false;
	} //row loop
}

int main() {
	cin >> N;
	recursive(0);
	cout << numCases;
	return 0;
}