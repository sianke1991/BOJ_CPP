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

// ������ ũ��
int boardSize;

// �� ĭ�� �ִ� ���� ��
int sand[500][500];

// �� ĭ�� ����̵��� �����ߴ��� ����
bool visited[500][500];

// ���� ������ ���� ���� ��
int overflowingSand = 0;

pair<int, int> tornadoSquare = {0, 0};
Direction tornadoDirection = LEFT;

// �Է¹��� ĭ�� ���� ���� ������� ���θ� ��ȯ�Ѵ�.
bool checkOBOf(int row, int col) {
    return row<0 || row>=boardSize || col<0 || col>=boardSize;
}

// �Է¹��� ĭ�� ���� ���� ������� ���θ� ��ȯ�Ѵ�.
bool checkOBOf(pair<int, int> square) {
    return checkOBOf(square.ROW, square.COL);
}

pair<int, int> nextSquareIn(Direction direction, pair<int, int> currentSquare) {
    return {currentSquare.ROW+direction.dRow, currentSquare.COL+direction.dCol};
}

/**
 * ����̵��� ��ġ �� ������ �Է� �޾� �𷡰� Ƣ�� ĭ ����� ��ȯ�Ѵ�.
 * ��ȯ ���� Ű�� �𷡰� Ƣ�� ��(����: %) �̴�.
 * implNote alpha ĭ�� ��� Ű ���� 100�� ����Ѵ�.
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

// ����̵��� �� ĭ �̵��Ѵ�.
// ����̵��� �������� �����Ͽ� �� �̻� �̵��� �� ������ false�� ��ȯ�Ѵ�.
bool tornadoMove() {
    //printf("aa%d, %d\n", tornadoSquare.ROW, tornadoSquare.COL);
    // ����̵��� �������� �����ߴ��� ���θ� ����Ѵ�.
    if (tornadoSquare.ROW==0 && tornadoSquare.COL==0)
        return false;

    // ����̵��� ����̵� �������� �� ĭ �̵��Ѵ�.
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

    // ���� �̵��� ������ ����̵� ������ ����Ѵ�.
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
