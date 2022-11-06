#include <bits/stdc++.h>
using namespace std;

/**
    N: 현재 단계 수. 현재 단계에서 고려하는 행 및 열의 개수는 2**N 개이다.
    r: 현재 고려하는 그리드 내에서의 행 번호 (0이상 2**N 미만)
    c: 현재 고려하는 그리드 내에서의 열 번호 (0이상 2**N 미만)
*/
int getNumSteps(int N, int r, int c) {
    //base cases
    if (N==0) {
        return 0;
    } else if (N==1) {
        return 2*r+c;
    }

    int isRowGreaterThanHalf = r>=(1<<(N-1));
    int isColGreaterThanHalf = c>=(1<<(N-1));
    int quadrant             = isRowGreaterThanHalf*2+isColGreaterThanHalf;
    int numQuarterGrids      = 1<<(2*N-2);
    int lengthHalfSide       = 1<<(N-1);
    return quadrant*numQuarterGrids+getNumSteps(N-1, r%lengthHalfSide, c%lengthHalfSide);
}

int getNumSteps2(int N, int r, int c) {
    //base cases
    if (N==0) return 0;
    int isRowGreaterThanHalf = r>=(1<<(N-1));
    int isColGreaterThanHalf = c>=(1<<(N-1));
    int quadrant             = isRowGreaterThanHalf*2+isColGreaterThanHalf; //왼쪽 위가 0사분면, 오른쪽 위가 1사분면, 왼쪽 아래가 2사분면, 오른쪽 아래가 3사분면
    int lenHalfSide          = 1<<(N-1);
    switch (quadrant) {
        case 0:
            return getNumSteps2(N-1, r, c);
        case 1:
            return lenHalfSide*lenHalfSide+getNumSteps2(N-1, r, c-lenHalfSide); //r은 절반을 넘지 않기 때문에 lenHalfSide만큼 빼지 않아도 OK.
        case 2:
            return 2*lenHalfSide*lenHalfSide+getNumSteps2(N-1, r-lenHalfSide, c); //c는 절반을 넘지 않기 때문에 lenHalfSide만큼 빼지 않아도 OK.
        case 3:
            return 3*lenHalfSide*lenHalfSide+getNumSteps2(N-1, r-lenHalfSide, c-lenHalfSide);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << getNumSteps(N, r, c);
    return 0;
}
