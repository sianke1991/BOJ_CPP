#include <bits/stdc++.h> //���� ��� ������ �� ���� ��Ŭ��� �Ѵ�.

using namespace std;

bool hasChecked[1001];
bool isConnected[1001][1001];

int main() {
    //���� ��Ҷ� �������� ���� ����� ����� ���, '��'�� ���� ���̴�.
    //�׷��� �� '��� ��'�� ������ ���ϴ� �����̴�.
    //BFS�� �����ϴ� ������ ���ϴ� �����̴�.
    int N, M; //N: ��� ����, M: ���� ����
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        isConnected[u][v] = true;
        isConnected[v][u] = true;
    } //���� �Է� ����
    int numConnectedComponents = 0;
    for (int i=1; i<=N; i++) {
        if (hasChecked[i]) continue;
        numConnectedComponents++;
        hasChecked[i] = true;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int currentNode = q.front();

            q.pop();
            for (int j=1; j<=N; j++) {
                if (j==currentNode) continue;
                if (!isConnected[currentNode][j]) continue;
                if (hasChecked[j]) continue;
                hasChecked[j] = true;
                q.push(j);
            } //i�� ����Ǿ� �ִ� ��� üũ ���� (j loop)
        } //until q becomes empty
    } //���� ��� ���� (i loop)

    cout << numConnectedComponents;
    return 0;
}
