#include <iostream>

using namespace std;

//timeReq[i]: i��° ���� �ϴµ� �ҿ�Ǵ� �ð� (day)
int timeReq[1500001];
//payRcv[i]: i��° ���� �� �� ���� �� �ִ� ����
int payRcv[1500001];
//dpCache[i]: i��° ��, i��° ���� �ϱ� ���� ���� ������ �ִ�ġ
int dpCache[1500001];
//���� dp�� ������ ���������� dpCache�� �ִ�ġ
int localMax = 0;
int globalMax = 0;

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
        localMax = max(localMax, dpCache[i]);
        int j=i+timeReq[i]; //i ��° ���� ������ �� ������ i+timeReq[i] ��° ���� �޴� ������ ����Ѵ�.
        if (j>N) continue; //������ �Ѵ� ���� ����� �ʿ䰡 ����.
        dpCache[j] = max(dpCache[j], localMax+payRcv[i]);
        globalMax = max(globalMax, dpCache[j]);
    }

    cout << globalMax;

    return 0;
}
