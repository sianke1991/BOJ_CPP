/*
    ������� ģ�� ������ ���� ���̷� ����Ǵ��� ���θ� �����ϱ� ���� union-find ����� ����Ѵ�.
    �������� �־����� ������� ����� ģ�� ���� Ȥ�� ���� �����ε�,
    �̸� ���� ����Ʈ�� ǥ���ϱ� ���� ������ ����ġ�� �д�.
    �ϳ��� �׷��� ���� �̺� �׷������� ���θ� �ش� �׷��� ���� ��Ʈ ��忡 ������ �д�.
    �׷��� �� ��� ���� ���� �̺� �׷������� ���θ� �ľ��� �� ������ ��ȸ�Ѵ�.
    1. �� ��尡 �ٸ� ���� ���� ��� Unknown�� ����Ѵ�.
    2. �� ��尡 ���� ���� �̺� �׷����� �ƴ� ��� Error�� ����Ѵ�.
    3. �� ��尡 ���� ������ Friend��, �� ����� ���� �ٸ��� Enemy�� ����Ѵ�.
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
int isBipartite[100001]; //�̺б׷��� ���� ���� ��� 0, �̺� �׷����� ��� 1, �̺� �׷����� �ƴ� ��� 2 (��Ʈ ��忡�� ������)

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
            if (p.first==0) { //ģ�� ����
                if (visited[p.second]==currentColour) {
                    continue;
                }
                if (visited[p.second]==oppositeColour) {
                    isBipartite[node] = 2;
                    return;
                }
                visited[p.second] = currentColour;
                q.push(p.second);
            } else { //���� ����
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
    //parentOf �迭 �ʱ�ȭ
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

    //�� �׷����� ���� ���� �̺� �׷��� ������ �Ѵ�.
    for (int startNode=1; startNode<=numNodes; startNode++) {
        int rootNode = rootOf(startNode);
        if (isBipartite[rootNode]) continue; //�̺� �׷��� ���θ� Ȯ���� ���-
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
        if (isBipartite[root0]==2) { //�̺� �׷����� �ƴ� ���-
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
