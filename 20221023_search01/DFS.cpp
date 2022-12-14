#include <bits/stdc++.h> //여러 헤더 파일을 한 번에 인클루드 한다.
#define X first
#define Y second
int board[502][502] =
{
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
bool vis[502][502];
int n=7, m=10; //n: 행의 개수, m: 열의 개수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;

int main() {
    stack<pair<int, int>> S;
    vis[0][0] = 1;
    S.push({0, 0});
    while (!S.empty()) {
        pair<int, int> curNode = S.top(); S.pop();
        cout << "(" << curNode.X << ", " << curNode.Y << ") -> ";
        for (int dir=0; dir<4; dir++) {
            int nx = curNode.X+dx[dir];
            int ny = curNode.Y+dy[dir];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue; //out of bounds
            if (vis[nx][ny]) continue; //has already visited
            if (board[nx][ny]!=1) continue; //invalid position
            vis[nx][ny] = 1;
            S.push({nx, ny});
        } //directional loop
    } //until S becomes empty
    return 0;
}
