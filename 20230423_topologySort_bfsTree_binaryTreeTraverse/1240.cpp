#include <bits/stdc++.h>

using namespace std;

struct AdjNode {
    int node;
    int dist;
};

AdjNode makeAdjNode(int node, int dist) {
    AdjNode adjNode;
    adjNode.node = node;
    adjNode.dist = dist;
    return adjNode;
}

vector<AdjNode> adjList[1001];
vector<int> results; //numQueries 개수의 쿼리에 대한 답을 저장해두는 벡터


int bfs(int from, int to) {
    if (from==to) return 0;
    int parentOf[1001] = {0}; //특정 노드의 부모 노드를 기록해두는 노드
    queue<AdjNode> q;
    for (AdjNode adjNode:adjList[from]) {
        q.push(adjNode);
        parentOf[adjNode.node] = from;
    }
    while (!q.empty()) {
        int currentNode = q.front().node;
        int currentDist = q.front().dist;
        q.pop();
        if (currentNode==to) return currentDist;
        for (AdjNode adjNode:adjList[currentNode]) {
            if (adjNode.node==parentOf[currentNode]) continue; //다음에 가기 위해 고려하는 노드가 부모 노드일 경우 고려 대상에서 제외한다.
            AdjNode nextNode = makeAdjNode(adjNode.node, currentDist+adjNode.dist);
            q.push(nextNode);
            parentOf[nextNode.node] = currentNode;
        }
    }
    return -1;
}


int main() {
    int numNodes, numQueries;
    cin >> numNodes >> numQueries;
    for (int i=0; i<numNodes-1; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        adjList[from].push_back(makeAdjNode(to, dist));
        adjList[to].push_back(makeAdjNode(from, dist));
    }

    for (int i=0; i<numQueries; i++) {
        int from, to;
        cin >> from >> to;
        results.push_back(bfs(from, to));
    }
    for (int result:results) {
        cout << result << '\n';
    }
    return 0;
}
