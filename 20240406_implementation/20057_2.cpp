#include <bits/stdc++.h>
#include <stdio.h>
#define ROW first
#define COL second

using namespace std;

struct Direction {
    char abbreviation;
    int dRow;
    int dCol;
};

Direction NONE = {'n', 0, 0};
Direction LEFT = {'l', 0, -1};
Direction BOTTOM = {'b', 1, 0};
Direction RIGHT = {'r', 0, 1};
Direction TOP = {'t', -1, 0};

Direction counterClockwiseOf(Direction dir) {
    switch (dir.abbreviation) {
        case 'l': return BOTTOM;
        case 'b': return RIGHT;
        case 'r': return TOP;
        case 't': return LEFT;
        default: return NONE;
    }
}

Direction clockwiseOf(Direction dir) {
    switch (dir.abbreviation) {
        case 'l': return TOP;
        case 'b': return LEFT;
        case 'r': return BOTTOM;
        case 't': return RIGHT;
        default: return NONE;
    }
}

Direction reverseOf(Direction dir) {
    switch (dir.abbreviation) {
        case 'l': return RIGHT;
        case 'b': return TOP;
        case 'r': return LEFT;
        case 't': return BOTTOM;
        default: return NONE;
    }
}

// 보드의 크기
int boardSize;

// 각 칸에 있는 모래의 양
int sand[500][500];

// 각 칸에 토네이도가 도달했는지 여부
bool visited[500][500];

// 보드 밖으로 나간 모래의 양
int overflowingSand = 0;

pair<int, int> tornadoSquare = {0, 0};
Direction tornadoDirection = LEFT;

// 입력받은 칸이 보드 밖을 벗어나는지 여부를 반환한다.
bool checkOBOf(int row, int col) {
    return row<0 || row>=boardSize || col<0 || col>=boardSize;
}

// 입력받은 칸이 보드 밖을 벗어나는지 여부를 반환한다.
bool checkOBOf(pair<int, int> square) {
    return checkOBOf(square.ROW, square.COL);
}

pair<int, int> nextSquareIn(Direction direction, pair<int, int> currentSquare) {
    return {currentSquare.ROW+direction.dRow, currentSquare.COL+direction.dCol};
}

/**
 * 토네이도의 위치 및 방향을 입력 받아 모래가 튀는 칸 목록을 반환한다.
 * 반환 값의 키는 모래가 튀는 양(단위: %) 이다.
 * implNote alpha 칸의 경우 키 값은 100을 사용한다.
 */
multimap<long long, pair<int, int>> splashAreas(pair<int, int> tornadoSquare, Direction tornadoDirection) {
    multimap<long long, pair<int, int>> result;
    Direction counterClockwiseDirection = counterClockwiseOf(tornadoDirection);
    Direction clockwiseDirection = clockwiseOf(tornadoDirection);
    Direction reverseDirection = reverseOf(tornadoDirection);

    pair<int, int> seven_square_a =  nextSquareIn(counterClockwiseDirection, tornadoSquare);
    result.insert({7LL, seven_square_a});

    pair<int, int> seven_square_b = nextSquareIn(clockwiseDirection, tornadoSquare);
    result.insert({7LL, seven_square_b});

    pair<int, int> two_square_a = nextSquareIn(counterClockwiseDirection, seven_square_a);
    result.insert({2LL, two_square_a});

    pair<int, int> two_square_b = nextSquareIn(clockwiseDirection, seven_square_b);
    result.insert({2LL, two_square_b});

    pair<int, int> one_square_a = nextSquareIn(reverseDirection, seven_square_a);
    result.insert({1LL, one_square_a});

    pair<int, int> one_square_b = nextSquareIn(reverseDirection, seven_square_b);
    result.insert({1LL, one_square_b});

    pair<int, int> ten_square_a = nextSquareIn(tornadoDirection, seven_square_a);
    result.insert({10LL, ten_square_a});

    pair<int, int> ten_square_b = nextSquareIn(tornadoDirection, seven_square_b);
    result.insert({10LL, ten_square_b});

    pair<int, int> alpha_square = nextSquareIn(tornadoDirection, tornadoSquare);
    result.insert({100LL, alpha_square});

    pair<int, int> five_square = nextSquareIn(tornadoDirection, alpha_square);
    result.insert({5LL, five_square});

    return result;
}

// 토네이도를 한 칸 이동한다.
// 토네이도가 목적지에 도달하여 더 이상 이동할 수 없으면 false를 반환한다.
bool tornadoMove() {
    //printf("aa%d, %d\n", tornadoSquare.ROW, tornadoSquare.COL);
    // 토네이도가 목적지에 도달했는지 여부를 계산한다.
    if (tornadoSquare.ROW==0 && tornadoSquare.COL==0)
        return false;

    // 토네이도를 토네이도 방향으로 한 칸 이동한다.
    tornadoSquare = nextSquareIn(tornadoDirection, tornadoSquare);
    //printf("ab%d, %d\n", tornadoSquare.ROW, tornadoSquare.COL);
    visited[tornadoSquare.ROW][tornadoSquare.COL] = true;

    if (sand[tornadoSquare.ROW][tornadoSquare.COL]) {
        int sandAmountSum = 0;
        long long sandAmount = 0;

        for (pair<long long, pair<int, int>> entry:splashAreas(tornadoSquare, tornadoDirection)) {
            //printf("%d %d, ", entry.second.ROW, entry.second.COL);
            if (entry.first==100LL) {
                sandAmount = sand[tornadoSquare.ROW][tornadoSquare.COL]-sandAmountSum;
            } else {
                sandAmount = sand[tornadoSquare.ROW][tornadoSquare.COL]*entry.first/100;
            }

            if (checkOBOf(entry.second)) {
                overflowingSand+=sandAmount;
            } else {
                sand[entry.second.ROW][entry.second.COL]+=sandAmount;
            }
            sandAmountSum+=sandAmount;
        } //splashArea loop
    }

    // 다음 이동에 적용할 토네이도 방향을 계산한다.
    //printf("ac\n");
    Direction counterClockwiseDirection = counterClockwiseOf(tornadoDirection);
    pair<int, int> tmpSquare = nextSquareIn(counterClockwiseDirection, tornadoSquare);
    if (!visited[tmpSquare.ROW][tmpSquare.COL])
        tornadoDirection = counterClockwiseDirection;

    return true;
}

int main() {
    scanf("%d", &boardSize);
    tornadoSquare = {boardSize/2, boardSize/2};
    visited[tornadoSquare.ROW][tornadoSquare.COL] = true;

    for (int row=0; row<boardSize; row++) {
        for (int col=0; col<boardSize; col++) {
            scanf("%d", &sand[row][col]);
        }
    }

    while (tornadoMove());

    printf("%d", overflowingSand);
    return 0;
}
