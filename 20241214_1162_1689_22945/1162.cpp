#include <bits/stdc++.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

const long long INF = LLONG_MAX>>3;
// distTable[A][B] := 포장 도로를 A 개 사용하여 B 도시에 도착하는데 걸리는 최소 시간
long long distTable[21][10010];
// adjList[A] := 도시 A와 연결된 간선 목록, {간선의 가중치, 간선의 다른 쪽 노드 번호} 쌍으로 정보를 저장
vector<pair<long long, int>> adjList[10010];
// 도시의 개수
int numNodes;
// 도로의 개수
int numEdges;
// 포장할 도로 개수
int numPaves;


void input() {
    scanf("%d %d %d", &numNodes, &numEdges, &numPaves);
    for (int p=0; p<=numPaves; p++) {
        //distTable[p][1] = -1LL;
        for (int n=2; n<=numNodes; n++) {
            distTable[p][n] = INF;
        } //n loop
    } //p loop

    for (int e=0; e<numEdges; e++) {
        int nodeA, nodeB; long long dist;
        scanf("%d %d %lld", &nodeA, &nodeB, &dist);
        adjList[nodeA].push_back({dist, nodeB});
        adjList[nodeB].push_back({dist, nodeA});
    } //e loop
}

int main() {
    input();
    // {시간, 포장 도로 사용한 개수, 도착 노드}
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 0, 1});
    while (!pq.empty()) {
        long long currentDist = get<0>(pq.top());
        int currentNumPaves = get<1>(pq.top());
        int currentNode = get<2>(pq.top());
        pq.pop();
        if (distTable[currentNumPaves][currentNode]<currentDist)
            continue;
        for (pair<long long, int> edge:adjList[currentNode]) {
            int nextNode = edge.second;
            //nextNode로 가는데 포장도로를 사용하지 않는 경우-
            int nextNumPaves = currentNumPaves;
            long long nextDist = currentDist + edge.first;
            if (distTable[nextNumPaves][nextNode]>nextDist) {
                distTable[nextNumPaves][nextNode] = nextDist;
                pq.push({nextDist, nextNumPaves, nextNode});
            }
            //nextNode로 가는데 포장도로를 사용하는 경우-
            nextNumPaves++;
            if (nextNumPaves>numPaves)
                continue;
            nextDist = currentDist;
            if (distTable[nextNumPaves][nextNode]>nextDist) {
                distTable[nextNumPaves][nextNode] = nextDist;
                pq.push({nextDist, nextNumPaves, nextNode});
            }
        } //edge loop
    } //while loop

    /*
    for (int p=0; p<=numPaves; p++) {
        for (int n=1; n<=numNodes; n++) {
            printf("%lld ", distTable[p][n]);
        }
        puts("");
    }
    */

    long long result = distTable[0][numNodes];
    for (int p=1; p<=numPaves; p++) {
        if (result>distTable[p][numNodes])
            result = distTable[p][numNodes];
    } //p loop
    printf("%lld", result);
    return 0;
}
