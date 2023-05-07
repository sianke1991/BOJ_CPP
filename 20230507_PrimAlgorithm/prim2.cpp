#define X first
#define Y second

#include <bits/stdc++.h>

using namespace std;

int main() {
    int v = 5, e = 7;
    vector<pair<int, int>> adj[10005]; //���� ����Ʈ {���, ������ȣ}

    adj[1].push_back({4, 2});
    adj[1].push_back({3, 3});
    adj[1].push_back({3, 4});
    adj[2].push_back({4, 1});
    adj[2].push_back({8, 5});
    adj[3].push_back({3, 1});
    adj[3].push_back({3, 4});
    adj[3].push_back({5, 5});
    adj[4].push_back({3, 1});
    adj[4].push_back({3, 3});
    adj[4].push_back({6, 5});
    adj[5].push_back({8, 2});
    adj[5].push_back({5, 3});
    adj[5].push_back({6, 4});


    bool chk[10005]; //�ش� ������ MST�� ���ԵǾ����� ����
    int cnt = 0; //MST�� ���Ե� ������ ����
    //tuple<int, int, int> {���, ��߳��, �������}
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq; //�ܼ��� priority_queue<tuple<int, int, int>> ��� �ۼ��ϸ� �ִ����� �ȴ�.
    chk[1] = 1;
    for (auto nxt:adj[1]) {
        pq.push({nxt.X, 1, nxt.Y});
    }

    while (cnt < v-1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue; //�켱���� ť���� ���� ������ [�̹� ���õ� ���� �����ϴ�] ������ ���-
        cout << cost << ' ' << a << ' ' << b << '\n';
        chk[b] = true;
        cnt++;
        for (auto nxt:adj[b]) {
            if (!chk[nxt.Y]) //�� if ������ �ʿ��� �����ΰ�?
                pq.push({nxt.X, b, nxt.Y});
        }
    }

}
