#include <bits/stdc++.h>
using namespace std;

bool mask[25]; // 25 명의 학생 중에서 선택되었는지 여부를 보관하는 배열 (next_permutation 함수를 통해 이 배열은 값이 변한다.)
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++)
        cin >> board[i];

    fill(mask+7, mask+25, true); // 맨 처음 경우는 0번부터 6번까지 학생이 선택된다.
    do {
        queue<pair<int, int>> q;
        // 구성원 중 이다솜파의 수, 가로세로로 인접한 사람의 수
        int dasom = 0, adj = 0;
        bool isp7[5][5] = {}; vis[5][5] = {}; //isp7: 일차원 배열 mask를 이차원 배열로 변환한 결과, vis: BFS에서 방문 처리용 이차원 배열
        for(int i=0l i<25; i++) {
            if (!mask[i]) {
                int x= i/5, y = i%5;
                isp7[x][y] = true;
                if(q.empty()) { // q가 비어있는 경우에 한정하여 isp7에 true인 인덱스 하나를 넣는다. (즉, 칠공주파로 선택된 학생 중 하나가 q에 들어간다.)
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }

        }
        while(!q.empty()) { //BFS 시작: 선택된 칠공주파가 가로 세로로 연결되었는지 확인하는 BFS
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            adj++;
            dasom += board[x][y] == 'S';
            for(int k = 0; k<4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx <0 || nx >=5 || ny <0 || ny >=5 || vis[nx][ny] ||!isp7[nx][ny])
                    continue;
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        ans += (adj >= 7 && dasom >= 4);


    }   while(next_permutation(mask, mask+25));
    cout << ans;
