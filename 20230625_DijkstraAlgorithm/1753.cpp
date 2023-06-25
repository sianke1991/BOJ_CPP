#include <bits/stdc++.h>

using namespace std;
const int INF = 100000000;

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    int startingNode;
    cin >> startingNode;

    int distTable[numNodes+1];
    for (int i=1; i<=numNodes; i++)
        distTable[i] = INF;
    distTable[startingNode] = 0;

    vector<pair<int, int>> adjList[numNodes+1];

    for (int i=0; i<numEdges; i++) {
        int u, v, w; //���� ����: ���� ���, ���� ���, ���� ����ġ
        cin >> u >> v >> w;
        adjList[u].push_back({w, v}); //{���� ����ġ, ���� ���} ���� vector�� �ִ´�.
    } //i loop

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //���� ��带 �켱���� ť�� �ִ´�.
    pq.push({0, startingNode});

    while (!pq.empty()) {
        pair<int, int> p0 = pq.top();
        pq.pop();
        int currentDist = p0.first;
        int currentNode = p0.second;

        //currentDist�� distTable[currentNode]�� �ٸ� ��� continue ó���� ���� �� �ִµ�,
        //��¥�� ������ ������ distTable�� ���� ���̹Ƿ� continue ó���� ���� �ʾƵ� OK�̴�.
        //PQ���� ������ �� ȿ������ {�Ÿ�, ���} ���� �ƹ��� ȿ�� ���� �ݺ����� ������ �ȴ�.


        for (pair<int, int> p1:adjList[currentNode]) {
            int nextDist = currentDist + p1.first;
            int nextNode = p1.second;
            if (distTable[nextNode] > nextDist) { //nextNode�� ���µ� �� ȿ������ ����� ã�� ���-
                distTable[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    } //while loop

    for (int i=1; i<=numNodes; i++) {
        int dist = distTable[i];
        if (dist>=INF) {
            cout << "INF\n";
        } else {
            cout << dist << '\n';
        }
    }

    return 0;
}
