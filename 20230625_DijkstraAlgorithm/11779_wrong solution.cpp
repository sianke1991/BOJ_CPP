#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
const int INF = 1000000000;

vector<pair<int, int>> adjList[1001]; //���� ����Ʈ
int distTable[1001]; //�Ÿ� ���̺� (�� ������ ���µ� ���� �ϴ� �ּ� �Ÿ�)
int prevTable[1001]; //Ư�� ��忡 �����ϱ� ���� ��� �ؾ� �ϴ� ��� (prevTable[���� ���] = ��� ���)
int startingNode, endingNode; //���� ���, ���� ���
vector<int> nodesInPath; //���� ��忡�� ����Ͽ� ���� ��忡 �����ϱ���� ���ľ� �ϴ� ��带 �������� �ۼ��� vector


//���� ��忡�� ����Ͽ� nextNode�� �����ϱ� ���� ���ľ� �ϴ� ��θ� ã�� nodesInPath�� �����Ѵ�.
void setPath() {
    if (startingNode == endingNode) {
        nodesInPath.push_back(startingNode);
        return;
    }
    int currentNode = endingNode;
    do {
        nodesInPath.push_back(currentNode);
        currentNode = prevTable[currentNode];
    } while (currentNode!=startingNode);
    nodesInPath.push_back(startingNode);
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
    cin >> startingNode >> endingNode;

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

    //setPath(); //��� ����
    if (startingNode == endingNode) {
        nodesInPath.push_back(startingNode);
    } else {
        int currentNode = endingNode;
        do {
            nodesInPath.push_back(currentNode);
            currentNode = prevTable[currentNode];
        } while (currentNode!=startingNode);
        nodesInPath.push_back(startingNode);
    }
    reverse(nodesInPath.begin(), nodesInPath.end()); //��� ��� �� ���� ��� for loop�� ����ϱ� ���� nodesInPath�� �������ش�.

    //�ּ� �Ÿ� ���
    printf("%d\n", distTable[endingNode]);
    //��� �� ��� ���� ���
    printf("%d\n", nodesInPath.size());
    // ��� ���
    for (int node:nodesInPath) {
        printf("%d ", node);
    }

    return 0;
}
