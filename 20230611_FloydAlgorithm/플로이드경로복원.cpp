#include <bits/stdc++.h>

using namespace std;

const int INFINITE_DIST = 100000000;

int main() {
    int numNodes = 5;
    int numEdges = 14;

    int adjMatrix[numNodes+1][numNodes+1];
    int nxtMatrix[numNodes+1][numNodes+1]; //������̺� (ó������ ��� ���Ҹ� -1�� �����Ѵ�.)
    for (int i=1; i<=numNodes; i++) {
        for (int j=1; j<=numNodes; j++) {
            adjMatrix[i][j] = INFINITE_DIST;
            nxtMatrix[i][j] = -1;
        }
        adjMatrix[i][i] = 0;
    }

    adjMatrix[1][2] = 4; adjMatrix[2][1] = 4;
    nxtMatrix[1][2] = 2; nxtMatrix[2][1] = 1; //s�� t�� ���� ����� ��� nxtMatrix[s][t] = t�� �����Ѵ�.

    adjMatrix[1][3] = 1; adjMatrix[3][1] = 1;
    nxtMatrix[1][3] = 3; nxtMatrix[3][1] = 1;

    adjMatrix[1][4] = 1; adjMatrix[4][1] = 1;
    nxtMatrix[1][4] = 4; nxtMatrix[4][1] = 1;

    adjMatrix[2][5] = 8; adjMatrix[5][2] = 8;
    nxtMatrix[2][5] = 5; nxtMatrix[5][2] = 2;

    adjMatrix[3][4] = 3; adjMatrix[4][3] = 3;
    nxtMatrix[3][4] = 4; nxtMatrix[4][3] = 3;

    adjMatrix[3][5] = 15; adjMatrix[5][3] = 15;
    nxtMatrix[3][5] = 5; nxtMatrix[5][3] = 3;

    adjMatrix[4][5] = 6; adjMatrix[5][4] = 6;
    nxtMatrix[4][5] = 5; nxtMatrix[5][4] = 4;

    for (int k=1; k<=numNodes; k++) { //�����ؾ� �� ��� ����
        for (int s=1; s<=numNodes; s++) { //���� ���
            for (int t=1; t<=numNodes; t++) { //���� ���
                if (adjMatrix[s][t]>adjMatrix[s][k]+adjMatrix[k][t]) { //s���� t�� �� �� k ��带 �����ϴ� ���� �� ȿ������ ��
                    adjMatrix[s][t] = adjMatrix[s][k]+adjMatrix[k][t]; //s���� t�� �� �� k ��带 �����ϵ��� �����Ѵ�.
                    nxtMatrix[s][t] = nxtMatrix[s][k]; //s���� t�� �� �� k ��带 �����ϵ��� �����Ѵ�.
                }
            } //t loop (���� ��� ����)
        } //s loop (���� ��� ����)
    } //k loop (���� ��� ����)

    for (int i=1; i<=numNodes; i++) {
        for (int j=1; j<=numNodes; j++) {
            cout << nxtMatrix[i][j] << ' ';
        }
        cout << '\n';
    }

    //nxtTable ó�� ���
//      -1 2 3 4 4
//      1 -1 1 1 5
//      1 1 -1 1 1
//      1 1 1 -1 5
//      4 2 4 4 -1

    return 0;
}
