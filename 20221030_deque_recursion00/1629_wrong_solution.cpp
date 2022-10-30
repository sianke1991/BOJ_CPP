#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int result = 1;
    while (B--) {
        result *= A;
        result %= C;
    }
    cout << result;
    return 0;
}
