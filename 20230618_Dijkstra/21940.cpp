#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;
int startingNodes[200]; //�����̿� ģ������ ��� �ִ� �� ������ ��ȣ
int adjMatrix[201][201];
int maxTimesRequired[201];

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int Max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

/**
 * ������ gatherNode�� ����
 * �����̿� ģ������ �պ��ð� �� �ִ밪�� ����Ͽ� ��ȯ�Ѵ�.
 * �� �Լ��� ȣ���ϱ� �� adjMatrix�� ������ �Ϸ�Ǿ�� �Ѵ�.
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

    //���� ��� �ʱ�ȭ
    for (int i=1; i<=numCities; i++) {
        for (int j=1; j<=numCities; j++) {
            adjMatrix[i][j] = INF;
        } //j loop
        adjMatrix[i][i] = 0;
    } //i loop


    //���� ���� �Է�
    for (int i=0; i<numRoads; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        adjMatrix[s][t] = Min(adjMatrix[s][t], p); //���� �׷����̹Ƿ� adjMatrix[t][s]�� �� ������ ���� �ʴ´�.
    } //i loop


    //�÷��̵� �˰��� ����
    for (int k=1; k<=numCities; k++) {
        for (int s=1; s<=numCities; s++) {
            for (int t=1; t<=numCities; t++) {
                if (adjMatrix[s][t]>adjMatrix[s][k]+adjMatrix[k][t]) {
                    adjMatrix[s][t] = adjMatrix[s][k]+adjMatrix[k][t];
                }
            } //t loop (���� ��� ����)
        } //s loop (���� ��� ����)
    } //k loop (���� ��� ����)

    //�� ������� ��� �ִ� ���� ���� �Է�
    int numPeople;
    cin >> numPeople;
    for (int i=0; i<numPeople; i++) {
        cin >> startingNodes[i];
    }

    int optTimeRequired = INF;
    //�������� ���� �պ� �ð� ���
    for (int i=1; i<=numCities; i++) {
        int timeRequired = MaxTimeRequired(i);
        maxTimesRequired[i] = timeRequired;
        optTimeRequired = Min(optTimeRequired, timeRequired);
    } //i loop

    //������ ���
    for (int i=1; i<=numCities; i++) {
        if (maxTimesRequired[i]==optTimeRequired) {
            cout << i << ' ';
        }
    }

    return 0;
}
