#include <stdio.h>
#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

/*
    ��� ��忡�� ���� ��忡 ���µ� �ɸ��� �ּ� �Ÿ���
    ��� ��忡�� �ǿ��� ��ġ�� ����, �ǿ��� ��ġ���� ���� ��忡 ���µ� �ɸ��� �ּ� �Ÿ�
    �� ���� ���ؼ� �� ���� ������
    �ּ� �Ÿ��� �ǿ��� ��ġ�� �鷯�� ���� ��忡 �� �� ������ �ǹ��Ѵ�.
    �� ��忡�� �ٸ� ���� ���µ� �ɸ��� �ּ� �Ÿ��� ���ϱ� ���� Dijkstra �ִ� �Ÿ� �˰����� ������ �� �ִ�.
    �� ������ Dijkstra �ִ� ��� �˰����� �� �� ����ؾ� �Ѵ�. (��� ��忡�� �� ��, �ǿ��� ��ġ���� �� �� ��)
*/

int numNodes; //��� ���� 1��, ���� ���� numNodes�� �̴�.
int passingNode; //�ǿ��� ��ġ
vector<pair<int, int>> adjList[5001]; //�� ��忡 ���� ������� ������ ������ {�Ÿ�, ���� ���}�� ������ �����Ѵ�.

void input() {
    int numEdges; //������ ����
    scanf("%d %d %d", &numNodes, &numEdges, &passingNode);
    for (int i=0; i<numEdges; i++) {
        int node0, node1, dist;
        scanf("%d %d %d", &node0, &node1, &dist);
        adjList[node0].push_back({dist, node1});
        adjList[node1].push_back({dist, node0});
    }
}

int distTable0[5001];
int distTable1[5001];

//��� �������� Dijkstra �˰����� �����Ѵ�.
void dijkstra0() {
    for (int i=1; i<=numNodes; i++)
        distTable0[i] = INF;
    distTable0[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair�� �ּ� ��
    pq.push({0, 1});
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDist>distTable0[currentNode])
            continue;
        for (auto edge:adjList[currentNode]) {
            int nextDist = currentDist+edge.first;
            int nextNode = edge.second;
            if (nextDist<distTable0[nextNode]) {
                distTable0[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        } //edge loop
    } //while loop
}

//�ǿ찡 �ִ� �������� Dijkstra �˰����� �����Ѵ�.
void dijkstra1() {
    for (int i=1; i<=numNodes; i++)
        distTable1[i] = INF;
    distTable1[passingNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair�� �ּ� ��
    pq.push({0, passingNode});
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDist>distTable1[currentNode])
            continue;
        for (auto edge:adjList[currentNode]) {
            int nextDist = currentDist+edge.first;
            int nextNode = edge.second;
            if (nextDist<distTable1[nextNode]) {
                distTable1[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        } //edge loop
    } //while loop
}

int main() {
    input();
    dijkstra0();
    dijkstra1();
    int dist0 = distTable0[numNodes]; //�ǿ츦 ����ġ�� �ٷ� ���꿡 �� �� �ּ� �Ÿ�
    int dist1 = distTable0[passingNode] + distTable1[numNodes]; //�ǿ��� ��ġ�� �����ϰ� ���꿡 �� �� �ּ� �Ÿ�
    if (dist1<=dist0) {
        printf("SAVE HIM");
    } else {
        printf("GOOD BYE");
    }
    return 0;
}
