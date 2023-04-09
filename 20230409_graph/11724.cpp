#include <bits/stdc++.h>

using namespace std;

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<int> adj[numNodes+1];
    bool hasVisited[numNodes+1];
    for (int i=0; i<numNodes+1; i++) {
        hasVisited[i] = false;
    }
    for (int i=0; i<numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } //i loop

    int numConnectedComponents = 0;
    for (int i=1; i<=numNodes; i++) {
        if (hasVisited[i]) continue;
        numConnectedComponents++;
        queue<int> q;
        hasVisited[i] = true;
        q.push(i);
        while (!(q.empty())) {
            int u = q.front();
            q.pop();
            for (int v:adj[u]) {
                if (hasVisited[v]) continue;
                q.push(v);
                hasVisited[v] = true;
            } //v loop
        } //while q is not empty
    } //i loop
    cout << numConnectedComponents;
    return 0;
}
