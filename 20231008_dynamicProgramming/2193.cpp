#include <iostream>

using namespace std;

//dpCache[N][bit]: N�ڸ� �������� ���� (���ʿ���) N��° ��Ʈ�� bit�� ��ģ���� ����� ��
long long dpCache[92][2];

int main() {
    int N;
    cin >> N;
    dpCache[1][0] = 0;
    dpCache[1][1] = 1;

    for (int i=2; i<=N; i++) {
        dpCache[i][0] = dpCache[i-1][0] + dpCache[i-1][1]; //�ٷ� �� �ڸ��� 0�̴�, 1�̴� ��� ���� �ش� �ڸ��� 0�� �� �� �ִ�.
        dpCache[i][1] = dpCache[i-1][0]; //�ٷ� �� �ڸ��� 0�̾�� �ش� �ڸ��� 1�� �� �� �ִ�.
    }
    cout << dpCache[N][0] + dpCache[N][1];
    return 0;
}
