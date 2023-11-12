#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lines;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        lines.push_back({x, y});
    }

    sort (lines.begin(), lines.end());

    int l, r;
    l = lines[0].first;
    r = lines[0].second;
    int ans = 0;
    for (int i=1; i<n; i++) {
        int a, b;
        a = lines[i].first; b = lines[i].second;
        if (a<=r && b>=r) r = b; //직전 선분의 오른쪽 끝을 이번 선분이 포함하고, 오른쪽으로 더 가는 경우 오른쪽 끝을 연장한다.
        else if (a > r) { //직전 선분의 오른쪽 끝과 이번 선분의 왼쪽 끝이 분리된 경우
            ans += r-l;
            l = a;
            r = b;
        }
    }

    cout << ans + r - l;
    return 0;
}
