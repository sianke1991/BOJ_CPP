#include <stdio.h>
#define INFINITY 100000000

//인접 행렬: adjMatrix[from][to]는 from 노드에서 to 노드로 가는 간선에 소요되는 시간을 의미한다.
// adjMatrix[from][to]가 0인 경우 from 노드에서 to 노드로 가는 간선이 없음을 의미한다.
//int adjMatrix[1001][1001];
// 노드 개수
int numNodes;
// 간선 개수
int numEdges;
// 비용 행렬: distTable[from][to]는 from 노드에서 to 노드로 갈 때 걸리는 시간의 최소값을 의미한다.
int distTable[1001][1001];
// 집결지: 모든 학생이 모이기로 한 노드의 번호
int gatherPoint;


void init() {
    for (int s=1; s<=numNodes; s++) {
        for (int t=1; t<s; t++) distTable[s][t] = INFINITY;
        for (int t=s+1; t<=numNodes; t++) distTable[s][t] = INFINITY;
    }
}

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    scanf("%d %d %d", &numNodes, &numEdges, &gatherPoint);
    init();

    // 간선 입력
    for (int i=0; i<numEdges; i++) {
        int from, to, dist;
        scanf("%d %d %d", &from, &to, &dist);
        distTable[from][to] = dist;
    } //i loop

    for (int k=1; k<=numNodes; k++) {
        for (int s=1; s<=numNodes; s++) {
            for (int t=1; t<=numNodes; t++) {
                if (distTable[s][t]>distTable[s][k]+distTable[k][t])
                    distTable[s][t] = distTable[s][k]+distTable[k][t];
            } //t loop
        } //s loop
    } //k loop

    int result = 0;
    for (int i=1; i<=numNodes; i++) {
        result = max(result, distTable[i][gatherPoint] + distTable[gatherPoint][i]);
    }

    printf("%d", result);
    return 0;
}
