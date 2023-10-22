#include <iostream>


using namespace std;

//dpCache[i][j]: i �ڸ� �ڿ����� ���� j��  ������ ��ܼ��� ���� (1000000000 ���� ���� ������)
long long dpCache[102][10];


int main() {
    int N; // �ڸ� ����
    cin >> N;

    //���̽� ���̽�
    for (int j=1; j<=9; j++)
        dpCache[1][j] = 1;

    //��ȭ��
    for (int i=2; i<=N; i++) {
        dpCache[i][0] = dpCache[i-1][1]; //0���� ������ i+1 �ڸ� ��ܼ��� ������� 1�� ������ i �ڸ� ��ܼ� �ڿ� 0�� ���δ�.
        for (int j=1; j<=8; j++) {
            dpCache[i][j] = (dpCache[i-1][j-1]+dpCache[i-1][j+1]) % 1000000000; //j�� ������ i+1 �ڸ� ��ܼ��� ������� j-1 �Ǵ� j+1�� ������ i �ڸ� ��ܼ� �ڿ� 0�� ���δ�.
            //���� ��� 4�� ������ 10�ڸ� ��ܼ��� ������� 3 �Ǵ� 5�� ������ 9�ڸ� ��ܼ� �ڿ� 4�� ���δ�.
        }
        dpCache[i][9] = dpCache[i-1][8]; //9�� ������ i+1 �ڸ� ��ܼ��� ������� 8�� ������ i�ڸ� ��ܼ� �ڿ� 9�� ���δ�.
    }

    long long result = 0;
    for (int j=0; j<=9; j++) { //�ڸ��� N�� ���� 0-9�� ������ ��ܼ��� ������ ���Ѵ�.
        result = (result+dpCache[N][j])%1000000000;
    }

    cout << result;
    return 0;
}
