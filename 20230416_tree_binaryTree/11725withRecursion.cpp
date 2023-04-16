#include <bits/stdc++.h>

using namespace std;
int numNodes;
vector<int> adjList[100001];
int parentOf[100001];

void dfs(int currentNode) {
    for (int nextNode:adjList[currentNode]) {
        if (nextNode==parentOf[currentNode]) continue;
        parentOf[nextNode] = currentNode;
        dfs(nextNode);
    }
}

int main() {
    cin >> numNodes;
    for (int i=0; i<numNodes-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1);
    for (int i=2; i<=numNodes; i++) {
        cout << parentOf[i] << '\n';
    }
    return 0;
}
