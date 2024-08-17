#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int RED = 1;
const int BLUE = 2;

bool test() {
    int numNodes; //V (정점의 개수)
    int numEdges; //E (간선의 개수)
    vector<int> adjList[20001]; //인접 리스트
    scanf("%d %d", &numNodes, &numEdges);
    for (int i=0; i<numEdges; i++) {
        int node0, node1;
        scanf("%d %d", &node0, &node1);
        adjList[node0].push_back(node1);
        adjList[node1].push_back(node0);
    } //i loop

    int visited[numNodes+1] = {0};
    //둘 이상으로 분리된 그래프라도 두 색으로 이웃한 노드끼리 다른 색으로 칠할 수 있다면 해당 그래프는 이분 그래프이다.
    //따라서 어떤 그래프가 이분 그래프인지 여부를 확인하기 위해선 한 노드에서만 탐색을 시작하면 안된다.
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
                if (visited[nextNode]==currentColour) //바로 옆 노드가 현재 노드와 같은 색을 하고 있으면 해당 그래프는 이분 그래프가 아니다.
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
