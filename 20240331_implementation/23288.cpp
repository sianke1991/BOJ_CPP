#include <bits/stdc++.h>
#include <stdio.h>
// sianke1991
// 주사위 면 이름 정의
#define TOP 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define FRONT 4
#define BOTTOM 5
#define row first
#define col second

using namespace std;

// 주사위 굴러가는 방향 정의
struct Direction {
    char initial;
    int dRow;
    int dCol;
};

const Direction NONE = {'O', 0, 0};
const Direction EAST = {'E', 0, 1};
const Direction SOUTH = {'S', 1, 0};
const Direction WEST = {'W', 0, -1};
const Direction NORTH = {'N', -1, 0};

vector<Direction> directions = {EAST, SOUTH, WEST, NORTH};

// 입력받은 방향의 반대 방향을 반환한다.
Direction oppositeDirectionOf(Direction dir) {
    switch (dir.initial) {
         case 'E': return WEST;
         case 'S': return NORTH;
         case 'W': return EAST;
         case 'N': return SOUTH;
         default: return NONE;
    }
}

// 입력받은 방향의 시계 방향을 반환한다.
Direction clockwiseDirectionOf(Direction dir) {
    switch (dir.initial) {
        case 'E': return SOUTH;
        case 'S': return WEST;
        case 'W': return NORTH;
        case 'N': return EAST;
        default: return NONE;
    }
}

// 입력받은 방향의 반시계 방향을 반환한다.
Direction anticlockwiseDirectionOf(Direction dir) {
    switch (dir.initial) {
        case 'E': return NORTH;
        case 'S': return EAST;
        case 'W': return SOUTH;
        case 'N': return WEST;
        default: return NONE;
    }
}

// 지도의 세로 크기 (행의 개수)
int numRows;
// 지도의 가로 크기 (열의 개수)
int numCols;
// 주사위가 이동할 수 있는 횟수
int numTotalRolls;

// 입력받은 칸에서 입력받은 방향으로 한 칸 이동할 때 나오는 칸을 반환한다.
pair<int, int> nextSquareIn(Direction dir, pair<int, int> square) {
    return {square.row+dir.dRow, square.col+dir.dCol};
}

// 입력받은 칸이 경계를 벗어나는지 여부를 반환한다.
bool checkOBOf(pair<int, int> square) {
    return square.row<0 || square.row>=numRows || square.col<0 || square.col>=numCols;
}


// 주사위 각 면의 수
int die[6] = {1, 2, 3, 4, 5, 6};
// 주사위의 위치
pair<int, int> dieSquare = {0, 0};
// 주사위의 이동 방향
Direction dieDirection = EAST;
// 점수 누적 결과
int accumScore = 0;

int board[21][21];
int boardPoint[21][21];

// 보드 위의 입력받은 칸에 있는 수를 반환한다.
int boardNumberAt(pair<int, int> square) {
    return board[square.row][square.col];
}

// 주사위가 보드 위의 해당 칸에 도달했을 때 얻을 수 있는 점수를 반환한다.
int pointAt(pair<int, int> square) {
    if (boardPoint[square.row][square.col])
        return boardPoint[square.row][square.col];

    int numberOnSquare = boardNumberAt(square);
    set<pair<int, int>> visitedSquares;
    visitedSquares.insert(square);
    queue<pair<int, int>> q;
    q.push(square);
    while (!q.empty()) {
        pair<int, int> currentSquare = q.front();
        q.pop();
        for (Direction dir:directions) {
            pair<int, int> nextSquare = nextSquareIn(dir, currentSquare);
            if (checkOBOf(nextSquare)) //이웃한 칸이 경계를 벗어나는 경우
                continue;
            if (boardNumberAt(nextSquare)!=numberOnSquare) //이웃한 칸이 다른 수를 가지고 있는 경우
                continue;
            if (visitedSquares.find(nextSquare)!=visitedSquares.end()) //이웃한 칸에 이미 방문한 경우
                continue;
            visitedSquares.insert(nextSquare);
            q.push(nextSquare);
        } //dir loop
    } //while q is not empty

    int result = numberOnSquare * visitedSquares.size();
    for (pair<int, int> square:visitedSquares) {
        boardPoint[square.row][square.col] = result;
    }
    return result;
}

// 주사위를 굴린다.
void roll() {
    // 주사위를 한 번 굴려서 도달할 칸
    pair<int, int> dieNextSquare = nextSquareIn(dieDirection, dieSquare);
    if (checkOBOf(dieNextSquare)) { // 해당 칸이 경계를 벗어나는 경우 방향을 반대로 하여 한 칸 굴린다.
        dieDirection = oppositeDirectionOf(dieDirection);
        dieNextSquare = nextSquareIn(dieDirection, dieSquare);
    }
    dieSquare = dieNextSquare;
    switch (dieDirection.initial) { //주사위를 굴린 방향에 따라 주사위의 면 구성을 변경시킨다.
        case 'E': {
            int tmp = die[RIGHT];
            die[RIGHT] = die[TOP];
            die[TOP] = die[LEFT];
            die[LEFT] = die[BOTTOM];
            die[BOTTOM] = tmp;
            break;
        }
        case 'S': {
            int tmp = die[FRONT];
            die[FRONT] = die[TOP];
            die[TOP] = die[BACK];
            die[BACK] = die[BOTTOM];
            die[BOTTOM] = tmp;
            break;
        }
        case 'W': {
            int tmp = die[LEFT];
            die[LEFT] = die[TOP];
            die[TOP] = die[RIGHT];
            die[RIGHT] = die[BOTTOM];
            die[BOTTOM] = tmp;
            break;
        }
        case 'N': {
            int tmp = die[BACK];
            die[BACK] = die[TOP];
            die[TOP] = die[FRONT];
            die[FRONT] = die[BOTTOM];
            die[BOTTOM] = tmp;
            break;
        }
    } //switch dieDirection
    accumScore += pointAt(dieSquare); //도착한 위치의 점수를 얻는다.
    //도착한 위치와 보드 칸의 수의 대소 관계에 따라 주사위의 방향을 변경한다.
    if (die[BOTTOM]>boardNumberAt(dieSquare)) {
        dieDirection = clockwiseDirectionOf(dieDirection);
    } else if (die[BOTTOM]<boardNumberAt(dieSquare)) {
        dieDirection = anticlockwiseDirectionOf(dieDirection);
    }
}

int main() {
    scanf("%d %d %d", &numRows, &numCols, &numTotalRolls);
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            scanf("%d", &board[i][j]);
        } //j loop
    } //i loop

    for (int i=0; i<numTotalRolls; i++) {
        roll();
    } //i loop (roll loop)
    printf("%d", accumScore);

    return 0;
}
