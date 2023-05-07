//프림 알고리즘 (우선순위 큐를 사용)
//1. 임의의 정점을 선택해 최소 신장 트리에 추가
//2. 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선 중 비용이 가장 작은 것을 최소 신장 트리에 추가
//3. 최소 신장 트리에 V-1개의 간선이 추가될 때 까지 2번 과정을 반복한다.

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int nodeA;
    int nodeB;
    int distance;

    bool operator<(const edge that) const {
        return this->distance > that.distance;
    }

    string toString() {
        return "nodeA: "+to_string(this->nodeA)+", nodeB: "+to_string(this->nodeB)+", distance: "+to_string(this->distance);
    }
};

vector<edge> adjList[6];



struct edge makeEdge(int nodeA, int nodeB, int distance) {
    edge result;
    result.nodeA = nodeA;
    result.nodeB = nodeB;
    result.distance = distance;
    return result;
};

int main() {
    adjList[1].push_back(makeEdge(1, 2, 4));
    adjList[1].push_back(makeEdge(1, 3, 3));
    adjList[1].push_back(makeEdge(1, 4, 3));
    adjList[2].push_back(makeEdge(2, 1, 4));
    adjList[2].push_back(makeEdge(2, 5, 8));
    adjList[3].push_back(makeEdge(3, 1, 3));
    adjList[3].push_back(makeEdge(3, 4, 3));
    adjList[3].push_back(makeEdge(3, 5, 5));
    adjList[4].push_back(makeEdge(4, 1, 3));
    adjList[4].push_back(makeEdge(4, 3, 3));
    adjList[4].push_back(makeEdge(4, 5, 6));
    adjList[5].push_back(makeEdge(5, 2, 8));
    adjList[5].push_back(makeEdge(5, 3, 5));
    adjList[5].push_back(makeEdge(5, 4, 6));

    priority_queue<edge> pq;
    unordered_set<int> selectedNodes;

    selectedNodes.insert(1);
    for (edge e:adjList[1]) {
        pq.push(e);
    }
    while (selectedNodes.size()<5) {
        edge selectedEdge = pq.top();
        pq.pop();
        if (selectedNodes.find(selectedEdge.nodeB)!=selectedNodes.end()) continue;
        cout << selectedEdge.toString() << '\n';
        int selectedNode = selectedEdge.nodeB;
        selectedNodes.insert(selectedNode);
        for (edge e:adjList[selectedNode]) {
            pq.push(e);
        }
    }
    return 0;
}
