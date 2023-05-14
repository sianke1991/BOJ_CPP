#include <bits/stdc++.h>

using namespace std;
long long dpArray[100][100];
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
            break;
        }
    }
    for (int i=1; i<numRows; i++) {
        //j==0 (�� ���� ��)
        {
            int j=0;
            if (board[i-1][j]==1) { //�ٷ� �� ĭ�� ���� ���� ���-
                dpArray[i][j] = 0;
            } else if (board[i][j]==1) { //�ش� ĭ�� ���� ���� ���-
                dpArray[i][j] = 0;
            } else if (board[i][j+1]==1) { //�ٷ� ������ ĭ�� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j]+dpArray[i-1][j+1];
            } else { //�̿�ĭ�� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j];
            }
        }
        for (int j=1; j<numCols-1; j++) {
            if (board[i-1][j]==1) { //�ٷ� �� ĭ�� ���� ���� ���-
                dpArray[i][j] = 0;
            } else if (board[i][j]==1) { //�ش� ĭ�� ���� ���� ���-
                dpArray[i][j] = 0;
            } else if (board[i][j-1]==1 && board[i][j+1]!=1) { //�ٷ� ���� ĭ���� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j-1]+dpArray[i-1][j];
            } else if (board[i][j-1]!=1 && board[i][j+1]==1) { //�ٷ� ������ ĭ���� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j]+dpArray[i-1][j+1];
            } else if (board[i][j-1]==1 && board[i][j+1]==1) { //���ʿ� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j-1]+dpArray[i-1][j]+dpArray[i-1][j+1];
            } else { //�̿�ĭ�� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j];
            }
        }
        //j==numCols-1 (�� ������ ��)
        {
            int j=numCols-1;
            if (board[i-1][j]==1) { //�ٷ� �� ĭ�� ���� ���� ���-
                dpArray[i][j] = 0;
            } else if (board[i][j]==1) { //�ش� ĭ�� ���� ���� ���-
                dpArray[i][j] = 0;
            } else if (board[i][j-1]==1) { //�ٷ� ���� ĭ�� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j-1]+dpArray[i-1][j];
            } else { //�̿�ĭ�� ���� ���� ���-
                dpArray[i][j] = dpArray[i-1][j];
            }
        }
    }
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
