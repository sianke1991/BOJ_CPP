#include <iostream>

int stoke[1000001];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> stoke[i];
    }
    int max_val = stoke[n-1];
    long long ans = 0;

    for (int i=n-2; i>=0; --i) {
        if (stoke[i] > max_val) max_val = a[i];
        ans += max_val - a[i];
    }

    cout << ans << '\n';

    return 0;
}
