#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10];
int p[10]; //각 노드의 부모 노드를 저장할 배열
//트리라는 특정한 조건을 만족하는 그래프는 BFS를 할 때 visited 처리를 하지 않아도 된다.
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt:adj[cur]) { //특정 노드에 연결된 노드를 큐에 넣을 때 부모 노드는 넣지 않는다. (그 부모 노드는 방문한 적이 있기 때문에)
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur; //특정 노드의 자식 노드의 부모 값을 기록해둔다.
        } //nxt loop
    } //while loop
}

int p2[10];
int depth[10]; //각 노드의 depth를 저장할 배열 (bfs를 돌면서 해당 배열을 구성하게 된다.)
void bfs2(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt:adj[cur]) {
            if (p2[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur]+1; //자식의 depth 는 본인 depth 보다 1 큰 값이다.
        }
    }
}

int p3[10];
int depth2[10];
void dfs(int root) {
    stack<int> s;
    s.push(root);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for (int nxt:adj[cur]) {
            if (p3[cur] == nxt) continue;
            s.push(nxt);
            p3[nxt] = cur;
            depth2[nxt] = depth2[cur]+1;
        }
    }
}

// 깊이 우선 탐색, 재귀적 방법
int p4[10];
int depth3[10];
void dfs2(int cur) {
    cout << cur << ' ';
    for (int nxt:adj[cur]) {
        if (p4[cur]==nxt) continue;
        p4[nxt] = cur;
        depth3[nxt] = depth3[cur]+1;
        dfs2(nxt);
    }
}

//깊이 우선 탐색, 재귀적 방법 (parent 배열, depth 배열을 남기지 않아도 되는 경우) (맨 처음 호출할 때 par 값은 0 또는 -1과 같은, 실제 사용하지 않는 노드의 값을 인자로 넣는다.)
void dfs3(int cur, int par) {
    cout << cur << ' ';
    for (int nxt:adj[cur]) {
        if (nxt==par) continue;
        dfs3(nxt, cur);
    }
}



int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[4].push_back(6);
    adj[6].push_back(4);
    adj[6].push_back(7);
    adj[6].push_back(8);
    adj[7].push_back(6);
    adj[8].push_back(6);
    dfs(1);
    cout << '\n';
    for (int parent:p3) {
        cout << parent << ' ';
    }
    cout << '\n';
    for (int dep:depth2) {
        cout << dep << ' ';
    }
    cout << '\n';



    return 0;
}
