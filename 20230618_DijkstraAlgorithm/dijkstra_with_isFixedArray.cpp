#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000;

//���ͽ�Ʈ�� �ִܰ�� �˰���
//�� ��� ��忡�� �� ��带 ���µ� �ʿ��� �ּ� ����� ����Ѵ�.
//���� ������ ������ ���� �Ұ�

//�� �ܰ踶�� �ּ� ��� ���̺��� �� �� �ϳ��� ������Ű�µ�, ���̺��� �� �� �ּ�ġ�� �����ϰ� �ȴ�.

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
    int priceTables[7];
    bool isFixed[7];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //�ּ� ��� ���̺��� (���� ��带 �����ϰ�) ���Ѵ�� �ʱ�ȭ�Ѵ�.
    for (int i=0; i<7; i++) {
        priceTables[i] = INF;
        isFixed[i] = false;
    }
    priceTables[startingNode] = 0;
    isFixed[startingNode] = true;
    for (pair<int, int> adjNode:adjList[startingNode]) {
        pq.push(adjNode);
    }

    while (!pq.empty()) {
        pair<int, int> currentNode = pq.top();
        pq.pop();
        if (isFixed[currentNode.second]) continue;
        priceTables[currentNode.second] = Min(priceTables[currentNode.second], currentNode.first);
        isFixed[currentNode.second] = true;
        for (pair<int, int> adjNode:adjList[currentNode.second]) {
            if (isFixed[adjNode.second]) continue;
            //(s -> n1) �� ����� priceTables[n0] + (n0 -> n1) �� ���� ����.
            pq.push({priceTables[currentNode.second]+adjNode.first, adjNode.second});
        }
    } //while loop

    for (int i=1; i<=6; i++) {
        cout << priceTables[i] << ' ';
    }

    return 0;
}
