#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000000;

vector<pair<int, int>> adjList[1001]; //인접 리스트
int distTable[1001]; //거리 테이블 (각 노드까지 가는데 가야 하는 최소 거리)
int prevTable[1001]; //특정 노드에 도착하기 위해 출발 해야 하는 노드 (prevTable[도착 노드] = 출발 노드)
int startingNode, endingNode; //시작 노드, 도착 노드
stack<int> nodesInPath; //시작 노드에서 출발하여 도착 노드에 도달하기까지 거쳐야 하는 노드를 역순으로 작성한 stack


//시작 노드에서 출발하여 nextNode에 도달하기 위해 거쳐야 하는 경로를 찾아 nodesInPath를 구성한다.
void setPath() {
    if (startingNode == endingNode) {
        nodesInPath.push(startingNode);
        return;
    }
    int currentNode = endingNode;
    do {
        nodesInPath.push(currentNode);
        currentNode = prevTable[currentNode];
    } while (currentNode!=startingNode);
    nodesInPath.push(startingNode);
}

int main() {
    int numNodes, numEdges;
    scanf("%d", &numNodes);
    scanf("%d", &numEdges);

    for (int i=0; i<numEdges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjList[u].push_back({w, v});
    } //i loop
    scanf("%d %d", &startingNode, &endingNode);

    for (int i=1; i<=numNodes; i++) {
        distTable[i] = INF;
    }
    distTable[startingNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, startingNode});

    while (!pq.empty()) {
        pair<int, int> p0 = pq.top();
        pq.pop();

        int currentDist = p0.first;
        int currentNode = p0.second;
        if (currentDist!=distTable[currentNode]) continue; //이 로직이 들어가지 않으면 시간초과가 뜬다...

        for (pair<int, int>p1:adjList[currentNode]) {
            int nextDist = currentDist+p1.first;
            int nextNode = p1.second;

            if (distTable[nextNode]>nextDist) { //nextNode에 도달하는데 더 효율적인 방법을 찾은 경우-
                distTable[nextNode] = nextDist;
                prevTable[nextNode] = currentNode;
                pq.push({nextDist, nextNode});
            }
        } //p1 loop
    } //while loop

    setPath();
    int pathLength = nodesInPath.size();



    //최소 거리 출력
    printf("%d\n", distTable[endingNode]);
    //경로 상 노드 개수 출력
    printf("%d\n", pathLength);
    // 경로 출력
    while (!nodesInPath.empty()) {
        printf("%d ", nodesInPath.top());
        nodesInPath.pop();
    }

    return 0;
}
