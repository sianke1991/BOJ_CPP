#include <bits/stdc++.h>
#include <stdio.h>


/*
M개의 간선 중 N-1 개를 택해서 최소 신장 트리를 만든다.
이 문제에서 키위새는 가지 디저트로 하루를 연명해야 하므로
간선 내 노점의 오픈 날짜는 해당 간선의 "비용"으로 간주할 수 있다.
최소 신장 트리에 포함된 간선을 하나 씩 탐색하면서 연명에 실패하게 되는
최소 일자를 찾는다.
*/
using namespace std;

struct Edge {
    int day;
    int from;
    int to;
};

bool cmp(Edge e0, Edge e1) {
    return e0.day<e1.day;
}

int parentOf[100001];

int rootOf(int node) {
    while (parentOf[node]!=node) {
        node = parentOf[node];
    }
    return parentOf[node];
}

bool checkSameGroup(int node0, int node1) {
    int rootOfNode0 = rootOf(node0);
    int rootOfNode1 = rootOf(node1);
    //printf("checkSameGroup node0: %d(%d), node1: %d(%d)\n", node0, rootOfNode0, node1, rootOfNode1);
    return rootOfNode0==rootOfNode1;
}

void unionize(int node0, int node1) {
    int rootOfNode0 = rootOf(node0);
    int rootOfNode1 = rootOf(node1);
    if (rootOfNode0<rootOfNode1) {
        parentOf[rootOfNode1] = rootOfNode0;
    } else {
        parentOf[rootOfNode0] = rootOfNode1;
    }
}

int main() {
    int numNodes;
    int numEdges;
    scanf("%d %d", &numNodes, &numEdges);
    vector<Edge> edges;
    for (int i=0; i<numEdges; i++) {
        int from, to, day;
        scanf("%d %d %d", &from, &to, &day);
        edges.push_back({day, from, to});
    }
    for (int i=1; i<=numNodes; i++) {
        parentOf[i] = i;
    }
    sort(edges.begin(), edges.end(), cmp);
    int currentDay = 0;
    for (Edge edge:edges) {
        if (checkSameGroup(edge.from, edge.to)) //이 간선은 사용하지 않을 것이다,
            continue;
        currentDay++;
        if (currentDay<edge.day) {
            printf("%d", currentDay);
            return 0;
        } else {
            unionize(edge.from, edge.to);
        }
    } //edge loop
    printf("%d", currentDay+1);
    return 0;
}
