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

    vector<pair<int, int>> vec(N); //���͸� ��ġ �迭ó�� ����ϱ� ���� ���� ��� (ó���� ũ�� N�� ��Ƶд�.)

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
