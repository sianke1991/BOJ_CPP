#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

vector<pair<int, int>> board[2][20];
bool used[2][20];
int ans[2];
int N;

void backtrack(int idx, int cnt, int color) {
    if (idx==2*N) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    for (auto v:board[color][idx]) {
        int x, y;
        tie(x, y) = v;
        if (used[color][x+y]) continue;
        used[color][x+y] = true;
        backtrack(idx+1, cnt+1, color);
        used[color][x+y] = false;
    }

    backtrack(idx+1, cnt, color);
}

int main() {
    scanf("%d", &N);
    int b;
    for (int row=0; row<N; row++) {
        for (int col=0; col<N; col++) {
            scanf("%d", &b);
            if (b) {
                board[(row+col)%2][N+row-col-1].push_back({row, col});
            }
        }
    }
    backtrack(0, 0, 0);
    backtrack(0, 0, 1);
    cout << ans[0] + ans[1];
    return 0;
}
