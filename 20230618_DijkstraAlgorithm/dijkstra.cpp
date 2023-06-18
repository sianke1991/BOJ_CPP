#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000;

//���ͽ�Ʈ�� �ִܰ�� �˰��� (2)
//�켱���� ť�� ����ϴ� ��� �ּ� ��� ���̺��� ���� ���θ� ������ �������� �ʴ´�.
//�켱���� ť�� {���, ���} ���� ���� ��, �켱���� ť���� {���, ���} ���� �� ���� �ּ� ��� ���̺�� ���Ͽ�
//����ġ ���� ���� ���� ��� �ش� ���� ������ ó�� ���� ��������.

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}



int main() {
    vector<pair<int, int>> adjList[7]; //��������Ʈ
    adjList[1].push_back({3, 2}); //{���, �������}
    adjList[1].push_back({2, 3});
    adjList[1].push_back({5, 4});
    adjList[2].push_back({2, 3});
    adjList[2].push_back({8, 5});
    adjList[3].push_back({2, 4});
    adjList[4].push_back({6, 5});
    adjList[5].push_back({1, 6});

    int startingNode = 1;
    int priceTable[7];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //�ּ� ��� ���̺��� (���� ��带 �����ϰ�) ���Ѵ�� �ʱ�ȭ�Ѵ�.
    for (int i=0; i<7; i++) {
        priceTable[i] = INF;
    }
    priceTable[startingNode] = 0;

    //���� ��忡�� ������� ���� ������ �켱���� ť�� ����ִ� ������ �˰����� �����Ѵ�.
    for (pair<int, int> nxtNodePair:adjList[startingNode]) {
        priceTable[nxtNodePair.second] = nxtNodePair.first;
        pq.push(nxtNodePair);
    }

    //�켱���� ť�� �� �� ���� �ݺ��� �����Ѵ�.
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentPrice = pq.top().first;
        pq.pop();

        if (currentPrice!=priceTable[currentNode]) {
            //�켱���� ť���� �̾Ƴ� ��� ������ �ּ� ��� ���̺� ����ִ� ��� ������ �ٸ� ���
            //�켱���� ť���� �̾Ƴ� ��� ������ ������ ó�� ���� ��������. (�ش� ��忡 �����ϴµ� �� ȿ������ ����� �̸� �߰������Ƿ� �� ȿ������ ����� ���õȴ�.)
            continue;
        }

        for (pair<int, int> nxtNodePair:adjList[currentNode]) {
            int nxtNode = nxtNodePair.second;
            int nxtPrice = priceTable[currentNode] + nxtNodePair.first;
            if (priceTable[nxtNode]>nxtPrice) { //nxtNode�� ���µ� ���ݱ��� �߰��� ������� �� ȿ������ ����� ã�� ���-
                priceTable[nxtNode] = nxtPrice;
                pq.push({nxtPrice, nxtNode});
            }
        } //nxtNodePair loop
    } //while loop

    for (int price:priceTable) {
        cout << price << ' ';
    }

    return 0;
}
