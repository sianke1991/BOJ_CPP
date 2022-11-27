// ���̳��� ���α׷���
// ���� ���� ���� ������ ���� Ǭ �� �� ����� �̿��Ͽ� �־��� ������ �ذ��ϴ� �˰���

// 1. ���̺� �����ϱ�
// 2. ��ȭ�� ã��
// 3. �ʱⰪ ���ϱ�
// 4. �ݺ��� ���� �迭�� ä��������.

#include <iostream>

using namespace std;

// 1463 (1�� �����)
// 1. ���̺� �����ϱ�
// D[i] := i�� 1�� ����� ���� �����ؾ� �� �ּ� ���� Ƚ��
// 2. ��ȭ�� ã��
// D[12] ?
// D[12] = min(D[4]+1, D[6]+1, D[11]+1)
// 3. �ʱⰪ ���ϱ�
// D[1] = 0

int D[1000001];
int N;

int minVal(int val0) {
    return val0;
}
int minVal(int val0, int val1) {
    return min(val0, val1);
}
int minVal(int val0, int val1, int val2) {
    return min(min(val0, val1), val2);
}


/*
�� ����� ����ϸ� getD �Լ��� �ʹ� ���� ȣ���ϰ� �ȴ�.
int getD(int idx) {
    if (idx <= 1) {
        return 0;
    } else if (D[idx]!=0) {
        return D[idx];
    } else if (idx%6==0) {
        D[idx] = minVal(getD(idx/3)+1, getD(idx/2)+1, getD(idx-1)+1);
        return D[idx];
    } else if (idx%3==0) {
        D[idx] = minVal(getD(idx/3)+1, getD(idx-1)+1);
        return D[idx];
    } else if (idx%2==0) {
        D[idx] = minVal(getD(idx/2)+1, getD(idx-1)+1);
        return D[idx];
    } else {
        D[idx] = getD(idx-1)+1;
        return D[idx];
    }
}
*/

int getD(int idx) {
    for (int i=2; i<=idx; i++) {
        //if (D[i]) continue; //�� �迭�� ä�������� ����̹Ƿ�, �迭�� �̹� ä���� �ִ� ��츦 ����� �ʿ䰡 ����.
        if (i%6==0) {
            D[i] = minVal(D[i-1], D[i/2], D[i/3])+1;
        } else if (i%3==0) {
            D[i] = minVal(D[i-1], D[i/3])+1;
        } else if (i%2==0) {
            D[i] = minVal(D[i-1], D[i/2]) +1;
        } else {
            D[i] = D[i-1]+1;
        }
    } //i loop
    return D[idx];
}

int getD2(int idx) {
    for (int i=2; i<=idx; i++) {
        D[i] = D[i-1]+1;
        if (i%2==0) D[i] = min (D[i], D[i/2]+1);
        if (i%3==0) D[i] = min (D[i], D[i/3]+1);
    }
    return D[idx];
}

int main() {
    cin >> N;
    cout << getD(N);
    return 0;
}
