#include <stdio.h>
#include <bits/stdc++.h>
#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define ROW first
#define COL second

using namespace std;

/**�� ���⿡ ���� �� ��ȭ*/
int dRow[] = {-1, 1, 0, 0};
/**�� ���⿡ ���� �� ��ȭ*/
int dCol[] = {0, 0, -1, 1};

/**
 * ������ ���� ���� (������ ���� ������ ���� ������ �����ϴ�.)
 * ���� �� �л��� ������ numRows*numRows�� �Ǿ� �Ѵ�.
 */
int numRows;

/**
 * �� �ڸ��� ���� �л� ��ȣ: ������ ���� 0�� ��� �ش� �ڸ��� ���� �������� ���� ���̴�.
 */
int classroom[20][20];

/**
 * �Է¹��� ĭ�� ������ �л� ��ȣ�� ��ȯ�Ѵ�.
 */
int studentAt(pair<int, int> square) {
    return classroom[square.ROW][square.COL];
}

/**
 * �� �л��� ���� �����ϴ� �л��� ��ȣ ����: favourites[1] �� 1�� �л��� �����ϴ� �л� ����
 */
set<int> favourites[402];

/**
 * �Է¹��� ĭ���� �Է¹��� �������� �� ĭ �̵����� �� ������ ĭ�� ��ȯ�Ѵ�.
 */
pair<int, int> nextSquareOf(int rowNum, int colNum, int direction) {
    return {rowNum+dRow[direction], colNum+dCol[direction]};
}

/**
 * �Է¹��� ĭ�� ��踦 ������� ���θ� ��ȯ�Ѵ�.
 */
bool checkOutOfBounds(pair<int, int> currentSquare) {
    return currentSquare.ROW<0 || currentSquare.COL<0 ||
            currentSquare.ROW>=numRows || currentSquare.COL>=numRows;
}

/**
 * �Է¹��� ĭ �������� �̿��� ĭ ����� ��ȯ�Ѵ�.
 */
vector<pair<int, int>> nextSquaresOf(int rowNum, int colNum) {
    vector<pair<int, int>> result;
    for (int direction=TOP; direction<=RIGHT; direction++) {
        pair<int, int> nextSquare = nextSquareOf(rowNum, colNum, direction);
        if (checkOutOfBounds(nextSquare))
            continue;
        result.push_back(nextSquare);
    } //direction loop
    return result;
}

/**
 * �ش� �л��� �ش� �ڸ��� �ɾ��� �� �켱���� ������ ����Ѵ�.
 * �켱������ [������ �����ϴ� �л� ��]�� ���� ����,
 * [������ �� �ڸ� ��]�� ���� ���� ��������.
 */
int priorityOf(int studentNumber, int rowNum, int colNum) {
    if (classroom[rowNum][colNum])
        return -2;
    vector<pair<int, int>> nextSquares = nextSquaresOf(rowNum, colNum);
    //������ �� �ڸ� ���� �� ������ �����ϴ� �л� ��
    int numVacants = 0, numFavourites = 0;
    for (pair<int, int> nextSquare:nextSquares) {
        if (favourites[studentNumber].find(studentAt(nextSquare))!=favourites[studentNumber].end())
            numFavourites++;
        else if (studentAt(nextSquare)==0)
            numVacants++;
    } //nextSquare loop
    return numFavourites<<3 | numVacants;
}

void putStudent(int studentNumber) {
    int optPriority = -1;
    int optRow = -1;
    int optCol = -1;
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numRows; col++) {
            int currentPriority = priorityOf(studentNumber, row, col);
            if (currentPriority>optPriority) {
                optRow = row; optCol = col;
                optPriority = currentPriority;
            }
        }
    }
    classroom[optRow][optCol] = studentNumber;
}

int satisfactionOf(int rowNum, int colNum) {
    vector<pair<int, int>> nextSquares = nextSquaresOf(rowNum, colNum);
    int studentNumber = classroom[rowNum][colNum];
    int numFavourites = 0;
    for (pair<int, int> nextSquare:nextSquares) {
        if (favourites[studentNumber].find(studentAt(nextSquare))!=favourites[studentNumber].end())
            numFavourites++;
    }
    switch (numFavourites) {
        case 4: return 1000;
        case 3: return 100;
        case 2: return 10;
        case 1: return 1;
        default: return 0;
    }
}

int sumSatisfaction() {
    int result = 0;
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numRows; col++) {
            result += satisfactionOf(row, col);
        } //col loop
    } //row loop
    return result;
}

int main() {
    scanf("%d", &numRows);
    vector<int> students;
    for (int i=0; i<numRows*numRows; i++) {
        int studentNumber;
        scanf("%d", &studentNumber);
        students.push_back(studentNumber);
        int f0, f1, f2, f3;
        scanf("%d %d %d %d", &f0, &f1, &f2, &f3);
        favourites[studentNumber].insert(f0);
        favourites[studentNumber].insert(f1);
        favourites[studentNumber].insert(f2);
        favourites[studentNumber].insert(f3);
    }

    for (int student:students) {
        putStudent(student);
    }

    printf("%d", sumSatisfaction());
    return 0;
}
