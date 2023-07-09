#include <bits/stdc++.h>

using namespace std;
const int INF = 100000;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int main() {
    int numRows, numCols;
    scanf("%d %d", &numCols, &numRows); //�������� ���� ������ ���� �Է��Ѵ�....
    char board[numRows][numCols+1]; //���ڿ��� ������ "���ڿ��� �������� �˷��ִ�" \0 ���ڰ� ��ġ�Ѵ�.
    for (int i=0; i<numRows; i++) {
        scanf("%s", board[i]);
    }

    //������̺� �ʱ�ȭ
    int priceTable[numRows][numCols]; //������̺�: [0][0]���� [row][col]�� �����ϴµ� �ʿ��� ��� (�ı��ؾ� �� ���� ����)
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            priceTable[i][j] = INF;
        }
    }
    priceTable[0][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; //{���, ���ȣ, ����ȣ}�� ������ Ʃ���� ����Ѵ�.
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
            int newPrice = board[newRow][newCol]-'0'+currentPrice; //���� �ִ� ĭ�� �����ؾ� �ϴ� ��� �ٷ� ���� ĭ�� �����ϴ� ��뺸�� 1 ū ������� ������ �� �ִ�.
                                                                    //�ݴ�� ���� ���� ĭ�� �����ؾ� �ϴ� ��� �ٷ� ���� ĭ�� �����ϴ� ��� �� ������� ������ �� �ִ�.
            if (priceTable[newRow][newCol]>newPrice) {
                priceTable[newRow][newCol] = newPrice;
                pq.push({newPrice, newRow, newCol});
            }
        } //directionIndex loop
    } //while loop

    printf("%d", priceTable[numRows-1][numCols-1]);
    return 0;
}
