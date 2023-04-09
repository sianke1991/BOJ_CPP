#include <bits/stdc++.h>

using namespace std;
int numNodes, numEdges, startingNode;
char adj[1001][1001];
char hasVisited[1001];
vector<int> DFSResults;
vector<int> BFSResults;

int main() {
    cin >> numNodes >> numEdges >> startingNode;
    for (int i=0; i<numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; //u에서 v로 연결되는 간선 있음
        adj[v][u] = 1; //v에서 u로 연결되는 간선 있음
    } //i loop

    //1. DFS
    stack<int> s;
    s.push(startingNode);
    while (!(s.empty())) {
        int u = s.top();
        s.pop();
        if (hasVisited[u]==1) continue;
        DFSResults.push_back(u);
        hasVisited[u] = 1;
        for (int v=numNodes; v>=1; v--) {
            if (adj[u][v]==0) continue;
            s.push(v);
        } //v loop
    }

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
