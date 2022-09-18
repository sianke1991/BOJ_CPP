#include <iostream>
using namespace std;

int N; //����� ����
int honeyArr[100000] = {0};
int sumArr[100000]   = {0}; //�ε��� 0���� ���� �� eg. sumArr[3]�� �ε��� 0, 1, 2, 3�� ���� ��
int maxTotal = -1;

//������ ��� ��ġ�� ���: �� ���� �� ���� ��ġ�ؾ� ���� �ִ�� �� �� �ִ�.
//�� ���� ��ġ�� ������Ű�� ������ ��ġ�� ������Ѽ� (���� ����) �ִ�ġ�� ��ȸ�Ѵ�.
void updateMaxTotalBTB(int i) {
    int result = 0;
    result += sumArr[i]-sumArr[0];
    result += sumArr[N-2]-sumArr[i-1];
    if (maxTotal < result) maxTotal = result;
}

//������ ���� ���� ��ġ�� ���: �ٸ� �� �� �� �ϳ��� �ٸ��� ���� ��ġ�ؾ� ���� �ִ�� �� �� �ִ�.
//�� �� �� ��� ���� ��ġ�� ������Ѽ� �ִ�ġ�� ��ȸ�Ѵ�.
void updateMaxTotalBBT(int i) {
    int result = 0;
    result += sumArr[N-1]-sumArr[0] - honeyArr[i];
    result += sumArr[N-1]-sumArr[i];
    if (maxTotal < result) maxTotal = result;
}

void updateMaxTotalTBB(int i) {
    int result = 0;
    result += sumArr[i-1];
    result += sumArr[N-2] - honeyArr[i];
    if (maxTotal < result) maxTotal = result;
}

int main() {
    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> honeyArr[i];
    }
    int partialSum = 0;
    for (int i=0; i<N; i++) {
        partialSum += honeyArr[i];
        sumArr[i] = partialSum;
    }

    //case0. BTB
    for (int i=1; i<N-1; i++) {
        updateMaxTotalBTB(i);
    }

    //case1. BBT
    for (int i=1; i<N-1; i++) {
        updateMaxTotalBBT(i);
    }

    //case2. TBB
    for (int i=1; i<N-1; i++) {
        updateMaxTotalTBB(i);
    }

    cout << maxTotal;
    return 0;
}
