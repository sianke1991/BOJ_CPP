#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

/**보드의 크기: 1행부터 boardSize행까지 boardSize 개의 행을 사용한다.*/
int boardSize;

int makeSquare(int rowNum, int colNum) {
    return rowNum*100+colNum;
}


int rowNumOf(int square) {
    return square/100;
}

int colNumOf(int square) {
    return square%100;
}

const int dRow[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dCol[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

/**
 * 나이트가 움직일 수 있는 칸 목록을 반환한다.
 * 보드 밖으로 나가는 칸은 제외한다.
 */
unordered_map<int, double> squaresKnightCanMoveFrom(int square) {
    unordered_map<int, double> result;
    int row = rowNumOf(square);
    int col = colNumOf(square);
    for (int dir=0; dir<8; dir++) {
        int nRow = row+dRow[dir];
        int nCol = col+dCol[dir];
        if (nRow<1 || nRow>boardSize || nCol<1 || nCol>boardSize)
            continue;
        result[makeSquare(nRow, nCol)] = 1.0;
    } //dir loop
    return result;
}

/**
 * 두 맵을 합한 결과를 반환한다.
 */
unordered_map<int, double> mergeunordered_maps(unordered_map<int, double> m0, unordered_map<int, double> m1) {
    unordered_map<int, double> result;
    for (auto entry:m0) {
        result[entry.first] += entry.second;
    }
    for (auto entry:m1) {
        result[entry.first] += entry.second;
    }
    return result;
}

/**
 *  맵 목록을 합한 결과를 반환한다,
 */
unordered_map<int, double> mergeunordered_maps(vector<unordered_map<int, double>> ms) {
    unordered_map<int, double> result;
    for (unordered_map<int, double> m:ms) {
        for (auto entry:m) {
            result[entry.first] += entry.second;
        } //entry loop
    } //m loop
    return result;
}

/**
 * dpArray
 * dpArray[square][steps]: square에서 출발하여 steps 번 이동하여 도달할 수 있는 칸 목록(특정 칸에 도달할 방법이 여러 개인 경우 그 개수를 기록한다.)
 */
unordered_map<int, double> dpArray[5151][51];

/**
 * dpArrayFixed
 * dpArrayFixed[a][b]: dpArray[a][b]가 계산된 적이 있는지 여부를 기록한다. (초기값은 전부 false)
 */
bool dpArrayFixed[5151][51];

/**
 * 출발칸과 움직임 횟수를 입력받아 도착할 수 있는 칸 목록을 반환한다.
 */
unordered_map<int, double> getDpArrayOf(int square, int steps) {
    //해당 값이 이미 계산된 경우라면 그 계산된 값을 그대로 사용한다. (메모이제이션)
    if (dpArrayFixed[square][steps])
        return dpArray[square][steps];

    //베이스 케이스
    if (steps==1) {
        dpArray[square][steps] = squaresKnightCanMoveFrom(square);
        dpArrayFixed[square][steps] = true;
        return dpArray[square][steps];
    }

    //베이스 케이스
    if (steps==0) {
        unordered_map<int, double> m;
        m[square] = 1.0;
        dpArray[square][steps] = m;
        dpArrayFixed[square][steps] = true;
        return dpArray[square][steps];
    }

    //점화식
    for (auto entry:getDpArrayOf(square, 1)) { //entry.first는 square에서 출발하여 나이트가 갈 수 있는 칸이 된다.
        dpArray[square][steps] = mergeunordered_maps(dpArray[square][steps], getDpArrayOf(entry.first, steps-1));
    }
    dpArrayFixed[square][steps] = true;
    return dpArray[square][steps];
}

int main() {
    int initialRowNum, initialColNum, numSteps;
    scanf("%d %d %d %d", &boardSize, &initialRowNum, &initialColNum, &numSteps);
    unordered_map<int, double> targetSquareProfile = getDpArrayOf(makeSquare(initialRowNum, initialColNum), numSteps);

    double result = 0.;
    for (auto entry:targetSquareProfile) {
        result += entry.second;
    } // 나이트가 보드 위에 남을 경우의 수를 계산한다.
    result /= pow(8, numSteps); // 전체 경우의 수인 [8의 numSteps 제곱]으로 나누어 확률을 계산한다.
    printf("%.12f", result);
    return 0;
}
