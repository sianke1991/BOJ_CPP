#include <bits/stdc++.h>
#include <stdio.h>
#define INFINITY 100000000
#define STARTING_NODE 1

using namespace std;

// ��� ���̺�. priceTable[x] �� 1�� ��忡�� x �� ������ ���µ� �ʿ��� �ּ��� ���
int priceTable[50001];
// ���� ����Ʈ: adjList[x]�� x ��忡�� ���� ������ ���� ����. �� ������ {���, ���� ���}�� �����Ѵ�.
vector<pair<int, int>> adjList[50001];
// �갣 ���� (�׷��� �� ��� ����): ��� ���� 1��, ���� ���� numNodes ���̴�.
int numNodes;
// �� ���� ���� (�׷��� �� ���� ����)
int numEdges;

// �ʱ�ȭ �Լ�
void init() {
    for (int i=2; i<=numNodes; i++)
        priceTable[i] = INFINITY;

}

int main() {
    scanf("%d %d", &numNodes, &numEdges);
    for (int i=0; i<numEdges; i++) {
        int from, to, price;
        scanf("%d %d %d", &from, &to, &price);
        adjList[from].push_back({price, to});
        adjList[to].push_back({price, from});
    } // ���� �Է�
    init();


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //  {���, ���� ���}�� ������ pair�� ���
    pq.push({0, STARTING_NODE});
    while (!pq.empty()) {
        int currentPrice = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentPrice!=priceTable[currentNode]) continue;

        for (pair<int, int> p:adjList[currentNode]) {
            int nextPrice = currentPrice + p.first;
            int nextNode = p.second;

            if (priceTable[nextNode]>nextPrice) { // nextNode�� �����ϴµ� �� ȿ������ ����� ã�� ���-
                priceTable[nextNode] = nextPrice;
                pq.push({nextPrice, nextNode});
            }
        } //p loop
    } //while loop

    printf("%d\n", priceTable[numNodes]);

    /*
    for (int i=1; i<=numNodes; i++) {
        printf("target: %d, price: %d\n", i, priceTable[i]);
    }
    */
    return 0;
}
