#include <bits/stdc++.h>

using namespace std;


int main() {

    //������ ����ϴ� ���
    int a[3] = {1, 2, 3};
    do {
        for (int i=0; i<3; i++) {
            cout << a[i];
        }
        cout << '\n';
    } while (next_permutation(a, a+3)); //������ ���鼭 �迭 a�� ������ �����Ѵ�.

    for (int i=0; i<3; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    //������ ����ϴ� ���
    int b[4] = {0, 0, 1, 1}; //0�� �ش� ��ġ�� �ִ� ���Ҹ� ����������, 1�� �ش� ��ġ�� �ִ� ���Ҹ� �������� �ʾ����� ��Ÿ����.
    do {
        for (int i=0; i<4; i++) {
            if (b[i]==0) cout << i+1;
        }
        cout << '\n';
    } while (next_permutation(b, b+4));

    return 0;
}
