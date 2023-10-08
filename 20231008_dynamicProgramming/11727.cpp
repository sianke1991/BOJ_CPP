#include <iostream>
//11727
using namespace std;
long long dpCache[1002];

int main() {
    //여러 개의 하위 문제를 먼저 풀고, 그 결과를 쌓아 올려서 주어진 문제를 해결한다.
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
