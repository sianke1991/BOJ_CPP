#include <bits/stdc++.h>

using namespace std;

//timeReq[i]: i��° ���� �ϴµ� �ҿ�Ǵ� �ð� (day)
int timeReq[16];
//payRcv[i]: i��° ���� �� �� ���� �� �ִ� ����
int payRcv[16];
//dpCache[i]: i��° ��, i��° ���� �ϱ� ���� ���� ������ �ִ�ġ
int dpCache[16];

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    int N; //��¥ ��
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> timeReq[i];
        cin >> payRcv[i];
    } //i loop

    for (int i=0; i<N; i++) {
        for (int j=i+timeReq[i]; j<=N; j++) { //i ��° ���� ������ �� ������ i+timeReq[i] ��° ���� �޴� ������ ����Ѵ�.
            //������ ���� ����Ǵ� �ϵ� ������ ���� �� �����Ƿ� dpCache[N]�� ���� �����Ѵ�.
            //���� ��� ��� 2�� ���� 2�� �ɸ��� ���� ������ ��� �� ������ dpCache[N]�� ��������.
            dpCache[j] = max(dpCache[j], dpCache[i]+payRcv[i]); //i ��° ���� �ϸ� ���� ������ dpCache[i]+payRcv[i]�̹Ƿ� �� ���� dpCache[j]�� ���Ͽ� �ִ�ġ�� dpCache�� �����Ѵ�.
        } //j loop
    } //i loop

    cout << dpCache[N];

    return 0;
}
