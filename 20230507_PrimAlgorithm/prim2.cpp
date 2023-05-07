#define X first
#define Y second

#include <bits/stdc++.h>

using namespace std;

int main() {
    int v = 5, e = 7;
    vector<pair<int, int>> adj[10005]; //인접 리스트 {비용, 정점번호}

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


    bool chk[10005]; //해당 정점이 MST에 포함되었는지 여부
    int cnt = 0; //MST에 포함된 간선의 개수
    //tuple<int, int, int> {비용, 출발노드, 도착노드}
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq; //단순히 priority_queue<tuple<int, int, int>> 라고 작성하면 최대힙이 된다.
    chk[1] = 1;
    for (auto nxt:adj[1]) {
        pq.push({nxt.X, 1, nxt.Y});
    }

    while (cnt < v-1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue; //우선순위 큐에서 뽑은 간선이 [이미 선택된 노드와 연결하는] 간선일 경우-
        cout << cost << ' ' << a << ' ' << b << '\n';
        chk[b] = true;
        cnt++;
        for (auto nxt:adj[b]) {
            if (!chk[nxt.Y]) //이 if 조건이 필요한 조건인가?
                pq.push({nxt.X, b, nxt.Y});
        }
    }

}
