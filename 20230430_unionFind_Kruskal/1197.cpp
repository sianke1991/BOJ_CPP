#include <bits/stdc++.h>
using namespace std;

tuple<long long, int, int> edgesInGraph[100005]; //그래프에 있는 간선
//pair<int, int> edgesInMST[10000]; //최소 신장 트리에 있는 간선
int parentOf[100005]; //최소 신장 트리에 포함된 간선의 부자 관계를 저장한 배열

/**
 * 재귀적 방법을 사용하여 입력받은 노드의 루트 노드를 찾는다.
 * 특정 노드에 대해 노드와 그의 부모 노드가 같을 때 까지 부모를 찾아 위로 올라간다.
 */
int rootOf(int node) {
    if (parentOf[node]==node) {
        return node;
    } else {
        return rootOf(parentOf[node]);
    }
}

/**
 * 두 노드를 입력받아,
 * 두 노드가 이어져 있다면 false를 반환한다.
 * 두 노드가 이어져 있지 않으면 두 노드가 연결되도록 처리 후 true를 반환한다.
 * 두 노드가 연결되도록 처리하기 위해선 두 노드의 루트 노드 간 친자 관계를 맺는다.
 * (두 노드간에 친자 관계를 맺을 필요 없이, 두 노드의 루트 노드간에 친자 관계를 맺는다.)
 *  => 이 처리를 하면 이후에 두 노드의 루트 노드는 동일하게 된다.
 */
bool areDifferentGroup(int nodeA, int nodeB) {
    int rootNodeA = rootOf(nodeA);
    int rootNodeB = rootOf(nodeB);
    if (rootNodeA==rootNodeB) return false; //두 노드가 연결된 경우-
    if (rootNodeA<=rootNodeB) {
        parentOf[rootNodeB] = rootNodeA; //두 노드가 연결되지 않은 경우 연결 처리-
    } else {
        parentOf[rootNodeA] = rootNodeB; //두 노드가 연결되지 않은 경우 연결 처리-
    }
    return true;
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
        tuple<long long, int, int> currentEdge = edgesInGraph[i];
        int currentNodeA = get<1>(currentEdge); //이번에 살필 간선이 연결하는 두 노드 중 하나 (tuple에서 특정 위치의 값을 가져올 때는 get<idx> 함수를 사용한다.)
        int currentNodeB = get<2>(currentEdge); //이번에 살필 간선이 연결하는 두 노드 중 하나
        long long currentWeight = get<0>(currentEdge); //이번에 살필 간선의 가중치
        if (areDifferentGroup(currentNodeA, currentNodeB)) { //이번에 살필 간선이 연결하는 두 노드가 [아직 연결되지 않은 노드]인 경우
            MSTweight+=currentWeight; //해당 간선을  MST에 포함시킨다.
            numSelectedEdges++;
        }
        if (numSelectedEdges==numNodes-1) break; //MST에 포함된 간선의 개수가 (노드개수-1)에 도달하면 반복을 종료한다.
    }

    cout << MSTweight;
    return 0;
}
