#include <bits/stdc++.h>

using namespace std;
const int INFINITE_COST = 100000000; //문제 상에서 한 간선의 비용은 100000을 초과하지 않고, 도시 개수는 100을 초과하지 않으므로
                                      //한 도시에서 다른 도시로 가는데 필요한 총 비용은 10000000을 초과하지 않는다.
                                      //즉, 100000000을 무한의 비용으로 사용할 수 있다.
                                      //INFINITE_COST를 두 번 더하더라도 오퍼플로가 발생하지 않아야 한다.

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int main() {
    int numCities;
    int numBuses;

    cin >> numCities;
    cin >> numBuses;

    //모든 정점 쌍에 대해서 최단 비용을 출력해야 하므로 플로이드 알고리즘을 적용하면 된다.
    //플로이드 알고리즘은 두 정점 간 비용을 조회하는 경우가 많으므로 그래프를 표현하는데 인접리스트를 사용하는 것 보다 인접행렬을 사용하는 것이 용이하다.

    //인접행렬 구성 (대각성분은 0으로, 나머지 성분은 무한대로 설정한다.)
    int adjMatrix[numCities+1][numCities+1];
    for (int i=0; i<numCities+1; i++) {
        for (int j=0; j<numCities+1; j++) {
            adjMatrix[i][j] = INFINITE_COST;
        } //j loop
        adjMatrix[i][i] = 0;
    } //i loop

    for (int i=0; i<numBuses; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        adjMatrix[s][t] = Min(adjMatrix[s][t], p); //새로 입력받은 값이 기존에 입력받은 값보다 낮은 경우 인접행렬을 갱신한다. (s에서 t로 가는 비용이 여러번 주어질 수도 있다.)
    }

    for (int k=0; k<numCities+1; k++) { //k 노드를 경유하는 방법을 고려한다. //플로이드 알고리즘의 "각 단계"로써, 이 경유 노드 루프가 가장 바깥 루프가 되어야 한다.
        for (int s=0; s<numCities+1; s++) {
            for (int t=0; t<numCities+1; t++) {
                adjMatrix[s][t] = Min(adjMatrix[s][t], adjMatrix[s][k]+adjMatrix[k][t]); //기존에 계산된 비용과 k 노드를 경유할 때 필요한 비용을 비교하여 최적을 선택한다.
            } //t loop (도착 노드 루프)
        } //s loop (시작 노드 루프)
    } //k loop (경유하는 노드 루프)

    for (int i=1; i<numCities+1; i++) {
        for (int j=1; j<numCities+1; j++) {
            cout << (adjMatrix[i][j]>=INFINITE_COST ? 0 : adjMatrix[i][j]) << ' '; //한 노드에서 다른 노드로 갈 때 들어가는 비용이 INFINITE_COST를 초과하는 경우 두 노드는 서로 연결되지 않은 것으로 간주한다.
        }
        cout << '\n';
    }

    return 0;
}
