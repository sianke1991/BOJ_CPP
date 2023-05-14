#include <bits/stdc++.h>

using namespace std;
double dpArray[100][100];
int main() {
    int numRows, numCols;
    cin >> numRows >> numCols;
    int board[numRows][numCols];
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            cin >> board[i][j];
        }
    }
    for (int j=0; j<numCols; j++) {
        if (board[0][j]==2) {
            dpArray[0][j] = 1;
            board[0][j] = 0; //���� �ִ� ��ġ�� ���� ����.
            break;
        }
    }
    for (int i=1; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            if (board[i][j]==0) { //�ش� ĭ�� ���� ���� ���
                dpArray[i][j] += dpArray[i-1][j];
                continue;
            }
            //�ش� ĭ�� ���� �ִ� ��� �ش� ĭ���� ���� �� �� ����.
            //�ش� ĭ���� ���� �� Ȯ���� �ش� ĭ�� �̿�ĭ���� �й����ش�.
            //�� �� ������ ���� �����Ƿ� ����ó���� ���ʿ�
            dpArray[i][j] = 0;
            const int PREVIOUS_ROW = i-1;
            const int CURRENT_ROW = i;
            const int LEFT_COLUMN = j-1;
            const int RIGHT_COLUMN = j+1;

            if (board[PREVIOUS_ROW][LEFT_COLUMN]!=1 && board[CURRENT_ROW][LEFT_COLUMN]!=1 && board[PREVIOUS_ROW][RIGHT_COLUMN]!=1 && board[CURRENT_ROW][RIGHT_COLUMN]!=1) {
                //�ش� ĭ�� �߽����� �� ������ ���� ���� ���-
                dpArray[CURRENT_ROW][LEFT_COLUMN] += dpArray[i-1][j]/2;
                dpArray[CURRENT_ROW][RIGHT_COLUMN] += dpArray[i-1][j]/2;
            } else if (board[PREVIOUS_ROW][LEFT_COLUMN]!=1 && board[CURRENT_ROW][LEFT_COLUMN]!=1) {
                //�ش� ĭ�� �߽����� ���ʿ��� ���� ���� ���-
                dpArray[CURRENT_ROW][LEFT_COLUMN] += dpArray[i-1][j];
                dpArray[CURRENT_ROW][RIGHT_COLUMN] = 0;
            } else if (board[PREVIOUS_ROW][RIGHT_COLUMN]!=1 && board[CURRENT_ROW][RIGHT_COLUMN]!=1) {
                //�ش� ĭ�� �߽����� �����ʿ��� ���� ���� ���-
                dpArray[CURRENT_ROW][LEFT_COLUMN] = 0;
                dpArray[CURRENT_ROW][RIGHT_COLUMN] += dpArray[i-1][j];
            } else {
                //�ش� ĭ�� �߽����� �� �� ��ο� ���� �ִ� ���-
                dpArray[CURRENT_ROW][LEFT_COLUMN] = 0;
                dpArray[CURRENT_ROW][RIGHT_COLUMN] = 0;
            }
        } //j loop (col loop)
    } //i loop (row loop)
    int optCol = -1, optProb = -1;
    for (int j=0; j<numCols; j++) {
        if (dpArray[numRows-1][j]>0 && dpArray[numRows-1][j]>optProb) {
            optProb = dpArray[numRows-1][j];
            optCol = j;
        }
    }
    cout << optCol;
    return 0;
}
