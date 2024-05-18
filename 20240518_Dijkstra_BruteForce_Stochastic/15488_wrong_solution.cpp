#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

/**������ ũ��: 1����� boardSize����� boardSize ���� ���� ����Ѵ�.*/
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
 * ����Ʈ�� ������ �� �ִ� ĭ ����� ��ȯ�Ѵ�.
 * ���� ������ ������ ĭ�� �����Ѵ�.
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
 * �� ���� ���� ����� ��ȯ�Ѵ�.
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
 *  �� ����� ���� ����� ��ȯ�Ѵ�,
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
 * dpArray[square][steps]: square���� ����Ͽ� steps �� �̵��Ͽ� ������ �� �ִ� ĭ ���(Ư�� ĭ�� ������ ����� ���� ���� ��� �� ������ ����Ѵ�.)
 */
unordered_map<int, double> dpArray[5151][51];

/**
 * dpArrayFixed
 * dpArrayFixed[a][b]: dpArray[a][b]�� ���� ���� �ִ��� ���θ� ����Ѵ�. (�ʱⰪ�� ���� false)
 */
bool dpArrayFixed[5151][51];

/**
 * ���ĭ�� ������ Ƚ���� �Է¹޾� ������ �� �ִ� ĭ ����� ��ȯ�Ѵ�.
 */
unordered_map<int, double> getDpArrayOf(int square, int steps) {
    //�ش� ���� �̹� ���� ����� �� ���� ���� �״�� ����Ѵ�. (�޸������̼�)
    if (dpArrayFixed[square][steps])
        return dpArray[square][steps];

    //���̽� ���̽�
    if (steps==1) {
        dpArray[square][steps] = squaresKnightCanMoveFrom(square);
        dpArrayFixed[square][steps] = true;
        return dpArray[square][steps];
    }

    //���̽� ���̽�
    if (steps==0) {
        unordered_map<int, double> m;
        m[square] = 1.0;
        dpArray[square][steps] = m;
        dpArrayFixed[square][steps] = true;
        return dpArray[square][steps];
    }

    //��ȭ��
    for (auto entry:getDpArrayOf(square, 1)) { //entry.first�� square���� ����Ͽ� ����Ʈ�� �� �� �ִ� ĭ�� �ȴ�.
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
    } // ����Ʈ�� ���� ���� ���� ����� ���� ����Ѵ�.
    result /= pow(8, numSteps); // ��ü ����� ���� [8�� numSteps ����]���� ������ Ȯ���� ����Ѵ�.
    printf("%.12f", result);
    return 0;
}
