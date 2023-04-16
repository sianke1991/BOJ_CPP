#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10];
int p[10]; //�� ����� �θ� ��带 ������ �迭
//Ʈ����� Ư���� ������ �����ϴ� �׷����� BFS�� �� �� visited ó���� ���� �ʾƵ� �ȴ�.
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt:adj[cur]) { //Ư�� ��忡 ����� ��带 ť�� ���� �� �θ� ���� ���� �ʴ´�. (�� �θ� ���� �湮�� ���� �ֱ� ������)
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur; //Ư�� ����� �ڽ� ����� �θ� ���� ����صд�.
        } //nxt loop
    } //while loop
}

int p2[10];
int depth[10]; //�� ����� depth�� ������ �迭 (bfs�� ���鼭 �ش� �迭�� �����ϰ� �ȴ�.)
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
            depth[nxt] = depth[cur]+1; //�ڽ��� depth �� ���� depth ���� 1 ū ���̴�.
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

// ���� �켱 Ž��, ����� ���
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

//���� �켱 Ž��, ����� ��� (parent �迭, depth �迭�� ������ �ʾƵ� �Ǵ� ���) (�� ó�� ȣ���� �� par ���� 0 �Ǵ� -1�� ����, ���� ������� �ʴ� ����� ���� ���ڷ� �ִ´�.)
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
