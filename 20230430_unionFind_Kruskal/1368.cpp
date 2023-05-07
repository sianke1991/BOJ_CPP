#include <bits/stdc++.h>

using namespace std;

/*
예를 들어 논이 4개가 있다고 한다면, 4개의 논에 [우물] 1개를 포함하여
총 5개의 노드가 있는 그래프를 생각한다.
모든 논이 직, 간접적으로 우물과 연결되면 모든 논에 물이 대지는 것이다.
따라서 논 노드 및 우물 노드로 이루어진 그래프로 MST를 생성하면 모든 논에 물을 대기 위한 최소 비용을 구할 수 있다.
*/

vector<tuple<long long, int, int>> edges; //그래프에 있는 간선 {비용, 출발노드, 도착노드}
int parentOf[301]; //최소 신장 트리에 포함된 간선의 부자 관계를 저장한 배열

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
    int numPaddies; //논의 개수 (실제 고려하는 그래프의 노드 개수는 numPaddies+1이다.
    cin >> numPaddies;
    //최초에 최소 신장 트리에 간선은 없으므로 각 노드의 부모는 자기 자신이 된다.
    for (int i=0; i<=numPaddies; i++) {
        parentOf[i] = i;
    }
    //우물을 파기 위해 필요한 비용을 edges에 적는다.
    for (int i=1; i<=numPaddies; i++) {
        int price;
        cin >> price;
        edges.push_back({price, i, 0});
        edges.push_back({price, 0, i});
    }

    for (int i=1; i<=numPaddies; i++) {
        for (int j=1; j<=numPaddies; j++) {
            int price;
            cin >> price;
            if (i==j) continue;
            edges.push_back({price, i, j});
        } //j loop, 도착노드 루프
    } //i loop, 출발노드 루프

    sort(edges.begin(), edges.end());
    long long sumWeight = 0; //최소 신장 트리 가증치
    int numSelectedEdges = 0; //현재 최소 신장 트리에 들어간 간선의 개수

    for (tuple<long long, int, int> e:edges) {
        int currentNodeA = get<1>(e); //이번에 살필 간선이 연결하는 두 노드 중 하나 (tuple에서 특정 위치의 값을 가져올 때는 get<idx> 함수를 사용한다.)
        int currentNodeB = get<2>(e); //이번에 살필 간선이 연결하는 두 노드 중 하나
        long long currentWeight = get<0>(e); //이번에 살필 간선의 가중치
        if (areDifferentGroup(currentNodeA, currentNodeB)) { //이번에 살필 간선이 연결하는 두 노드가 [아직 연결되지 않은 노드]인 경우
            sumWeight+=currentWeight;
            numSelectedEdges++;
        }
        if (numSelectedEdges==numPaddies) break; //최소 신장 트리에 numPaddies 개수의 간선이 들어가면 반복을 종료한다.
                                                //(그래프에는 (numPaddies+1) 만큼의 노드가 있으므로 생성될 최소 신장 트리에는 numPaddies 만큼의 간선이 들어가야 한다.)
    }
    cout << sumWeight;
    return 0;
}
