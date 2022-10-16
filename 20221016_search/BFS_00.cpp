//BFS
//1. �����Ѵ� ĭ�� ť�� �ְ� �湮�ߴٴ� ǥ�ø� ����.
//2. ť���� ���Ҹ� ������ �� ĭ�� �����¿�� ������ ī�� ���� 3���� ����.
//3. �ش� ĭ�� ������ �湮�ߴٸ� �ƹ��͵� ���� �ʰ�, ó������ �湮�ߴٸ� �湮 ����� ����� ť�� ����
//4. ť�� �� ������ 2���� �ݺ�

//�ð����⵵: O(N) (N: �湮�ϴ� ����� ����) = O(��*��)

//#include <iostream>
//#include <queue>
//#include <vector>
//#include <utility>
#include <bits/stdc++.h> //���� ��� ������ �� ���� ��Ŭ��� �Ѵ�.
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
int n = 7, m = 10; //n�� ���� ����, m�� ���� ����
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main() {
//    pair<int, int> t1 = make_pair(10, 13); //��� ����
//    pair<int, int> t2 = {4, 20};

//    cout << t2.first << ',' << t2.second << '\n';
//    if (t2<t1) cout << "t2 < t1"; //first ���� ���� ���� ��, �� ���� ������ second ���� ���Ѵ�.
    ios::sync_with_stdio;
    cin.tie(0);
    queue<pair<int, int>> Q;
    vis[0][0] = true;
    Q.push({0, 0}); //Q�� �湮�� �� �ִ´�.

    while (!Q.empty()) {
        /*
        pair<int, int> lpVisited = Q.front(); //Q���� ���� ���� ������ ���� ��ȸ
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
