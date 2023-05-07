#include <bits/stdc++.h>

using namespace std;

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<pair<int, int>> adjList[10001]; //인접리스트 {비용, 도착노드}

    for (int i=0; i<numEdges; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        adjList[nodeA].push_back({weight, nodeB});
        adjList[nodeB].push_back({weight, nodeA});
    }


    //tuple<int, int, int> {비용, 출발노드, 도착노드}
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
    bool isNodeAlreadySelected[10001];
    for (int i=0; i<10001; i++) isNodeAlreadySelected[i] = false;
    int numSelectedEdges = 0;
    long long sumWeight = 0;

    isNodeAlreadySelected[1] = true;
    for (pair<int, int> e:adjList[1]) {
        pq.push({e.first, 1, e.second});
    }

    while (numSelectedEdges<numNodes-1) {
        tuple<int, int, int> selectedEdge = pq.top();
        pq.pop();
        if (isNodeAlreadySelected[get<2>(selectedEdge)]) continue;
        sumWeight += get<0>(selectedEdge);
        isNodeAlreadySelected[get<2>(selectedEdge)] = true;
        numSelectedEdges++;
        for (pair<int, int> e:adjList[get<2>(selectedEdge)]) {
            //if (isNodeAlreadySelected[e.second]) continue; //이 if문은 필수는 아닌 듯 하다.
            pq.push({e.first, get<2>(selectedEdge), e.second});
        }
    }
    cout << sumWeight;
    return 0;
}
