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
        //j==0 (맨 왼쪽 열)
        {
            int j=0;
            if (board[i-1][j]==1) { //바로 윗 칸에 못이 있을 경우-
                dpArray[i][j] = 0;
            } else if (board[i][j]==1) { //해당 칸에 못이 있을 경우-
                dpArray[i][j] = 0;
            } else if (board[i][j+1]==1) { //바로 오른쪽 칸에 못이 있을 경우-
                dpArray[i][j] = dpArray[i-1][j]+dpArray[i-1][j+1];
            } else { //이웃칸에 못이 없을 경우-
                dpArray[i][j] = dpArray[i-1][j];
            }
        }
        for (int j=1; j<numCols-1; j++) {
            if (board[i-1][j]==1) { //바로 윗 칸에 못이 있을 경우-
                dpArray[i][j] = 0;
            } else if (board[i][j]==1) { //해당 칸에 못이 있을 경우-
                dpArray[i][j] = 0;
            } else if (board[i][j-1]==1 && board[i][j+1]!=1) { //바로 왼쪽 칸에만 못이 있을 경우-
                dpArray[i][j] = dpArray[i-1][j-1]+dpArray[i-1][j];
            } else if (board[i][j-1]!=1 && board[i][j+1]==1) { //바로 오른쪽 칸에만 못이 있을 경우-
                dpArray[i][j] = dpArray[i-1][j]+dpArray[i-1][j+1];
            } else if (board[i][j-1]==1 && board[i][j+1]==1) { //양쪽에 못이 있을 경우-
                dpArray[i][j] = dpArray[i-1][j-1]+dpArray[i-1][j]+dpArray[i-1][j+1];
            } else { //이웃칸에 못이 없을 경우-
                dpArray[i][j] = dpArray[i-1][j];
            }
        }
        //j==numCols-1 (맨 오른쪽 열)
        {
            int j=numCols-1;
            if (board[i-1][j]==1) { //바로 윗 칸에 못이 있을 경우-
                dpArray[i][j] = 0;
            } else if (board[i][j]==1) { //해당 칸에 못이 있을 경우-
                dpArray[i][j] = 0;
            } else if (board[i][j-1]==1) { //바로 왼쪽 칸에 못이 있을 경우-
                dpArray[i][j] = dpArray[i-1][j-1]+dpArray[i-1][j];
            } else { //이웃칸에 못이 없을 경우-
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
