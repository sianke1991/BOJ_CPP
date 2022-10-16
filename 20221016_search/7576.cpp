#include <bits/stdc++.h> //���� ��� ������ �� ���� ��Ŭ��� �Ѵ�.
#define X first
#define Y second

int tomato[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

using namespace std;

int main() {
    int N, M; //N: ���� ����, M: ���� ����
    cin >> M >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> tomato[i][j];
        } //j loop
    } //i loop

    //0. BFS�� ������ ��ġ�� ã�Ƽ� ť�� �ִ´�.
    queue<pair<int, int>> Q;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (tomato[i][j]==1) Q.push({i, j});
        } //j loop
    } //i loop

    //1. ť���� �� ���� BFS�� �ǽ��Ѵ�.
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
