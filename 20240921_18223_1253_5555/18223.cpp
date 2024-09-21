#include <stdio.h>
#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

/*
    출발 노드에서 도착 노드에 가는데 걸리는 최소 거리와
    출발 노드에서 건우의 위치에 가고, 건우의 위치에서 도착 노드에 가는데 걸리는 최소 거리
    이 둘을 비교해서 두 값이 같으면
    최소 거리로 건우의 위치에 들러서 도착 노드에 갈 수 있음을 의미한다.
    한 노드에서 다른 노드로 가는데 걸리는 최소 거리를 구하기 위해 Dijkstra 최단 거리 알고리즘을 적용할 수 있다.
    이 문제는 Dijkstra 최단 경로 알고리즘을 두 번 사용해야 한다. (출발 노드에서 한 번, 건우의 위치에서 또 한 번)
*/

int numNodes; //출발 노드는 1번, 도착 노드는 numNodes번 이다.
int passingNode; //건우의 위치
vector<pair<int, int>> adjList[5001]; //각 노드에 대해 뻗어나가는 간선의 정보를 {거리, 도착 노드}의 쌍으로 저장한다.

void input() {
    int numEdges; //간선의 개수
    scanf("%d %d %d", &numNodes, &numEdges, &passingNode);
    for (int i=0; i<numEdges; i++) {
        int node0, node1, dist;
        scanf("%d %d %d", &node0, &node1, &dist);
        adjList[node0].push_back({dist, node1});
        adjList[node1].push_back({dist, node0});
    }
}

int distTable0[5001];
int distTable1[5001];

//출발 지점에서 Dijkstra 알고리즘을 적용한다.
void dijkstra0() {
    for (int i=1; i<=numNodes; i++)
        distTable0[i] = INF;
    distTable0[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair의 최소 힙
    pq.push({0, 1});
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDist>distTable0[currentNode])
            continue;
        for (auto edge:adjList[currentNode]) {
            int nextDist = currentDist+edge.first;
            int nextNode = edge.second;
            if (nextDist<distTable0[nextNode]) {
                distTable0[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        } //edge loop
    } //while loop
}

//건우가 있는 지점에서 Dijkstra 알고리즘을 적용한다.
void dijkstra1() {
    for (int i=1; i<=numNodes; i++)
        distTable1[i] = INF;
    distTable1[passingNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair의 최소 힙
    pq.push({0, passingNode});
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDist>distTable1[currentNode])
            continue;
        for (auto edge:adjList[currentNode]) {
            int nextDist = currentDist+edge.first;
            int nextNode = edge.second;
            if (nextDist<distTable1[nextNode]) {
                distTable1[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        } //edge loop
    } //while loop
}

int main() {
    input();
    dijkstra0();
    dijkstra1();
    int dist0 = distTable0[numNodes]; //건우를 지나치고 바로 마산에 갈 때 최소 거리
    int dist1 = distTable0[passingNode] + distTable1[numNodes]; //건우의 위치를 경유하고 마산에 갈 때 최소 거리
    if (dist1<=dist0) {
        printf("SAVE HIM");
    } else {
        printf("GOOD BYE");
    }
    return 0;
}
