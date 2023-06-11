#include <bits/stdc++.h>

using namespace std;
const int INFINITE_COST = 100000000; //���� �󿡼� �� ������ ����� 100000�� �ʰ����� �ʰ�, ���� ������ 100�� �ʰ����� �����Ƿ�
                                      //�� ���ÿ��� �ٸ� ���÷� ���µ� �ʿ��� �� ����� 10000000�� �ʰ����� �ʴ´�.
                                      //��, 100000000�� ������ ������� ����� �� �ִ�.
                                      //INFINITE_COST�� �� �� ���ϴ��� �����÷ΰ� �߻����� �ʾƾ� �Ѵ�.

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int main() {
    int numCities;
    int numBuses;

    cin >> numCities;
    cin >> numBuses;

    //��� ���� �ֿ� ���ؼ� �ִ� ����� ����ؾ� �ϹǷ� �÷��̵� �˰����� �����ϸ� �ȴ�.
    //�÷��̵� �˰����� �� ���� �� ����� ��ȸ�ϴ� ��찡 �����Ƿ� �׷����� ǥ���ϴµ� ��������Ʈ�� ����ϴ� �� ���� ��������� ����ϴ� ���� �����ϴ�.

    //������� ���� (�밢������ 0����, ������ ������ ���Ѵ�� �����Ѵ�.)
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
        adjMatrix[s][t] = Min(adjMatrix[s][t], p); //���� �Է¹��� ���� ������ �Է¹��� ������ ���� ��� ��������� �����Ѵ�. (s���� t�� ���� ����� ������ �־��� ���� �ִ�.)
    }

    for (int k=0; k<numCities+1; k++) { //k ��带 �����ϴ� ����� ����Ѵ�. //�÷��̵� �˰����� "�� �ܰ�"�ν�, �� ���� ��� ������ ���� �ٱ� ������ �Ǿ�� �Ѵ�.
        for (int s=0; s<numCities+1; s++) {
            for (int t=0; t<numCities+1; t++) {
                adjMatrix[s][t] = Min(adjMatrix[s][t], adjMatrix[s][k]+adjMatrix[k][t]); //������ ���� ���� k ��带 ������ �� �ʿ��� ����� ���Ͽ� ������ �����Ѵ�.
            } //t loop (���� ��� ����)
        } //s loop (���� ��� ����)
    } //k loop (�����ϴ� ��� ����)

    for (int i=1; i<numCities+1; i++) {
        for (int j=1; j<numCities+1; j++) {
            cout << (adjMatrix[i][j]>=INFINITE_COST ? 0 : adjMatrix[i][j]) << ' '; //�� ��忡�� �ٸ� ���� �� �� ���� ����� INFINITE_COST�� �ʰ��ϴ� ��� �� ���� ���� ������� ���� ������ �����Ѵ�.
        }
        cout << '\n';
    }

    return 0;
}
