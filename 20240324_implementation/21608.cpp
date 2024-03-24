#include <stdio.h>
#include <bits/stdc++.h>
#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define ROW first
#define COL second

using namespace std;

/**각 방향에 따른 행 변화*/
int dRow[] = {-1, 1, 0, 0};
/**각 방향에 따른 열 변화*/
int dCol[] = {0, 0, -1, 1};

/**
 * 교실의 행의 개수 (교실의 열의 개수도 행의 개수와 동일하다.)
 * 교실 내 학생의 개수는 numRows*numRows가 되야 한다.
 */
int numRows;

/**
 * 각 자리에 앉은 학생 번호: 원소의 값이 0인 경우 해당 자리는 아직 배정되지 않은 것이다.
 */
int classroom[20][20];

/**
 * 입력받은 칸에 배정된 학생 번호를 반환한다.
 */
int studentAt(pair<int, int> square) {
    return classroom[square.ROW][square.COL];
}

/**
 * 각 학생에 대해 좋아하는 학생의 번호 정보: favourites[1] 은 1번 학생이 좋아하는 학생 집합
 */
set<int> favourites[402];

/**
 * 입력받은 칸에서 입력받은 방향으로 한 칸 이동했을 때 나오는 칸을 반환한다.
 */
pair<int, int> nextSquareOf(int rowNum, int colNum, int direction) {
    return {rowNum+dRow[direction], colNum+dCol[direction]};
}

/**
 * 입력받은 칸이 경계를 벗어나는지 여부를 반환한다.
 */
bool checkOutOfBounds(pair<int, int> currentSquare) {
    return currentSquare.ROW<0 || currentSquare.COL<0 ||
            currentSquare.ROW>=numRows || currentSquare.COL>=numRows;
}

/**
 * 입력받은 칸 기준으로 이웃한 칸 목록을 반환한다.
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
 * 해당 학생이 해당 자리에 앉았을 때 우선순위 정도를 계산한다.
 * 우선순위는 [인접한 좋아하는 학생 수]가 많을 수록,
 * [인접한 빈 자리 수]가 많을 수록 높아진다.
 */
int priorityOf(int studentNumber, int rowNum, int colNum) {
    if (classroom[rowNum][colNum])
        return -2;
    vector<pair<int, int>> nextSquares = nextSquaresOf(rowNum, colNum);
    //인접한 빈 자리 개수 및 인접한 좋아하는 학생 수
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
