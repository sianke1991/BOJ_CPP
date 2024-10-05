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
    //입력
    scanf("%d %d", &numNodes, &numEdges);
    for (int i=0; i<numEdges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adjList[from].push_back(to);
        indegreeOf[to]++;
    }
    //진입 차수가 0인 노드를 q에 넣는다.
    for (int i=1; i<=numNodes; i++) {
        if (indegreeOf[i]==0) q.push(i);
    }
    //q에서 원소를 뽑고, q와 연결된 노드의 진입 차수를 1 감소시킨다.
    //진입 차수가 0이 된 노드는 q에 넣는다.
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
