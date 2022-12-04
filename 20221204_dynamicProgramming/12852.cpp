#include <iostream>
#include <algorithm>

using namespace std;

int dpArray[1000002][2];    //dpArray[i][0]: i�� 1�� ����� ���� �ʿ��� ���� Ƚ���� �ּ�ġ (�� ���̺�)
                            //dpArray[i][1]: i�� 1�� ����� ���� �����ؾ� �� ������ ��� (��� ���� ���̺�)

int main() {
    int N;
    cin >> N;
    //�ʱⰪ ����
    dpArray[1][0] = 0;
    dpArray[1][1] = 0;
    dpArray[2][0] = 1;
    dpArray[2][1] = 1;
    dpArray[3][0] = 1;
    dpArray[3][1] = 1;
    for (int i=4; i<=N; i++) {
        dpArray[i][0] = dpArray[i-1][0]+1;
        dpArray[i][1] = i-1;
        if (i%2==0 && dpArray[i/2][0]+1 < dpArray[i][0]) {
            dpArray[i][0] = dpArray[i/2][0]+1;
            dpArray[i][1] = i/2;
        }
        if (i%3==0 && dpArray[i/3][0]+1 < dpArray[i][0]) {
            dpArray[i][0] = dpArray[i/3][0]+1;
            dpArray[i][1] = i/3;
        }
    }

    cout << dpArray[N][0] << '\n';
    int path = N;
    while (1) {
        cout << path << ' ';
        if (path==1) break;
        path = dpArray[path][1];
    }
    return 0;
}
