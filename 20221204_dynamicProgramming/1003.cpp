#include <iostream>

using namespace std;

int dpArray[41][2]; //�Ǻ���ġ(i)�� ȣ������ �� 0 �Ǵ� 1�� ����ϴ� Ƚ��

int main() {
    //�ʱⰪ ����
    dpArray[0][0] = 1;
    dpArray[0][1] = 0;
    dpArray[1][0] = 0;
    dpArray[1][1] = 1;
    //��ȭ�� ����
    for (int i=2; i<41; i++) {
        dpArray[i][0] = dpArray[i-2][0] + dpArray[i-1][0];
        dpArray[i][1] = dpArray[i-2][1] + dpArray[i-1][1];
    }
    int T;
    cin >> T;
    int results[T][2];
    for (int testcase=0; testcase<T; testcase++) {
        int N;
        cin >> N;
        results[testcase][0] = dpArray[N][0];
        results[testcase][1] = dpArray[N][1];
    }

    for (int i=0; i<T; i++) {
        cout << results[i][0] << ' ' << results[i][1] << '\n';
    }
    return 0;
}
