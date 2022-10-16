#include <bits/stdc++.h> //여러 헤더 파일을 한 번에 인클루드 한다.
#define X first
#define Y second

int tomato[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

using namespace std;

int main() {
    int N, M; //N: 행의 개수, M: 열의 개수
    cin >> M >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> tomato[i][j];
        } //j loop
    } //i loop

    //0. BFS를 시작할 위치를 찾아서 큐에 넣는다.
    queue<pair<int, int>> Q;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (tomato[i][j]==1) Q.push({i, j});
        } //j loop
    } //i loop

    //1. 큐에서 빼 내서 BFS를 실시한다.
    while (!Q.empty()) {
        pair<int, int> curTomato = Q.front();
        Q.pop();
        int dayPassed = tomato[curTomato.X][curTomato.Y];
        for (int dir=0; dir<4; dir++) {
            int nx = curTomato.X+dx[dir];
            int ny = curTomato.Y+dy[dir];
            if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if (tomato[nx][ny]!=0) continue;
            tomato[nx][ny] = dayPassed+1;
            Q.push({nx, ny});
        } //dir loop
    } //while loop

    int maxDayPassed = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (tomato[i][j]==0) {
                cout << "-1";
                return 0;
            }
            if (tomato[i][j]>maxDayPassed) maxDayPassed = tomato[i][j];
        }
    }
    cout << maxDayPassed-1;


    return 0;
}
