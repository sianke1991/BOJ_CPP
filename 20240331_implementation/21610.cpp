#include <bits/stdc++.h>
#include <stdio.h>
#define ROW first
#define dRow first
#define COL second
#define dCol second
// sianke1991

using namespace std;

// 방향 정의
const pair<int, int> NONE = {0, 0};
const pair<int, int> LEFT = {0, -1};
const pair<int, int> TOP_LEFT = {-1, -1};
const pair<int, int> TOP = {-1, 0};
const pair<int, int> TOP_RIGHT = {-1, 1};
const pair<int, int> RIGHT = {0, 1};
const pair<int, int> BOTTOM_RIGHT = {1, 1};
const pair<int, int> BOTTOM = {1, 0};
const pair<int, int> BOTTOM_LEFT = {1, -1};
pair<int, int> directions[] = {NONE, LEFT, TOP_LEFT, TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT};

// 격자의 크기
int numRows;

// 해당 칸이 격자를 벗어나는지 여부를 반환한다.
bool checkOBOf(pair<int, int> square) {
    return square.ROW<0 || square.ROW>=numRows ||
            square.COL<0 || square.COL>=numRows;
}

// 격자를 벗어나는 칸에 대해 대응되는 격자의 칸을 반환한다.
pair<int, int> correspondingSquareOf(pair<int, int> square) {
    int row = square.ROW;
    int tmpNumRows = numRows*30;
    while (row<0) {
        row += tmpNumRows;
    }
    row %= numRows;
    int col = square.COL;
    while (col<0) {
        col += tmpNumRows;
    }
    col %= numRows;
    return {row, col};
}

// 입력받은 칸에서 입력받은 방향으로 입력받은 거리만큼 이동했을 때 나오는 칸을 반환한다.
pair<int, int> translatedSquare(pair<int, int> direction, int distance, pair<int, int> square) {
    pair<int, int> result = {square.ROW+direction.dRow*distance, square.COL+direction.dCol*distance};
    return correspondingSquareOf(result);
}

pair<int, int> nextSquareIn(pair<int, int> direction, pair<int, int> square) {
    return {square.ROW+direction.dRow, square.COL+direction.dCol};
}

// 입력받은 칸의 대각선 위치에 있는 칸 목록을 반환한다.
vector<pair<int, int>> diagonalSquaresOf(pair<int, int> square) {
    vector<pair<int, int>> result;
    pair<int, int> nextSquare = nextSquareIn(TOP_LEFT, square);
    if (!checkOBOf(nextSquare))
        result.push_back(nextSquare);
    nextSquare = nextSquareIn(TOP_RIGHT, square);
    if (!checkOBOf(nextSquare))
        result.push_back(nextSquare);
    nextSquare = nextSquareIn(BOTTOM_RIGHT, square);
    if (!checkOBOf(nextSquare))
        result.push_back(nextSquare);
    nextSquare = nextSquareIn(BOTTOM_LEFT, square);
    if (!checkOBOf(nextSquare))
        result.push_back(nextSquare);
    return result;
}

// 각 바구니에 들어있는 물의 양
int basket[51][51];

// 입력받은 위치에 있는 바구니에 들어있는 물의 양
int basketAt(pair<int, int> square) {
    return basket[square.ROW][square.COL];
}

// 움직이기 전의 구름의 위치
set<pair<int, int>> cloudsBeforeMoving;
// 움직인 후의 구름의 위치
set<pair<int, int>> cloudsAfterMoving;



void execute(int directionIndex, int distance) {
    pair<int, int> direction = directions[directionIndex];
    //step a. 움직인 후의 구름의 위치 계산
    cloudsAfterMoving.clear();
    for (pair<int, int> cloud:cloudsBeforeMoving) {
        cloudsAfterMoving.insert(translatedSquare(direction, distance, cloud));
    }
    //step b. 움직인 후의 구름에서 비가 내림
    for (pair<int, int> cloud:cloudsAfterMoving) {
        basket[cloud.ROW][cloud.COL]++;
    }
    //step c. 물복사버그 마법을 시전함
    for (pair<int, int> cloud:cloudsAfterMoving) {
        for (pair<int, int> diagonalSquare:diagonalSquaresOf(cloud)) {
            if (basketAt(diagonalSquare))
                basket[cloud.ROW][cloud.COL]++;
        }
    }
    //step d. 구름 생성
    cloudsBeforeMoving.clear();
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numRows; col++) {
            if (basket[row][col]>=2 && cloudsAfterMoving.find({row, col})==cloudsAfterMoving.end()) {
                basket[row][col] -= 2;
                cloudsBeforeMoving.insert({row, col});
            }
        }
    }
}

int main() {
    int numActions;
    scanf("%d %d", &numRows, &numActions);
    cloudsBeforeMoving.insert({numRows-1, 0});
    cloudsBeforeMoving.insert({numRows-1, 1});
    cloudsBeforeMoving.insert({numRows-2, 0});
    cloudsBeforeMoving.insert({numRows-2, 1});
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numRows; col++) {
            scanf("%d", &basket[row][col]);
        }
    }
    int directionIndices[101];
    int distances[101];
    for (int i=0; i<numActions; i++) {
        scanf("%d %d", &directionIndices[i], &distances[i]);
    }
    for (int action=0; action<numActions; action++) {
        execute(directionIndices[action], distances[action]);
    }

    int result = 0;
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numRows; col++) {
            result += basket[row][col];
        }
    }
    printf("%d", result);
    return 0;
}

