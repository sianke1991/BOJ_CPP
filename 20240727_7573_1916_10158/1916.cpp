#include <bits/stdc++.h>
#define INF 268435455

using namespace std;

//adjList[i]:= i�� ���ÿ��� ������� ���� ��� {���, ���� ����}
vector<pair<int, int>> adjList[1001];
//costTable[i]:= ��� ���ÿ��� i�� ���ÿ� �����ϴµ� �ʿ��� �ּ� ���
int costTable[1001];

int main() {
    //������ ����
    int N;
    //������ ����
    int M;

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        adjList[from].push_back({cost, to});
    }

    //��� ����, ���� ����
    int start, finish;
    scanf("%d %d", &start, &finish);

    for (int i=0; i<1001; i++) costTable[i] = INF;
    costTable[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();
        //�켱���� ť���� ���� �� ���� �� ȿ������ ��츦 ���� ���-
        if (costTable[currentNode]<currentCost)
            continue;
        for (pair<int, int> p:adjList[currentNode]) {
            int nextNode = p.second;
            int nextCost = currentCost+p.first;
            //�̹��� ���� ��κ��� �� ȿ������ ��θ� �̹� ���� ���-
            if (costTable[nextNode]<=nextCost)
                continue;
            pq.push({nextCost, nextNode});
            costTable[nextNode] = nextCost;
        } //p loop
    } //while loop

    printf("%d", costTable[finish]);
    return 0;
}
