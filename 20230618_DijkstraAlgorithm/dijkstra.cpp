#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000;

//다익스트라 최단경로 알고리즘 (2)
//우선순위 큐를 사용하는 경우 최소 비용 테이블의 고정 여부를 별도로 관리하지 않는다.
//우선순위 큐에 {비용, 노드} 쌍을 넣을 때, 우선순위 큐에서 {비용, 노드} 쌍을 빼 낼때 최소 비용 테이블과 비교하여
//적절치 못한 쌍이 나올 경우 해당 쌍은 별도의 처리 없이 버려진다.

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
    int priceTable[7];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //최소 비용 테이블은 (시작 노드를 제외하고) 무한대로 초기화한다.
    for (int i=0; i<7; i++) {
        priceTable[i] = INF;
    }
    priceTable[startingNode] = 0;

    //시작 노드에서 뻗어나가는 간선 정보를 우선순위 큐에 집어넣는 것으로 알고리즘을 시작한다.
    for (pair<int, int> nxtNodePair:adjList[startingNode]) {
        priceTable[nxtNodePair.second] = nxtNodePair.first;
        pq.push(nxtNodePair);
    }

    //우선순위 큐가 빌 때 까지 반복을 수행한다.
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentPrice = pq.top().first;
        pq.pop();

        if (currentPrice!=priceTable[currentNode]) {
            //우선순위 큐에서 뽑아낸 비용 정보가 최소 비용 테이블에 들어있는 비용 정보와 다를 경우
            //우선순위 큐에서 뽑아낸 비용 정보는 별도의 처리 없이 버려진다. (해당 노드에 도착하는데 더 효율적인 방법을 미리 발견했으므로 덜 효율적인 방법은 무시된다.)
            continue;
        }

        for (pair<int, int> nxtNodePair:adjList[currentNode]) {
            int nxtNode = nxtNodePair.second;
            int nxtPrice = priceTable[currentNode] + nxtNodePair.first;
            if (priceTable[nxtNode]>nxtPrice) { //nxtNode에 가는데 지금까지 발견한 방법보다 더 효율적인 방법을 찾은 경우-
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
