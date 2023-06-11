#include <bits/stdc++.h>

using namespace std;

const int INFINITE_PRICE = 100000000;
int priceMatrix[101][101]; //priceMatrix[s][t]: s���� �����Ͽ� t�� �����ϴµ� �ʿ��� ���
                            //priceMatrix[s][t]�� �ʱ�ȭ
                            //priceMatrix[s][t] = 0 if s==t, input value if s and t are connected directly, INFINITE_PRICE otherwise
int nxtMatrix[101][101]; //nxtMatrix[s][t]: s���� �����Ͽ� t�� ������ �� s���� ������ ���
                            //nxtMatrix[s][t]�� �ʱ�ȭ
                            //nxtMatrix[s][t] = t if s and t (s!=t) are connected directly, -1 otherwise
string pathMatrix[101][101]; //pathMatrix[s][t]: s���� �����Ͽ� t�� ������ �� ���ľ� �� ��带 �������� �����Ͽ� �ۼ��� ���ڿ�
                            //pathMatrix�� �� ���Ҵ� �� ���ڿ�("")�� �ʱ�ȭ �ǰ�, �� ���� �ʱⰪ���� �״�� ����Ѵ�.
int pathLengthMatrix[101][101]; //pathLengthMatrix[s][t]: s���� �����Ͽ� t�� ������ �� ���ľ� �� ����� ����
                                //pathLengthMatrix�� �� ���Ҵ� 0���� �ʱ�ȭ �ǰ�, �� ���� �ʱⰪ���� �״�� ����Ѵ�.
//nxtMatrix�� �ϼ��� ������ pathMatrix�� pathLengthMatrix�� �ϼ��� �� �ִµ�, ����Լ��� ����� ���̹Ƿ�,
//�Լ� ���� �� nxtMatrix�� �� ���ҿ� ���� �����ϱ� ���� nxtMatrix�� ���������� ���� �ʿ䰡 �ִ�.

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

/**
 * from���� to�� ���� ���� ���ľ� �� ��θ� ��ȯ�Ѵ�.<br/>
 * ��� �� pathMatrix�� ������ �����ϰ� �����Ѵ�.<br/>
 * �� �Լ� ȣ�� �� priceMatrix, nxtMatrix�� ���� �ϼ��Ǿ��־�� �Ѵ�.
 */
string path(int from, int to) {
    if (from==to || priceMatrix[from][to]>=INFINITE_PRICE) { //from���� to�� ���� ���� �Ұ����� ��� �ƹ��� ��� ȣ���� �ϴ��� ��� ȣ���� ������� �ʴ´�.
                                                            //��, from���� to�� ���� ���� �Ұ����� ��� ��� ȣ���� ���ƾ� �Ѵ�. from���� to�� ���� ���� �Ұ�������
                                                            //���� �Ǵ��� priceMatrix[from][to]�� ����Ͽ� �� �� �ִ�. ��, priceMatrix[from][to]�� INFINITE_PRICE �̻��� ���
                                                            //from���� to�� ���� ���� �Ұ����ϴٰ� �Ǵ��� �� �ִ�.
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
    int numCities, numBuses;
    cin >> numCities;
    cin >> numBuses;

    //priceMatrix, nxtMatrix �ʱ�ȭ
    for (int i=1; i<=numCities; i++) {
        for (int j=1; j<=numCities; j++) {
            priceMatrix[i][j] = INFINITE_PRICE;
            nxtMatrix[i][j] = -1;
        } //j loop
        priceMatrix[i][i] = 0;
    } //i loop

    //���� ���� �Է�
    for (int i=0; i<numBuses; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        priceMatrix[s][t] = Min(priceMatrix[s][t], p); //s���� �����Ͽ� t�� �����ϴ� ����� ���� �� �Էµ� �� �����Ƿ�, �Է°� �� �ּҸ� priceMatrix[s][t]�� �ִ´�.
        nxtMatrix[s][t] = t; //s���� t��尡 ���� ����Ǿ����Ƿ� nxtMatrix[s][t]�� t�� �����Ѵ�.
    }

    //�÷��̵� �˰��� ����
    //��� ��� ��(s, t)�� ���ؼ� s���� ����Ͽ� t�� �����ϴµ� �ʿ��� ����� ���ؾ� �ϹǷ� �÷��̵� �˰����� ����Ѵ�.
    for (int k=1; k<=numCities; k++) { //k�� �����ϴ� ��츦 ����Ѵ�.
        for (int s=1; s<=numCities; s++) {
            for (int t=1; t<=numCities; t++) {
                if (priceMatrix[s][t]>priceMatrix[s][k]+priceMatrix[k][t]) { //���� s���� t�� ���µ� k�� �����ϴ� ���� �� ȿ������ ���-
                    priceMatrix[s][t] = priceMatrix[s][k]+priceMatrix[k][t]; //k�� ������ �� ������� �����Ѵ�.
                    nxtMatrix[s][t] = nxtMatrix[s][k]; //k�� ������ �� ���� ���� �����Ѵ�.
                }
            } //t loop (���� ��� ����)
        } //s loop (���� ��� ����)
    } //k loop (���� ��� ����)

    //��� �迭 ����
    for (int s=1; s<=numCities; s++) {
        for (int t=1; t<=numCities; t++) {
            path(s, t);
        } //t loop (���� ��� ����)
    } //s loop (���� ��� ����)

    //��� ��� ���
    for (int s=1; s<=numCities; s++) {
        for (int t=1; t<=numCities; t++) {
            cout << (priceMatrix[s][t]>=INFINITE_PRICE ? 0 : priceMatrix[s][t]) << ' ';
        } //t loop (���� ��� ����)
        cout << '\n';
    } //s loop (���� ��� ����)

    //��� ���
    for (int s=1; s<=numCities; s++) {
        for (int t=1; t<=numCities; t++) {
            cout << pathLengthMatrix[s][t] << ' ' << pathMatrix[s][t] << '\n';
        } //t loop (���� ��� ����)
    } //s loop (���� ��� ����)

    return 0;
}
