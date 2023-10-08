#include <iostream>
//11727
using namespace std;
long long dpCache[1002];

int main() {
    //���� ���� ���� ������ ���� Ǯ��, �� ����� �׾� �÷��� �־��� ������ �ذ��Ѵ�.
    int N;
    cin >> N;
    dpCache[0] = 1;
    dpCache[1] = 1;
    for (int i=2; i<=N; i++) {
        dpCache[i] = (dpCache[i-1] + dpCache[i-2]*2)%10007;
    }
    cout << dpCache[N];
    return 0;
}
