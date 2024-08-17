#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int RED = 1;
const int BLUE = 2;

bool test() {
    int numNodes; //V (������ ����)
    int numEdges; //E (������ ����)
    vector<int> adjList[20001]; //���� ����Ʈ
    scanf("%d %d", &numNodes, &numEdges);
    for (int i=0; i<numEdges; i++) {
        int node0, node1;
        scanf("%d %d", &node0, &node1);
        adjList[node0].push_back(node1);
        adjList[node1].push_back(node0);
    } //i loop

    int visited[numNodes+1] = {0};
    //�� �̻����� �и��� �׷����� �� ������ �̿��� ��峢�� �ٸ� ������ ĥ�� �� �ִٸ� �ش� �׷����� �̺� �׷����̴�.
    //���� � �׷����� �̺� �׷������� ���θ� Ȯ���ϱ� ���ؼ� �� ��忡���� Ž���� �����ϸ� �ȵȴ�.
    for (int startNode=1; startNode<=numNodes; startNode++) {
        if (visited[startNode])
            continue;
        visited[startNode] = RED;
        queue<int> q;
        q.push(startNode);
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            int currentColour = visited[currentNode];
            int oppositeColour = 3-currentColour;
            for (int nextNode:adjList[currentNode]) {
                if (visited[nextNode]==currentColour) //�ٷ� �� ��尡 ���� ���� ���� ���� �ϰ� ������ �ش� �׷����� �̺� �׷����� �ƴϴ�.
                    return false;
                if (visited[nextNode]==oppositeColour)
                    continue;
                visited[nextNode] = oppositeColour;
                q.push(nextNode);
            } //nextNode loop
        } //while loop
    } //startNode loop
    return true;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    vector<int> result;
    for (int i=0; i<numTestCases; i++) {
        if (test()) result.push_back(1);
        else        result.push_back(0);
    } //i loop
    for (int elem:result) {
        if (elem) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
