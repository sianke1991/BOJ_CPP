#include <bits/stdc++.h>

using namespace std;
const int INF = 100000;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int main() {
    int numRows, numCols;
    scanf("%d %d", &numCols, &numRows); //문제에서 열의 개수를 먼저 입력한다....
    char board[numRows][numCols+1]; //문자열의 끝에는 "문자열이 끝났음을 알려주는" \0 문자가 위치한다.
    for (int i=0; i<numRows; i++) {
        scanf("%s", board[i]);
    }

    //비용테이블 초기화
    int priceTable[numRows][numCols]; //비용테이블: [0][0]에서 [row][col]에 도달하는데 필요한 비용 (파괴해야 할 벽의 개수)
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            priceTable[i][j] = INF;
        }
    }
    priceTable[0][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; //{비용, 행번호, 열번호}로 구성된 튜플을 사용한다.
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        int currentPrice = get<0>(pq.top());
        int currentRow = get<1>(pq.top());
        int currentCol = get<2>(pq.top());
        pq.pop();

        if (priceTable[currentRow][currentCol]!=currentPrice) continue;
        for (int directionIndex=0; directionIndex<4; directionIndex++) {
            int newRow = dRow[directionIndex]+currentRow;
            int newCol = dCol[directionIndex]+currentCol;
            if (newRow<0 || newRow>=numRows) continue; //out of bounds
            if (newCol<0 || newCol>=numCols) continue; //out of bounds
            int newPrice = board[newRow][newCol]-'0'+currentPrice; //벽이 있는 칸에 도달해야 하는 경우 바로 직전 칸에 도달하는 비용보다 1 큰 비용으로 도달할 수 있다.
                                                                    //반대로 벽이 없는 칸에 도달해야 하는 경우 바로 직전 칸에 도달하는 비용 그 비용으로 도달할 수 있다.
            if (priceTable[newRow][newCol]>newPrice) {
                priceTable[newRow][newCol] = newPrice;
                pq.push({newPrice, newRow, newCol});
            }
        } //directionIndex loop
    } //while loop

    printf("%d", priceTable[numRows-1][numCols-1]);
    return 0;
}
