#include <bits/stdc++.h>

using namespace std;
int numNodes, numEdges, startingNode;
char adj[1001][1001];
char hasVisited[1001];
vector<int> DFSResults;
vector<int> BFSResults;

void DFS(int currentNode) {
    if (hasVisited[currentNode]==1) return;
    DFSResults.push_back(currentNode);
    hasVisited[currentNode] = 1;
    for (int i=1; i<=numNodes; i++) {
        if (adj[currentNode][i]==0) continue;
        DFS(i);
    }
}


int main() {
    cin >> numNodes >> numEdges >> startingNode;
    for (int i=0; i<numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; //u에서 v로 연결되는 간선 있음
        adj[v][u] = 1; //v에서 u로 연결되는 간선 있음
    } //i loop

    DFS(startingNode);

    //2. BFS
    queue<int> q;
    q.push(startingNode);
    hasVisited[startingNode] = 2;
    while (!(q.empty())) {
        int u = q.front();
        q.pop();
        BFSResults.push_back(u);
        for (int v=1; v<=numNodes; v++) {
            if (hasVisited[v]==2) continue;
            if (adj[u][v]==0) continue;
            q.push(v);
            hasVisited[v] = 2;
        } //v loop
    }

    //print

    for (int result:DFSResults) {
        cout << result << ' ';
    }
    cout << '\n';
    for (int result:BFSResults) {
        cout << result << ' ';
    }
    return 0;
}
