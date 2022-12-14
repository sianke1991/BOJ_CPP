//BFS
//1. 시작한느 칸을 큐에 넣고 방문했다는 표시를 남김.
//2. 큐에서 원소를 꺼내서 그 칸에 상하좌우로 인접한 카넹 대해 3번을 진행.
//3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문 기록을 남기고 큐에 삽입
//4. 큐가 빌 때까지 2번을 반복

//시간복잡도: O(N) (N: 방문하는 노드의 개수) = O(행*열)

//#include <iostream>
//#include <queue>
//#include <vector>
//#include <utility>
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
int n = 7, m = 10; //n은 행의 개수, m은 열의 개수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main() {
//    pair<int, int> t1 = make_pair(10, 13); //페어 생성
//    pair<int, int> t2 = {4, 20};

//    cout << t2.first << ',' << t2.second << '\n';
//    if (t2<t1) cout << "t2 < t1"; //first 값을 먼저 비교한 뒤, 그 값이 같으면 second 값을 비교한다.
    ios::sync_with_stdio;
    cin.tie(0);
    queue<pair<int, int>> Q;
    vis[0][0] = true;
    Q.push({0, 0}); //Q에 방문한 페어를 넣는다.

    while (!Q.empty()) {
        /*
        pair<int, int> lpVisited = Q.front(); //Q에서 제일 먼저 꺼내질 원소 조회
        Q.pop();
        cout << lpVisited.X << ", " << lpVisited.Y << "\n";
        for (int i=0; i<4; i++) {
            pair<int, int> lpNew = {lpVisited.X+dx[i], lpVisited.Y+dy[i]};
            if (lpNew.X<0 || lpNew.X>=n || lpNew.Y<0 || lpNew.Y>=m) continue; //out of bounds
            if (board[lpNew.X][lpNew.Y]==0) continue; //invalid location
            if (vis[lpNew.X][lpNew.Y]) continue; //has visited already
            vis[lpNew.X][lpNew.Y]=true;
            Q.push(lpNew);
        } //directional loop
        */

        pair<int, int> cur;
        cur = Q.front();
        cout << '(' << cur.X << ", " << cur.Y << ')' <<"->";
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X+dx[dir]; //new x
            int ny = cur.Y+dy[dir]; //new y
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue; //out of bounds
            if (vis[nx][ny] || board[nx][ny]!=1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        } //directional loop
    } //until Q is not empty



    return 0;




}
