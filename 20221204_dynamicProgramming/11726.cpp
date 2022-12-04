#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int dpArray[n+1];

    //초기값 설정
    dpArray[0] = 1;
    dpArray[1] = 1;
    dpArray[2] = 2;

    for (int i=3; i<=n; i++) {
        dpArray[i] = (dpArray[i-1] + dpArray[i-2])%10007;
    }

    cout << dpArray[n];
    return 0;
}
