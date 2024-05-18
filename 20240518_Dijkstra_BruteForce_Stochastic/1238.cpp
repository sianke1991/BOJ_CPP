#include <stdio.h>
#define INFINITY 100000000

//���� ���: adjMatrix[from][to]�� from ��忡�� to ���� ���� ������ �ҿ�Ǵ� �ð��� �ǹ��Ѵ�.
// adjMatrix[from][to]�� 0�� ��� from ��忡�� to ���� ���� ������ ������ �ǹ��Ѵ�.
//int adjMatrix[1001][1001];
// ��� ����
int numNodes;
// ���� ����
int numEdges;
// ��� ���: distTable[from][to]�� from ��忡�� to ���� �� �� �ɸ��� �ð��� �ּҰ��� �ǹ��Ѵ�.
int distTable[1001][1001];
// ������: ��� �л��� ���̱�� �� ����� ��ȣ
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

    // ���� �Է�
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
