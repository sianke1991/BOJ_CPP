#include <bits/stdc++.h>

using namespace std;

int edge[10][2]; //간선 정보 (edge[x][0]: x 번째 간선의 출발 노드, edge[x][1]: x 번째 간선의 도착 노드)
int deg[10]; //각 정점의 outdegree
int* adj[10]; //adj[x]: 노드 x에서 출발하는 간선들 정보
int idx[10]; //adj[i] 에서 새로운 정점을 추가할 때의 위치

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++; //각 노드에 대해 필요한 배열의 크기를 계산한다.
    } //i loop

    for (int i=1; i<=v; i++)
        adj[i] = new int[deg[i]]; //각 노드에 대해 필요한 크기의 배열을 생성한다.
    for (int i=0; i<e; i++) {
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v; //idx[u]는 0부터 시작해서 1씩 증가한다.
        idx[u]++;
    } //i loop (노드 루브)
    return 0;
}
