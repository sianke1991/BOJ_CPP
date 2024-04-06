#include <bits/stdc++.h>
#include <stdio.h>
#define LEFT 0
#define BOTTOM 1
#define RIGHT 2
#define TOP 3

using namespace std;
// 각 방향에 대한 행 변화
const int dRow[4] = {0, 1, 0, -1};

// 각 방향에 대한 열 변화
const int dCol[4] = {-1, 0, 1, 0};

// 보드의 크기
int boardSize;

// 각 칸에 있는 모래의 양
int sand[500][500];

// 각 칸에 토네이도가 도달했는지 여부
bool visited[500][500];

// 보드 밖으로 나간 모래의 양
int overflowingSand = 0;

int tornadoRow;
int tornadoCol;
int tornadoDir = LEFT;

// 입력받은 방향의 반시계 방향을 반환한다.
int counterClockwiseOf(int dir) {
    return (dir+1)%4;
}

int clockwiseOf(int dir) {
    return (dir+4-1)%4;
}

int reverseOf(int dir) {
    return (dir+2)%4;
}

// 입력받은 칸이 보드 밖을 벗어나는지 여부를 반환한다.
bool checkOBOf(int row, int col) {
    return row<0 || row>=boardSize || col<0 || col>=boardSize;
}

// 토네이도를 한 칸 이동한다.
// 토네이도가 목적지에 도달하여 더 이상 이동할 수 없으면 false를 반환한다.
bool tornadoMove() {
    //printf("%d, %d\n", tornadoRow, tornadoCol);
     // 토네이도가 목적지에 도달했는지 여부를 계산한다.
    if (tornadoRow==0 && tornadoCol==0)
        return false;

    // 토네이도를 토네이도 방향으로 한 칸 이동한다.
    tornadoRow += dRow[tornadoDir];
    tornadoCol += dCol[tornadoDir];
    visited[tornadoRow][tornadoCol] = true;

    if (sand[tornadoRow][tornadoCol]) {
        int counterClockwiseDir = counterClockwiseOf(tornadoDir);
        int clockwiseDir = clockwiseOf(tornadoDir);
        int reverseDir = reverseOf(tornadoDir);
        int sandAmountSum = 0;
        long long sandAmount = 0;

        int row7_a = tornadoRow+dRow[counterClockwiseDir];
        int col7_a = tornadoCol+dCol[counterClockwiseDir];
        sandAmount = sand[tornadoRow][tornadoCol]*7LL/100;
        if (checkOBOf(row7_a, col7_a)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row7_a][col7_a]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row7_b = tornadoRow+dRow[clockwiseDir];
        int col7_b = tornadoCol+dCol[clockwiseDir];
        //sandAmount = sand[tornadoRow][tornadoCol]*7LL/100;
        if (checkOBOf(row7_b, col7_b)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row7_b][col7_b]+=sandAmount;
        }
        sandAmountSum+=sandAmount;


        int row2_a = row7_a+dRow[counterClockwiseDir];
        int col2_a = col7_a+dCol[counterClockwiseDir];
        sandAmount = sand[tornadoRow][tornadoCol]*2LL/100;
        if (checkOBOf(row2_a, col2_a)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row2_a][col2_a]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row2_b = row7_b+dRow[clockwiseDir];
        int col2_b = col7_b+dCol[clockwiseDir];
        //sandAmount = sand[tornadoRow][tornadoCol]*2LL/100;
        if (checkOBOf(row2_b, col2_b)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row2_b][col2_b]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row1_a = row7_a+dRow[reverseDir];
        int col1_a = col7_a+dCol[reverseDir];
        sandAmount = sand[tornadoRow][tornadoCol]*1LL/100;
        if (checkOBOf(row1_a, col1_a)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row1_a][col1_a]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row1_b = row7_b+dRow[reverseDir];
        int col1_b = col7_b+dCol[reverseDir];
        //sandAmount = sand[tornadoRow][tornadoCol]*1LL/100;
        if (checkOBOf(row1_b, col1_b)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row1_b][col1_b]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row10_a = row7_a+dRow[tornadoDir];
        int col10_a = col7_a+dCol[tornadoDir];
        sandAmount = sand[tornadoRow][tornadoCol]*10LL/100;
        if (checkOBOf(row10_a, col10_a)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row10_a][col10_a]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row10_b = row7_b+dRow[tornadoDir];
        int col10_b = col7_b+dCol[tornadoDir];
        //sandAmount = sand[tornadoRow][tornadoCol]*10LL/100;
        if (checkOBOf(row10_b, col10_b)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row10_b][col10_b]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int row5 = tornadoRow+2*dRow[tornadoDir];
        int col5 = tornadoCol+2*dCol[tornadoDir];
        sandAmount = sand[tornadoRow][tornadoCol]*5LL/100;
        if (checkOBOf(row5, col5)) {
            overflowingSand+=sandAmount;
        } else {
            sand[row5][col5]+=sandAmount;
        }
        sandAmountSum+=sandAmount;

        int rowAlpha = tornadoRow+dRow[tornadoDir];
        int colAlpha = tornadoCol+dCol[tornadoDir];
        if (checkOBOf(rowAlpha, colAlpha)) {
            overflowingSand+=sand[tornadoRow][tornadoCol]-sandAmountSum;
        } else {
            sand[rowAlpha][colAlpha]+=sand[tornadoRow][tornadoCol]-sandAmountSum;
        }

        sand[tornadoRow][tornadoCol] = 0;
    }


    // 다음 이동에 적용할 토네이도 방향을 계산한다.
    int nextTornadoDir = counterClockwiseOf(tornadoDir);
    if (!visited[tornadoRow+dRow[nextTornadoDir]][tornadoCol+dCol[nextTornadoDir]])
        tornadoDir = nextTornadoDir;
    return true;
}


int main() {
    scanf("%d", &boardSize);
    tornadoRow = boardSize/2;
    tornadoCol = boardSize/2;
    visited[tornadoRow][tornadoCol] = true;

    for (int row=0; row<boardSize; row++) {
        for (int col=0; col<boardSize; col++) {
            scanf("%d", &sand[row][col]);
        }
    }

    while (tornadoMove());

    printf("%d", overflowingSand);
    return 0;
}
