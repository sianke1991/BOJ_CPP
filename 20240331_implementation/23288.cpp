#include <bits/stdc++.h>
#include <stdio.h>
// sianke1991
// �ֻ��� �� �̸� ����
#define TOP 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define FRONT 4
#define BOTTOM 5
#define row first
#define col second

using namespace std;

// �ֻ��� �������� ���� ����
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

// �Է¹��� ������ �ݴ� ������ ��ȯ�Ѵ�.
Direction oppositeDirectionOf(Direction dir) {
    switch (dir.initial) {
         case 'E': return WEST;
         case 'S': return NORTH;
         case 'W': return EAST;
         case 'N': return SOUTH;
         default: return NONE;
    }
}

// �Է¹��� ������ �ð� ������ ��ȯ�Ѵ�.
Direction clockwiseDirectionOf(Direction dir) {
    switch (dir.initial) {
        case 'E': return SOUTH;
        case 'S': return WEST;
        case 'W': return NORTH;
        case 'N': return EAST;
        default: return NONE;
    }
}

// �Է¹��� ������ �ݽð� ������ ��ȯ�Ѵ�.
Direction anticlockwiseDirectionOf(Direction dir) {
    switch (dir.initial) {
        case 'E': return NORTH;
        case 'S': return EAST;
        case 'W': return SOUTH;
        case 'N': return WEST;
        default: return NONE;
    }
}

// ������ ���� ũ�� (���� ����)
int numRows;
// ������ ���� ũ�� (���� ����)
int numCols;
// �ֻ����� �̵��� �� �ִ� Ƚ��
int numTotalRolls;

// �Է¹��� ĭ���� �Է¹��� �������� �� ĭ �̵��� �� ������ ĭ�� ��ȯ�Ѵ�.
pair<int, int> nextSquareIn(Direction dir, pair<int, int> square) {
    return {square.row+dir.dRow, square.col+dir.dCol};
}

// �Է¹��� ĭ�� ��踦 ������� ���θ� ��ȯ�Ѵ�.
bool checkOBOf(pair<int, int> square) {
    return square.row<0 || square.row>=numRows || square.col<0 || square.col>=numCols;
}


// �ֻ��� �� ���� ��
int die[6] = {1, 2, 3, 4, 5, 6};
// �ֻ����� ��ġ
pair<int, int> dieSquare = {0, 0};
// �ֻ����� �̵� ����
Direction dieDirection = EAST;
// ���� ���� ���
int accumScore = 0;

int board[21][21];
int boardPoint[21][21];

// ���� ���� �Է¹��� ĭ�� �ִ� ���� ��ȯ�Ѵ�.
int boardNumberAt(pair<int, int> square) {
    return board[square.row][square.col];
}

// �ֻ����� ���� ���� �ش� ĭ�� �������� �� ���� �� �ִ� ������ ��ȯ�Ѵ�.
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
            if (checkOBOf(nextSquare)) //�̿��� ĭ�� ��踦 ����� ���
                continue;
            if (boardNumberAt(nextSquare)!=numberOnSquare) //�̿��� ĭ�� �ٸ� ���� ������ �ִ� ���
                continue;
            if (visitedSquares.find(nextSquare)!=visitedSquares.end()) //�̿��� ĭ�� �̹� �湮�� ���
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

// �ֻ����� ������.
void roll() {
    // �ֻ����� �� �� ������ ������ ĭ
    pair<int, int> dieNextSquare = nextSquareIn(dieDirection, dieSquare);
    if (checkOBOf(dieNextSquare)) { // �ش� ĭ�� ��踦 ����� ��� ������ �ݴ�� �Ͽ� �� ĭ ������.
        dieDirection = oppositeDirectionOf(dieDirection);
        dieNextSquare = nextSquareIn(dieDirection, dieSquare);
    }
    dieSquare = dieNextSquare;
    switch (dieDirection.initial) { //�ֻ����� ���� ���⿡ ���� �ֻ����� �� ������ �����Ų��.
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
    accumScore += pointAt(dieSquare); //������ ��ġ�� ������ ��´�.
    //������ ��ġ�� ���� ĭ�� ���� ��� ���迡 ���� �ֻ����� ������ �����Ѵ�.
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
