#include <stdio.h>
#include <vector>

using namespace std;


/**보드의 크기: 1행부터 boardSize행까지 boardSize 개의 행을 사용한다.*/
int boardSize;

/**적용할 움직임 횟수*/
int numSteps;


const int dRow[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dCol[8] = {2, 1, -1, -2, -2, -1, 1, 2};

/**
 *  dpArray
 *  dpArray[numSteps][row][col]: numSteps번 움직여서 (row, col)에 있을 확률
 */
double dpArray[51][51][51];

int main() {
    int initialRow, initialCol;
    scanf("%d %d %d %d", &boardSize, &initialRow, &initialCol, &numSteps);
    dpArray[0][initialRow][initialCol] = 1.0;
    for (int stepCount=1; stepCount<=numSteps; stepCount++) {
        for (int rowNum=1; rowNum<=boardSize; rowNum++) {
            for (int colNum=1; colNum<=boardSize; colNum++) {
                for (int dir=0; dir<8; dir++) {
                    int pRow = rowNum+dRow[dir];
                    int pCol = colNum+dCol[dir];
                    if (pRow<1 || pRow>boardSize || pCol<1 || pCol>boardSize)
                        continue;
                    dpArray[stepCount][rowNum][colNum] += dpArray[stepCount-1][pRow][pCol]/8.0; // (pRow, pCol)에 도달하는 경우 중 8분의 1 만이 (rowNum, colNum)으로 이동한다.
                } //dir loop (나이트가 움직일 수 있는 방향 루프)
            } //colNum loop
        } //rowNum loop
    } //stepCount loop

    double result = 0.0;
    for (int rowNum=1; rowNum<=boardSize; rowNum++) {
        for (int colNum=1; colNum<=boardSize; colNum++) {
            result += dpArray[numSteps][rowNum][colNum];
        }
    }

    printf("%.16f", result); // 정확도를 체크하는 문제여서 그런지 포맷 지정을 통해 소수점 이하 16 자리 까지 출력함
    return 0;
}
