#include <bits/stdc++.h>

using namespace std;

const long long INF = 200000000000LL;
vector<pair<long long, int>> adjList[1001]; //인접리스트 {거리, 도착 노드}
long long distTable[1001];

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i=0; i<numEdges; i++) {
        int s, t;
        long long d;
        cin >> s >> t >> d;
        adjList[s].push_back({d, t});
    }

    int startingNode, endingNode;
    cin >> startingNode >> endingNode;

    for (int i=1; i<=numNodes; i++) {
        distTable[i] = INF;
    }
    distTable[startingNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0LL, startingNode});
    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (distTable[currentNode]!=currentDist) continue;

        for (pair<long long, int> p:adjList[currentNode]) {
            long long nextDist = p.first+currentDist;
            int nextNode = p.second;

            if (distTable[nextNode]>nextDist) {
                distTable[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        } //p loop
    } //while loop

    cout << distTable[endingNode];
    return 0;
}
