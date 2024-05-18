#include <stdio.h>
#include <vector>

using namespace std;


/**������ ũ��: 1����� boardSize����� boardSize ���� ���� ����Ѵ�.*/
int boardSize;

/**������ ������ Ƚ��*/
int numSteps;


const int dRow[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dCol[8] = {2, 1, -1, -2, -2, -1, 1, 2};

/**
 *  dpArray
 *  dpArray[numSteps][row][col]: numSteps�� �������� (row, col)�� ���� Ȯ��
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
                    dpArray[stepCount][rowNum][colNum] += dpArray[stepCount-1][pRow][pCol]/8.0; // (pRow, pCol)�� �����ϴ� ��� �� 8���� 1 ���� (rowNum, colNum)���� �̵��Ѵ�.
                } //dir loop (����Ʈ�� ������ �� �ִ� ���� ����)
            } //colNum loop
        } //rowNum loop
    } //stepCount loop

    double result = 0.0;
    for (int rowNum=1; rowNum<=boardSize; rowNum++) {
        for (int colNum=1; colNum<=boardSize; colNum++) {
            result += dpArray[numSteps][rowNum][colNum];
        }
    }

    printf("%.16f", result); // ��Ȯ���� üũ�ϴ� �������� �׷��� ���� ������ ���� �Ҽ��� ���� 16 �ڸ� ���� �����
    return 0;
}
