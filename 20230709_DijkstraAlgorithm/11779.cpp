#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000000;

vector<pair<int, int>> adjList[1001]; //���� ����Ʈ
int distTable[1001]; //�Ÿ� ���̺� (�� ������ ���µ� ���� �ϴ� �ּ� �Ÿ�)
int prevTable[1001]; //Ư�� ��忡 �����ϱ� ���� ��� �ؾ� �ϴ� ��� (prevTable[���� ���] = ��� ���)
int startingNode, endingNode; //���� ���, ���� ���
stack<int> nodesInPath; //���� ��忡�� ����Ͽ� ���� ��忡 �����ϱ���� ���ľ� �ϴ� ��带 �������� �ۼ��� stack


//���� ��忡�� ����Ͽ� nextNode�� �����ϱ� ���� ���ľ� �ϴ� ��θ� ã�� nodesInPath�� �����Ѵ�.
void setPath() {
    if (startingNode == endingNode) {
        nodesInPath.push(startingNode);
        return;
    }
    int currentNode = endingNode;
    do {
        nodesInPath.push(currentNode);
        currentNode = prevTable[currentNode];
    } while (currentNode!=startingNode);
    nodesInPath.push(startingNode);
}

int main() {
    int numNodes, numEdges;
    scanf("%d", &numNodes);
    scanf("%d", &numEdges);

    for (int i=0; i<numEdges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjList[u].push_back({w, v});
    } //i loop
    scanf("%d %d", &startingNode, &endingNode);

    for (int i=1; i<=numNodes; i++) {
        distTable[i] = INF;
    }
    distTable[startingNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, startingNode});

    while (!pq.empty()) {
        pair<int, int> p0 = pq.top();
        pq.pop();

        int currentDist = p0.first;
        int currentNode = p0.second;
        if (currentDist!=distTable[currentNode]) continue; //�� ������ ���� ������ �ð��ʰ��� ���...

        for (pair<int, int>p1:adjList[currentNode]) {
            int nextDist = currentDist+p1.first;
            int nextNode = p1.second;

            if (distTable[nextNode]>nextDist) { //nextNode�� �����ϴµ� �� ȿ������ ����� ã�� ���-
                distTable[nextNode] = nextDist;
                prevTable[nextNode] = currentNode;
                pq.push({nextDist, nextNode});
            }
        } //p1 loop
    } //while loop

    setPath();
    int pathLength = nodesInPath.size();



    //�ּ� �Ÿ� ���
    printf("%d\n", distTable[endingNode]);
    //��� �� ��� ���� ���
    printf("%d\n", pathLength);
    // ��� ���
    while (!nodesInPath.empty()) {
        printf("%d ", nodesInPath.top());
        nodesInPath.pop();
    }

    return 0;
}
