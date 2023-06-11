#include <bits/stdc++.h>

using namespace std;

const int INFINITE_DIST = 100000000;
const int numNodes = 5;
int adjMatrix[numNodes+1][numNodes+1];
int nxtMatrix[numNodes+1][numNodes+1];
string pathMatrix[numNodes+1][numNodes+1]; //pathMatrix[s][t]: s���� t�� ���� ���� ���ľ� �� ���
int pathLengthMatrix[numNodes+1][numNodes+1]; //pathLengthMatrix[s][t]: s���� t�� ���� ���� ������ ��� ����

/**
 * from���� to�� ���� ���� ���ľ� �� ��θ� ��ȯ�Ѵ�.<br/>
 * ��� �� pathMatrix�� ������ �����ϰ� �����Ѵ�.<br/>
 * �� �Լ� ȣ�� �� priceMatrix, nxtMatrix�� ���� �ϼ��Ǿ��־�� �Ѵ�.
 */
string path(int from, int to) {
    if (from==to || pathMatrix[from][to] >= INFINITE_DIST) { //from���� to�� ���� ���� �Ұ����� ��� �ƹ��� ��� ȣ���� �ϴ��� ��� ȣ���� ������� �ʴ´�.
                                                            //��, from���� to�� ���� ���� �Ұ����� ��� ��� ȣ���� ���ƾ� �Ѵ�. from���� to�� ���� ���� �Ұ�������
                                                            //���� �Ǵ��� adjMatrix[from][to]�� ����Ͽ� �� �� �ִ�. ��, adjMatrix[from][to]�� INFINITE_DIST �̻��� ���
                                                            //from���� to�� ���� ���� �Ұ����ϴٰ� �Ǵ��� �� �ִ�.
        pathMatrix[from][to] = "";
        return "";
    }
    if (pathMatrix[from][to]!="") { //from���� to�� ���� ��θ� �̹� ���� ��� pathMatrix�� ����� ���� �״�� ��ȯ�Ѵ�. (�޸������̼�)
        return pathMatrix[from][to];
    } else {
        int mid = nxtMatrix[from][to]; //���� ���
        if (mid==to) { //���� ��尡 ���� ���� ���� ��� from���� to�� ���� ���� ���� ���� ���� ���̴�. (��� ȣ�� ���� ����)
            pathMatrix[from][to] = to_string(from) + " " + to_string(to);
            pathLengthMatrix[from][to] = 2;
            return pathMatrix[from][to];
        } else { //���� ��尡 ���� ���� �ٸ� ��� from���� mid�� ���ļ� to�� ���� �Ѵ�. mid���� to�� ���� ��δ� ��� ȣ���� ���ؼ� ���Ѵ�.
            pathMatrix[from][to] = to_string(from) + " "  + path(mid, to); //mid�� path(mid, to)�� �Ϻ��̹Ƿ� to_string(mid)�� ���ϸ� �ȵȴ�.
            pathLengthMatrix[from][to] = 1 + pathLengthMatrix[mid][to]; //pathMatrix[from][to]�� pathMatrix[mid][to]�� �տ� from�� ���� ���̴�. ��, ��� ���̴�
                                                                        //pathLengthMatrix[from][to]�� pathLengthMatrix[mid][to] ���� 1 ū ���̴�.
            return pathMatrix[from][to];
        }
    }
}


int main() {

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

    cout << "=====nxtMatrix=======\n";
    for (int i=1; i<=numNodes; i++) {
        for (int j=1; j<=numNodes; j++) {
            cout << nxtMatrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=====nxtMatrix=======\n";

    for (int s=1; s<=numNodes; s++) {
        for (int t=1; t<=numNodes; t++) {
            path(s, t);
        } //t loop (���� ��� ����)
    } //s loop (���� ��� ����)
    for (int s=1; s<=numNodes; s++) {
        for (int t=1; t<=numNodes; t++) {
            cout << "from " << s << " to " << t << ": ";
            cout << pathLengthMatrix[s][t] << ' ' << pathMatrix[s][t] << '\n';
        }
    }

    return 0;
}
