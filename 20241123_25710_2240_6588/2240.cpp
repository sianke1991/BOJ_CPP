#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


// 자두 열매가 떨어지는 횟수
int numTimes;
// 자두 위치 변경 횟수
int numMaxMoves;
// dp[t][m] := 시각 t 초 때 m 번 움직임이 남은 상황에서 얻을 수 있는 자두 열매 개수의 최대치
// 자두 나무가 2 그루 있으므로 이동 횟수를 알면 현재 자두가 있는 위치를 알 수 있다.
int dp[1010][40];
/*
    자두가 이동할 수 있는 횟수가 제한되어 있으므로,
    dp 테이블의 제 2축은
    자두가 이동한 횟수
        - 혹은 -
    이동 남은 횟수
    가 되어야 한다.
*/
// falling[t] := 시각 t 초 때 자두 열매가 떨어지는 나무의 번호 (1 또는 2)
int falling[1010];



int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

void input() {
    scanf("%d %d", &numTimes, &numMaxMoves);
    for (int t=1; t<=numTimes; t++) {
        scanf("%d", &falling[t]);
    }
}

int main() {
    input();
    //초기값
    dp[0][numMaxMoves] = 0;
    //점화식
    for (int time=1; time<=numTimes; time++) {
        //처음부터 1번 나무에 고정된 경우는 별도로 관리해준다. (numRemainingMoves가 numMaxMoves인 경우-)
        //이 경우 1번 나무에 자두 열매가 떨어질 때 마다 1을 증가시켜준다.
        dp[time][numMaxMoves] = falling[time] == 1 ? dp[time-1][numMaxMoves]+1 : dp[time-1][numMaxMoves];
        for (int numRemainingMoves=numMaxMoves-1; numRemainingMoves>=0; numRemainingMoves--) {
            int position = ((numMaxMoves-numRemainingMoves)&1) ? 2 : 1;
            dp[time][numRemainingMoves] = max(
                dp[time-1][numRemainingMoves+1], //위치를 변경하는 경우-
                dp[time-1][numRemainingMoves]    //위치를 변경하지 않는 경우-
            );
            if (falling[time]==position) dp[time][numRemainingMoves]++; //자두 열매가 떨어지는 올바른 위치에 있는 경우 1을 증가시켜준다.
        } //numRemainingMoves loop
    } //time loop

    int result = 0;
    for (int numRemainingMoves=0; numRemainingMoves<=numMaxMoves; numRemainingMoves++) {
        result = max(result, dp[numTimes][numRemainingMoves]);
    }
    printf("%d", result);
    return 0;
}
