#include <iostream>
// ���� ���¿��� ������ ��� �ĺ����� ���󰡴� Ž�����
// ���°���Ʈ��
using namespace std;
int n, m;
int arr[10];
bool isUsed[10];
            // k: ����� ����
void func(int k) {
    if (k==m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!isUsed[i]) {
            arr[k] = i;
            isUsed[i] = true;
            func(k+1);
            isUsed[i] = false; //�ش� ��츦 ���� Ž���� ��� �ش� ���� ������ �Ѵ�.
        }
    }
}
/*
func(0): arr[0]�� ����, func(1) ȣ��
func(m): ��� �� ��� ����
*/


int main() {



    return 0;
}
