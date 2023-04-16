#include <bits/stdc++.h>

using namespace std;
vector<int> adjList[100001];
int parentOf[100001];

int main() {
    //트리의 특성 상 노드가 N개 일 때 간선은 N-1개 존재한다.
    int numNodes;
    cin >> numNodes;
    for (int i=0; i<numNodes-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } //i loop

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt:adjList[cur]) {
            if (nxt==parentOf[cur]) continue; //부모 노드는 이미 방문한 상태이므로 큐에 넣지 않는다.
            q.push(nxt);
            parentOf[nxt] = cur;
        }
    } //while loop

    for (int i=2; i<=numNodes; i++) {
        cout << parentOf[i] << '\n';
    }
    return 0;
}
