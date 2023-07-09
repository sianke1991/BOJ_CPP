#include <bits/stdc++.h>

using namespace std;

const int INF = 500000000;
vector<pair<int, int>> adjList[801]; //인접 리스트, {거리, 도착 노드}

int distFrom1[801]; //1번 노드에서 각 노드에 도달하는데 필요한 거리
int distFromV1[801]; //V1번 노드에서 각 노드에 도달하는데 필요한 거리
int distFromV2[801]; //V2번 노드에서 각 노드에 도달하는데 필요한 거리

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    //인접 리스트 구성
    for (int i=0; i<numEdges; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        adjList[s].push_back({d, t});
        adjList[t].push_back({d, s});
    }

    int v1, v2;
    cin >> v1 >> v2;

    //거리 테이블 초기화
    for (int i=1; i<=numNodes; i++) {
        distFrom1[i] = INF;
        distFromV1[i] = INF;
        distFromV2[i] = INF;
    }
    distFrom1[1] = 0;
    distFromV1[v1] = 0;
    distFromV2[v2] = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    pq1.push({0, 1});

    while (!pq1.empty()) {
        int currentDist = pq1.top().first;
        int currentNode = pq1.top().second;
        pq1.pop();

        if (distFrom1[currentNode]!=currentDist) continue;

        for (pair<int, int> p:adjList[currentNode]) {
            int nextDist = p.first + currentDist;
            int nextNode = p.second;
            if (distFrom1[nextNode]>nextDist) {
                distFrom1[nextNode] = nextDist;
                pq1.push({nextDist, nextNode});
            }
        } //p loop
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqV1;
    pqV1.push({0, v1});

    while (!pqV1.empty()) {
        int currentDist = pqV1.top().first;
        int currentNode = pqV1.top().second;
        pqV1.pop();

        if (distFromV1[currentNode]!=currentDist) continue;

        for (pair<int, int> p:adjList[currentNode]) {
            int nextDist = p.first + currentDist;
            int nextNode = p.second;
            if (distFromV1[nextNode]>nextDist) {
                distFromV1[nextNode] = nextDist;
                pqV1.push({nextDist, nextNode});
            }
        } //p loop
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqV2;
    pqV2.push({0, v2});

    while (!pqV2.empty()) {
        int currentDist = pqV2.top().first;
        int currentNode = pqV2.top().second;
        pqV2.pop();

        if (distFromV2[currentNode]!=currentDist) continue;

        for (pair<int, int> p:adjList[currentNode]) {
            int nextDist = p.first + currentDist;
            int nextNode = p.second;
            if (distFromV2[nextNode]>nextDist) {
                distFromV2[nextNode] = nextDist;
                pqV2.push({nextDist, nextNode});
            }
        } //p loop
    }

    int v1_v2_dist = distFrom1[v1] + distFromV1[v2] + distFromV2[numNodes];
    int v2_v1_dist = distFrom1[v2] + distFromV2[v1] + distFromV1[numNodes];
    int minDist = Min(v1_v2_dist, v2_v1_dist);
    if (minDist >= INF) cout << -1;
    else cout << minDist;

    return 0;
}
