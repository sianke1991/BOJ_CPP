#include <bits/stdc++.h>
using namespace std;

tuple<long long, int, int> edgesInGraph[100005]; //그래프에 있는 간선
//pair<int, int> edgesInMST[10000]; //최소 신장 트리에 있는 간선
int parentOf[100005]; //최소 신장 트리에 포함된 간선의 부자 관계를 저장한 배열
int rootOf[100005]; //최소 신장 트리에 포함된 각 노드의 시조를 저장한 배열

int getRootOf(int node) {
    if (parentOf[node]==node) {
        return node;
    } else {
        return parentOf[node];
    }
}

bool areSameGroup(int nodeA, int nodeB) {
    int rootNodeA = getRootOf(nodeA);
    rootOf[nodeA] = rootNodeA;
    int rootNodeB = getRootOf(nodeB);
    rootOf[nodeB] = rootNodeB;
    return rootNodeA==rootNodeB;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for (int i=1; i<=numEdges; i++) {
        parentOf[i] = i; //최초에 최소 신장 트리에 간선은 없으므로 각 노드의 부모는 자기 자신이 된다.
    }
    for (int i=0; i<numEdges; i++) {
        int nodeA, nodeB;
        long long weight;
        cin >> nodeA >> nodeB >> weight;
        edgesInGraph[i] = {weight, nodeA, nodeB};
    }
    sort(edgesInGraph, edgesInGraph+numEdges);
    long long MSTweight = 0; //최소 신장 트리 가중치
    int numSelectedEdges = 0; //현재 최소 신장 트리에 들어간 간선의 개수

    for (int i=0; i<numEdges; i++) {
        tuple<int, int, int> currentEdge = edgesInGraph[i];
        int currentNodeA = get<1>(currentEdge); //이번에 살필 간선이 연결하는 두 노드 중 하나 (tuple에서 특정 위치의 값을 가져올 때는 get<idx> 함수를 사용한다.)
        int currentNodeB = get<2>(currentEdge); //이번에 살필 간선이 연결하는 두 노드 중 하나
        long long currentWeight = get<0>(currentEdge); //이번에 살필 간선의 가중치
        if (!(areSameGroup(currentNodeA, currentNodeB))) { //이번에 살필 간선이 연결하는 두 노드가 [아직 연결되지 않은 노드인 경우]
            MSTweight+=currentWeight; //해당 간선을  MST에 포함시키고-
            numSelectedEdges++;
            int rootNodeA = rootOf[currentNodeA];
            int rootNodeB = rootOf[currentNodeB];
            if (rootNodeA<=rootNodeB) {
                parentOf[currentNodeB] = currentNodeA; //해당 두 노드는 친자 관계를 맺는다.
            } else {
                parentOf[currentNodeA] = currentNodeB; //해당 두 노드는 친자 관계를 맺는다.
            }

            //parentOf[max(currentNodeA, currentNodeB)] = min(currentNodeA, currentNodeB); //해당 두 노드는 친자 관계를 맺는다.
        }
        if (numSelectedEdges==numNodes-1) break; //MST에 포함된 간선의 개수가 (노드개수-1)에 도달하면 반복을 종료한다.
    }

    cout << MSTweight;
    return 0;
}
