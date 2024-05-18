#include <bits/stdc++.h>
#include <stdio.h>
#define INFINITY 100000000
#define STARTING_NODE 1

using namespace std;

// 비용 테이블. priceTable[x] 는 1번 노드에서 x 번 노드까지 가는데 필요한 최소의 비용
int priceTable[50001];
// 인접 리스트: adjList[x]는 x 노드에서 뻗어 나가는 간선 정보. 각 간선은 {비용, 도착 노드}로 저장한다.
vector<pair<int, int>> adjList[50001];
// 헛간 개수 (그래프 내 노드 개수): 출발 노드는 1번, 도착 노드는 numNodes 번이다.
int numNodes;
// 소 길의 개수 (그래프 내 간선 개수)
int numEdges;

// 초기화 함수
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
    } // 간선 입력
    init();


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //  {비용, 도착 노드}로 구성된 pair를 사용
    pq.push({0, STARTING_NODE});
    while (!pq.empty()) {
        int currentPrice = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentPrice!=priceTable[currentNode]) continue;

        for (pair<int, int> p:adjList[currentNode]) {
            int nextPrice = currentPrice + p.first;
            int nextNode = p.second;

            if (priceTable[nextNode]>nextPrice) { // nextNode에 도달하는데 더 효율적인 방법을 찾은 경우-
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
