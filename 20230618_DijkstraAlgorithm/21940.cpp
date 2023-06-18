#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;
int startingNodes[200]; //준형이와 친구들이 살고 있는 각 도시의 번호
int adjMatrix[201][201];
int maxTimesRequired[201];

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int Max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

/**
 * 집결지 gatherNode에 따른
 * 준형이와 친구들의 왕복시간 중 최대값을 계산하여 반환한다.
 * 이 함수를 호출하기 전 adjMatrix는 구성이 완료되어야 한다.
 */
int MaxTimeRequired(int gatherNode) {
    int result = 0;
    for (int startNode:startingNodes) {
        result = Max(result, adjMatrix[startNode][gatherNode]+adjMatrix[gatherNode][startNode]);
    }
    return result;
}



int main() {
    int numCities, numRoads;
    cin >> numCities >> numRoads;

    //인접 행렬 초기화
    for (int i=1; i<=numCities; i++) {
        for (int j=1; j<=numCities; j++) {
            adjMatrix[i][j] = INF;
        } //j loop
        adjMatrix[i][i] = 0;
    } //i loop


    //간선 정보 입력
    for (int i=0; i<numRoads; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        adjMatrix[s][t] = Min(adjMatrix[s][t], p); //방향 그래프이므로 adjMatrix[t][s]는 값 설정을 하지 않는다.
    } //i loop


    //플로이드 알고리즘 적용
    for (int k=1; k<=numCities; k++) {
        for (int s=1; s<=numCities; s++) {
            for (int t=1; t<=numCities; t++) {
                if (adjMatrix[s][t]>adjMatrix[s][k]+adjMatrix[k][t]) {
                    adjMatrix[s][t] = adjMatrix[s][k]+adjMatrix[k][t];
                }
            } //t loop (도착 노드 루프)
        } //s loop (시작 노드 루프)
    } //k loop (경유 노드 루프)

    //각 사람들이 살고 있는 도시 정보 입력
    int numPeople;
    cin >> numPeople;
    for (int i=0; i<numPeople; i++) {
        cin >> startingNodes[i];
    }

    int optTimeRequired = INF;
    //집결지에 따른 왕복 시간 계산
    for (int i=1; i<=numCities; i++) {
        int timeRequired = MaxTimeRequired(i);
        maxTimesRequired[i] = timeRequired;
        optTimeRequired = Min(optTimeRequired, timeRequired);
    } //i loop

    //집결지 출력
    for (int i=1; i<=numCities; i++) {
        if (maxTimesRequired[i]==optTimeRequired) {
            cout << i << ' ';
        }
    }

    return 0;
}
