#include<iostream>

using namespace std;

int D[301][2]; //D[i][0]: �ٷ� ���� ����� ���� �ʰ� i ��ܱ��� ������ ���� �� �ִ� ������ �ִ�ġ, D[i][1]: �ٷ� ���� ����� ��� i ��ܱ��� ���� �� ���� �� �ִ� ������ �ִ�ġ
int pointArr[301]; //i ����� ���� �� ���� �� �ִ� ����


int main() {
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> pointArr[i];
    }
    //�ʱⰪ ���ϱ�
    D[1][0] = pointArr[1];
    D[2][0] = pointArr[2];
    D[2][1] = pointArr[1]+pointArr[2];
    D[3][0] = D[1][0] + pointArr[3];
    D[3][1] = D[2][0] + pointArr[3];
    //��ȭ��
    for (int i=4; i<=N; i++) {
        D[i][0] = max(D[i-2][0], D[i-2][1])+pointArr[i]; //�ٷ� ���� ����� ���� �ʴ� ��쿡�� �� ��� �� ����� ���� �� 0 ������ 1 ���� ���� �����Ѵ�.
        D[i][1] = D[i-1][0]+pointArr[i]; //�ٷ� ���� ����� ��� ��쿡�� �� ��� �� ����� ���� �� 0 ������ �����Ѵ�.
    } //i loop
    cout << max(D[N][0], D[N][1]); //N ��° ��ܱ��� ���� �� �޴� ������ 0������ 1���� �� �ִ�ġ�� ������.
    return 0;
}