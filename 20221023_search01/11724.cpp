#include <bits/stdc++.h> //여러 헤더 파일을 한 번에 인클루드 한다.

using namespace std;

bool hasChecked[1001];
bool isConnected[1001][1001];

int main() {
    //연결 요소란 간선으로 서로 연결된 노드의 덩어리, '섬'과 같은 것이다.
    //그래프 상에 '노드 섬'의 개수를 구하는 문제이다.
    //BFS를 실행하는 개수를 구하는 문제이다.
    int N, M; //N: 노드 개수, M: 간선 개수
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        isConnected[u][v] = true;
        isConnected[v][u] = true;
    } //간선 입력 루프
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
            } //i에 연결되어 있는 노드 체크 루프 (j loop)
        } //until q becomes empty
    } //연결 요소 루프 (i loop)

    cout << numConnectedComponents;
    return 0;
}
