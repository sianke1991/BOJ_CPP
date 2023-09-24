#include <bits/stdc++.h>

using namespace std;

/**보드판 크기*/
int Size;
/**체스판 주 대각선의 하향 대각선 번호*/
int median;
/**각 체스 칸에 비숍이 올라올 수 있는지 여부*/
bool bishopAvailableAt[10][10];
/**각 하향 대각선에 대해 비숍이 위치하는 상향 대각선 번호. (해당 하향 대각선에 대해 비숍이 없는 경우 -1을 위치시킨다.)*/
int uDiagArr[19] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
/**각 상향 대각선에 대해 비숍이 차지했는지 여부*/
bool usedUDiag[19];
/**해당 체스판에 대해 놓을 수 있는 비숍의 최대 개수*/
int optResult = 0;



/**입력받은 정수의 절대값을 반환한다.*/
int abs(int num) {
    return num>=0 ? num : -num;
}
/**입력받은 체스판의 하향 대각선 번호를 반환한다. 좌하귀를 지나는 대각선이 0, 우상귀를 지나는 대각선이 최대치가 된다.*/
int dDiagNum(int row, int col) {
    return Size-1+col-row;
}
/**입력받은 체스판의 상향 대각선 번호를 반환한다. 좌상귀를 지나는 대각선이 0, 우하귀를 지나는 대각선이 최대치가 된다,*/
int uDiagNum(int row, int col) {
    return col+row;
}
/**두 대각선 번호를 입력받아 대응되는 열번호를 반환한다. 좌변을 지나는 열이 0, 우변을 지나는 열이 최대치가 된다.*/
int colNum(int dDiag, int uDiag) {
    return (dDiag+uDiag-Size+1)/2;
}
/**두 대각선 번호를 입력받아 대응되는 행번호를 반환한다. 상변을 지나는 행이 0, 하변을 지나는 행이 최대치가 된다.*/
int rowNum(int dDiag, int uDiag) {
    return (Size-1-dDiag+uDiag)/2;
}
/**하향 대각선 번호를 입력받아 하향 대각선 번호에 올 수 있는 상향 대각선 번호의 최소치를 반환한다.*/
int minUDiagNum(int dDiag) {
    return abs(dDiag-median);
}
int maxUDiagNum(int dDiag) {
    return 2*median-abs(dDiag-median);
}

//재귀 함수 (dDiag: 이번에 놓을 비숍의 하향 대각선 번호)
void backtrack(int dDiag, int cnt) {
    //베이스 케이스
    if (dDiag==2*Size-1) {
        if (cnt>optResult) optResult=cnt;
        return;
    }

    //해당 하향 대각선에는 비숍을 놓지 않고 넘기는 선택지
    uDiagArr[dDiag] = -1;
    backtrack(dDiag+1, cnt);

    //해당 하향 대각선 중 가능한 칸에 비숍을 넣고 넘기는 선택지
    for (int uDiag=minUDiagNum(dDiag); uDiag<=maxUDiagNum(dDiag); uDiag+=2) {
        if (usedUDiag[uDiag]) continue; //해당 상향 대각선 칸이 이미 차지된 경우-
        int row = rowNum(dDiag, uDiag);
        int col = colNum(dDiag, uDiag);
        if (!bishopAvailableAt[row][col]) continue; //해당 칸에 비숍을 놓을 수 없는 경우-
        uDiagArr[dDiag] = uDiag;
        usedUDiag[uDiag] = true;
        backtrack(dDiag+1, cnt+1);
        usedUDiag[uDiag] = false;
        uDiagArr[dDiag] = -1;
    } //uDiag loop
}




int main() {
    cin >> Size;
    median = Size-1;
    for (int row=0; row<Size; row++) {
        for (int col=0; col<Size; col++) {
            cin >> bishopAvailableAt[row][col];
        } //col loop
    } //row loop
    backtrack(0, 0);
    cout << optResult;
    return 0;
}
