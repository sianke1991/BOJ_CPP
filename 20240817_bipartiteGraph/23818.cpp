/*
    사람들이 친구 내지는 원수 사이로 연결되는지 여부를 관리하기 위해 union-find 기법을 사용한다.
    문제에서 주어지는 사람간의 관계는 친구 관계 혹은 원수 관계인데,
    이를 인접 리스트로 표현하기 위해 간선에 가중치를 둔다.
    하나의 그래프 섬이 이분 그래프인지 여부를 해당 그래프 섬의 루트 노드에 기입해 둔다.
    그래프 내 모든 섬에 대해 이분 그래프인지 여부를 파악한 뒤 쿼리를 조회한다.
    1. 두 노드가 다른 섬에 속한 경우 Unknown을 출력한다.
    2. 두 노드가 속한 섬이 이분 그래프가 아닐 경우 Error를 출력한다.
    3. 두 노드가 색이 같으면 Friend를, 두 노드의 색이 다르면 Enemy를 출력한다.
*/


#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int RED = 1;
const int BLUE = 2;
const int VIOLET = 4;

int visited[100001];
int parentOf[100001];
vector<pair<int, int>> adjList[100001];
vector<pair<int, int>> queries;
int isBipartite[100001]; //이분그래프 점검 전일 경우 0, 이분 그래프일 경우 1, 이분 그래프가 아닐 경우 2 (루트 노드에만 기입함)

int rootOf(int node) {
    if (parentOf[node]!=node) {
        parentOf[node] = rootOf(parentOf[node]);
    }
    return parentOf[node];
}

void unionize(int node0, int node1) {
    int root0 = rootOf(node0), root1 = rootOf(node1);
    if (root0<root1) {
        parentOf[root1] = root0;
    } else {
        parentOf[root0] = root1;
    }
}

void checkBipartitieFrom(int node) {
    queue<int> q;
    visited[node] = RED;
    q.push(node);
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        int currentColour = visited[currentNode];
        int oppositeColour = 3-currentColour;
        for (auto p:adjList[currentNode]) {
            if (p.first==0) { //친구 관계
                if (visited[p.second]==currentColour) {
                    continue;
                }
                if (visited[p.second]==oppositeColour) {
                    isBipartite[node] = 2;
                    return;
                }
                visited[p.second] = currentColour;
                q.push(p.second);
            } else { //원수 관계
                if (visited[p.second]==oppositeColour) {
                    continue;
                }
                if (visited[p.second]==currentColour) {
                    isBipartite[node] = 2;
                    return;
                }
                visited[p.second] = oppositeColour;
                q.push(p.second);
            }
        } //p loop
    } //while loop
    isBipartite[node] = 1;
}

int main() {
    int numNodes, numEdges, numQueries;
    scanf("%d %d %d", &numNodes, &numEdges, &numQueries);
    //parentOf 배열 초기화
    for (int i=0; i<=numNodes; i++)
        parentOf[i] = i;
    for (int i=0; i<numEdges; i++) {
        int relation, node0, node1;
        scanf("%d %d %d", &relation, &node0, &node1);
        adjList[node0].push_back({relation, node1});
        adjList[node1].push_back({relation, node0});
        unionize(node0, node1);
    } //i loop
    for (int i=0; i<numQueries; i++) {
        int node0, node1;
        scanf("%d %d", &node0, &node1);
        queries.push_back({node0, node1});
    }

    //각 그래프의 섬에 대해 이분 그래프 점검을 한다.
    for (int startNode=1; startNode<=numNodes; startNode++) {
        int rootNode = rootOf(startNode);
        if (isBipartite[rootNode]) continue; //이분 그래프 여부를 확인한 경우-
        checkBipartitieFrom(rootNode);
    }

    //0: Unknown, 1: Friend, 2: Enemy, 3: Error
    vector<int> result;
    for (pair<int, int> query:queries) {
        int node0 = query.first, node1 = query.second;
        int root0 = rootOf(node0), root1 = rootOf(node1);
        if (root0!=root1) {
            result.push_back(0);
            continue;
        }
        if (isBipartite[root0]==2) { //이분 그래프가 아닐 경우-
            result.push_back(3);
            continue;
        }
        if (visited[node0]==visited[node1]) {
            result.push_back(1);
        } else {
            result.push_back(2);
        }
    }

    for (int elem:result) {
        switch (elem) {
            case 0: printf("Unknown\n"); break;
            case 1: printf("Friend\n"); break;
            case 2: printf("Enemy\n"); break;
            case 3: printf("Error\n"); break;
        }
    }

    return 0;
}
