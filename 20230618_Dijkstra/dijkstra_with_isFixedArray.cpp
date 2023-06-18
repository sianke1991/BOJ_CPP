#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000;

//다익스트라 최단경로 알고리즘
//한 출발 노드에서 각 노드를 가는데 필요한 최소 비용을 계산한다.
//음의 간선이 있으면 적용 불가

//매 단계마다 최소 비용 테이블의 값 중 하나를 고정시키는데, 테이블의 값 중 최소치를 고정하게 된다.

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int main() {
    vector<pair<int, int>> adjList[7]; //인접리스트
    adjList[1].push_back({3, 2}); //{비용, 도착노드}
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

    //최소 비용 테이블은 (시작 노드를 제외하고) 무한대로 초기화한다.
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
            //(s -> n1) 의 비용은 priceTables[n0] + (n0 -> n1) 의 비용과 같다.
            pq.push({priceTables[currentNode.second]+adjNode.first, adjNode.second});
        }
    } //while loop

    for (int i=1; i<=6; i++) {
        cout << priceTables[i] << ' ';
    }

    return 0;
}
