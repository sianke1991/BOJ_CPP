#include <bits/stdc++.h>

using namespace std;

//vector<pair<int, int>> adjList[1001]; //인접 리스트 {소요 시간, 도착 노드}
int dist[1001][1001];       //최소 비용 테이블
const int INF = 10000000;

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int Max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    int numNodes, numEdges, gatherNode;
    cin >> numNodes >> numEdges >> gatherNode;
    /*
    for (int i=0; i<numEdges; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        adjList[s].push_back({d, t});
    } //i loop
    */
    for (int i=1; i<=numNodes; i++) {
        for (int j=1; j<=numNodes; j++) {
            dist[i][j] = INF;
        } //j loop
        dist[i][i] = 0;
    } //i loop

    for (int i=0; i<numEdges; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = Min(dist[s][t], d);
    }

    for (int k=1; k<=numNodes; k++) {
        for (int i=1; i<=numNodes; i++) {
            for (int j=1; j<=numNodes; j++) {
                dist[i][j] = Min(dist[i][j], dist[i][k]+dist[k][j]);
            } //j loop
        } //i loop
    } //k loop

    int maxTimeConsuming = 0;
    for (int i=1; i<=numNodes; i++) {
        maxTimeConsuming  = Max(maxTimeConsuming, dist[i][gatherNode]+dist[gatherNode][i]);
    }

    cout << maxTimeConsuming;
    return 0;
}
