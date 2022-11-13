#include <iostream>

using namespace std;

int N;
long long numCases = 0;
int rows[15];
bool isRowUsed[15];
/**두 기물이 한 대각선에 있는지 여부를 반환한다. */
bool isOnDiagonal(int row0, int col0, int row1, int col1) {
    return (row0-col0 == row1-col1) || (row0+col0 == row1+col1);
}

void recursion(int col) {
    //base case
    if (col==N) {
        numCases++;
        return;
    }
    for (int row=0; row<N; row++) {
        if (isRowUsed[row]) continue;
        bool isSafePosition = true;
        for (int prevCol=0; prevCol<col; prevCol++) {
            if (isOnDiagonal(rows[prevCol], prevCol, row, col)) {
                isSafePosition = false;
                break;
            }
        } //prevCol loop
        if (!isSafePosition) continue;
        rows[col] = row;
        isRowUsed[row] = true;
        recursion(col+1);
        isRowUsed[row] = false;
    } //row loop
}

int main() {
    cin >> N;
    recursion(0);
    cout << numCases;
    return 0;
}
