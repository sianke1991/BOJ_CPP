#include <bits/stdc++.h>
using namespace std;

bool mask[25]; // 25 ���� �л� �߿��� ���õǾ����� ���θ� �����ϴ� �迭 (next_permutation �Լ��� ���� �� �迭�� ���� ���Ѵ�.)
string board[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++)
        cin >> board[i];

    fill(mask+7, mask+25, true); // �� ó�� ���� 0������ 6������ �л��� ���õȴ�.
    do {
        queue<pair<int, int>> q;
        // ������ �� �̴ټ����� ��, ���μ��η� ������ ����� ��
        int dasom = 0, adj = 0;
        bool isp7[5][5] = {}; vis[5][5] = {}; //isp7: ������ �迭 mask�� ������ �迭�� ��ȯ�� ���, vis: BFS���� �湮 ó���� ������ �迭
        for(int i=0l i<25; i++) {
            if (!mask[i]) {
                int x= i/5, y = i%5;
                isp7[x][y] = true;
                if(q.empty()) { // q�� ����ִ� ��쿡 �����Ͽ� isp7�� true�� �ε��� �ϳ��� �ִ´�. (��, ĥ�����ķ� ���õ� �л� �� �ϳ��� q�� ����.)
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }

        }
        while(!q.empty()) { //BFS ����: ���õ� ĥ�����İ� ���� ���η� ����Ǿ����� Ȯ���ϴ� BFS
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
