#include <bits/stdc++.h> //���� ��� ������ �� ���� ��Ŭ��� �Ѵ�.
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int numPictures = 0;
int maxPictureSize = 0;

using namespace std;

int main() {
    int n, m; //n�� ���� ����, y�� ���� ����
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        } //j loop
    } //i loop

    //0. BFS�� ������ ��带 Ž���Ѵ�.
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j]!=1 || vis[i][j]) continue;

            //1. BFS�� ������ ��带 �߰������� BFS�� �ǽ��Ѵ�.
            numPictures++; //to update numPictures
            int curPictureSize = 0;
            queue<pair<int, int>> Q;
            vis[i][j] = true;
            Q.push({i, j});
            while (!Q.empty()) {
                pair<int, int> curNode = Q.front();
                Q.pop();
                curPictureSize++;
                for (int dir=0; dir<4; dir++) {
                    int nx = curNode.X+dx[dir];
                    int ny = curNode.Y+dy[dir];
                    if (nx<0 || nx>=n || ny<0 || ny>=m) continue; //out of bounds
                    if (board[nx][ny]!=1) continue; //invalid position
                    if (vis[nx][ny]) continue; //has visited already
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                } //directional loop
            } //until Q becomes empty
            if (curPictureSize>maxPictureSize) maxPictureSize = curPictureSize; //to update maxPictureSize
        } //j loop
    } //i loop

    cout << numPictures << "\n" << maxPictureSize;

    return 0;
}
