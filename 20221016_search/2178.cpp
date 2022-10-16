#include <bits/stdc++.h> //���� ��� ������ �� ���� ��Ŭ��� �Ѵ�.
#define X first
#define Y second

char board[102][102];
int dist[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int numPictures = 0;
int maxPictureSize = 0;

using namespace std;

int main() {
    int N, M; //N: ���� ����, M: ���� ����
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        } //j loop
    } //i loop

//    cout << "�Է� �Ϸ�!\n";
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});


    while (!q.empty()) {
        pair<int, int> curNode = q.front();
        int curDist = dist[curNode.X][curNode.Y];
//        cout << curNode.X << ", " << curNode.Y << "\n";
        q.pop();
        for (int dir=0; dir<4; dir++) {
            int nx = curNode.X+dx[dir];
            int ny = curNode.Y+dy[dir];
            if (nx<0 || nx>=N || ny<0 || ny>=M) continue; //out of bounds
            if (board[nx][ny]!='1') continue; //invalid position
            if (dist[nx][ny]) continue; //has visited already
            dist[nx][ny] = curDist+1;
            q.push({nx, ny});
        } //directional loop
    } //until q becomes empty

    cout << dist[N-1][M-1];

    return 0;
}
