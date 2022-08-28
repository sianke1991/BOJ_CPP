#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int compare(pair<int, int> x, pair<int, int> y) {
    int endTimeDif = x.second - y.second;
    if (endTimeDif) return endTimeDif;
    return x.first - y.first;
}

int main() {
    int N;
    for (int i=0; i<N; i++) cin >> N;

    vector<pair<int, int>> vec(N); //벡터를 마치 배열처럼 사용하기 위한 선언 방식 (처음에 크기 N을 잡아둔다.)

    for (int i=0; i<N; i++) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end());

    int savetime = 0, ans = 0;
    for (int i=0; i<N; i++) {
        if (savetime <= a[i].second) {
            savetime = a[i].first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
