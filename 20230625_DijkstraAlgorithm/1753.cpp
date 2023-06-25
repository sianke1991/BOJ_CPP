#include <bits/stdc++.h>

using namespace std;
const int INF = 100000000;

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    int startingNode;
    cin >> startingNode;

    int distTable[numNodes+1];
    for (int i=1; i<=numNodes; i++)
        distTable[i] = INF;
    distTable[startingNode] = 0;

    vector<pair<int, int>> adjList[numNodes+1];

    for (int i=0; i<numEdges; i++) {
        int u, v, w; //간선 정보: 시작 노드, 도착 노드, 간선 가중치
        cin >> u >> v >> w;
        adjList[u].push_back({w, v}); //{간선 가중치, 도착 노드} 쌍을 vector에 넣는다.
    } //i loop

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //시작 노드를 우선순위 큐에 넣는다.
    pq.push({0, startingNode});

    while (!pq.empty()) {
        pair<int, int> p0 = pq.top();
        pq.pop();
        int currentDist = p0.first;
        int currentNode = p0.second;

        //currentDist가 distTable[currentNode]와 다를 경우 continue 처리를 해줄 수 있는데,
        //어짜피 최적의 값만을 distTable에 넣을 것이므로 continue 처리를 하지 않아도 OK이다.
        //PQ에서 꺼내진 덜 효율적인 {거리, 노드} 쌍은 아무런 효과 없이 반복문을 지나게 된다.


        for (pair<int, int> p1:adjList[currentNode]) {
            int nextDist = currentDist + p1.first;
            int nextNode = p1.second;
            if (distTable[nextNode] > nextDist) { //nextNode에 가는데 더 효율적인 방법을 찾은 경우-
                distTable[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    } //while loop

    for (int i=1; i<=numNodes; i++) {
        int dist = distTable[i];
        if (dist>=INF) {
            cout << "INF\n";
        } else {
            cout << dist << '\n';
        }
    }

    return 0;
}
