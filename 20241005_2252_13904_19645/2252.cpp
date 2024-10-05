#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int numNodes;
int numEdges;
int indegreeOf[32001];
vector<int> adjList[32001];
queue<int> q;
vector<int> path;

int main() {
    //�Է�
    scanf("%d %d", &numNodes, &numEdges);
    for (int i=0; i<numEdges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adjList[from].push_back(to);
        indegreeOf[to]++;
    }
    //���� ������ 0�� ��带 q�� �ִ´�.
    for (int i=1; i<=numNodes; i++) {
        if (indegreeOf[i]==0) q.push(i);
    }
    //q���� ���Ҹ� �̰�, q�� ����� ����� ���� ������ 1 ���ҽ�Ų��.
    //���� ������ 0�� �� ���� q�� �ִ´�.
    while (!q.empty()) {
        int currentNode = q.front();
        path.push_back(currentNode);
        q.pop();
        for (int nextNode:adjList[currentNode]) {
            indegreeOf[nextNode]--;
            if (indegreeOf[nextNode]==0)
                q.push(nextNode);
        }
    }
    for (int elem:path)
        printf("%d ", elem);
    return 0;
}
