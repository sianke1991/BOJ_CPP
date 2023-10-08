#include <iostream>

using namespace std;

//dpCache[N][bit]: N자리 이진수에 대해 (왼쪽에서) N번째 비트가 bit인 이친수의 경우의 수
long long dpCache[92][2];

int main() {
    int N;
    cin >> N;
    dpCache[1][0] = 0;
    dpCache[1][1] = 1;

    for (int i=2; i<=N; i++) {
        dpCache[i][0] = dpCache[i-1][0] + dpCache[i-1][1]; //바로 앞 자리가 0이던, 1이던 상관 없이 해당 자리에 0이 올 수 있다.
        dpCache[i][1] = dpCache[i-1][0]; //바로 앞 자리가 0이어야 해당 자리에 1이 올 수 있다.
    }
    cout << dpCache[N][0] + dpCache[N][1];
    return 0;
}
