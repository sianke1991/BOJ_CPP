#include <bits/stdc++.h>

using namespace std;
vector<int> adjList[100001];
int parentOf[100001];

int main() {
    //Ʈ���� Ư�� �� ��尡 N�� �� �� ������ N-1�� �����Ѵ�.
    int numNodes;
    cin >> numNodes;
    for (int i=0; i<numNodes-1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } //i loop

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt:adjList[cur]) {
            if (nxt==parentOf[cur]) continue; //�θ� ���� �̹� �湮�� �����̹Ƿ� ť�� ���� �ʴ´�.
            q.push(nxt);
            parentOf[nxt] = cur;
        }
    } //while loop

    for (int i=2; i<=numNodes; i++) {
        cout << parentOf[i] << '\n';
    }
    return 0;
}
