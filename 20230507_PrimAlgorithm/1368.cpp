#include <bits/stdc++.h>

using namespace std;

/*
예를 들어 논이 4개가 있다고 한다면, 4개의 논에 [우물] 1개를 포함하여
총 5개의 노드가 있는 그래프를 생각한다.
모든 논이 직, 간접적으로 우물과 연결되면 모든 논에 물이 대지는 것이다.
따라서 논 노드 및 우물 노드로 이루어진 그래프로 MST를 생성하면 모든 논에 물을 대기 위한 최소 비용을 구할 수 있다.
*/

int main() {
    int numPaddies; //논의 개수 (실제 고려하는 그래프의 노드 개수는 numPaddies+1이다.
    cin >> numPaddies;
    vector<pair<int, int>> adjList[301]; //인접 리스트 {비용, 도착노드}
    for (int i=1; i<=numPaddies; i++) { //i 번째 논에 물을 대는 비용은 i번째 노드와 0번째 노드 사이의 비용과 같다.
        int price;
        cin >> price;
        adjList[i].push_back({price, 0});
        adjList[0].push_back({price, i});
    }
    for (int i=1; i<=numPaddies; i++) {
        for (int j=1; j<=numPaddies; j++) {
            int price;
            cin >> price;
            if (i==j) continue; //그래프에서 제 자리로 돌아오는 간선은 인접 리스트에 기록할 필요가 없다.
            adjList[i].push_back({price, j}); //한 간선을 두 번 입력해 주므로 이 단계에서 굳이 j출발 i도착 간선을 적을 필요가 없다.
        } //j loop (도착노드 루프)
    } //i loop (출발노드 루프)

    bool isNodeSelected[301]; //해당 노드가 MST에 포함되었는지 여부
    for (int i=0; i<301; i++) isNodeSelected[i] = false;
    //{비용, 출발노드, 도착노드}
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
    int numSelectedEdges = 0;
    long long sumPrices = 0;

    isNodeSelected[0] = true;
    for (pair<int, int> e:adjList[0]) {
        pq.push({e.first, 0, e.second});
    }

    while (numSelectedEdges<numPaddies) { //그래프에서 노드의 개수는 numPaddies+1이므로, MST에 들어있는 간선의 개수는 numPaddies가 되어야 한다.
        tuple<int, int, int> selectedEdge = pq.top();
        pq.pop();
        if (isNodeSelected[get<2>(selectedEdge)]) continue; //선택한 간선이 [이미 MST에 고려한 노드를 향하는] 간선일 경우-
        isNodeSelected[get<2>(selectedEdge)] = true;
        numSelectedEdges++;
        sumPrices += get<0>(selectedEdge);
        //cout << get<0>(selectedEdge) << ' ' << get<1>(selectedEdge) << ' ' << get<2>(selectedEdge) << '\n';

        for (pair<int, int> e:adjList[get<2>(selectedEdge)]) {
            //if (isNodeSelected[get<2>(selectedEdge)]) continue;
            pq.push({e.first, get<2>(selectedEdge), e.second});
        }
    }
    cout << sumPrices;
    return 0;
}
