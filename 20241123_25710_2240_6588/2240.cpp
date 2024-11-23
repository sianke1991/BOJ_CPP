#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


// �ڵ� ���Ű� �������� Ƚ��
int numTimes;
// �ڵ� ��ġ ���� Ƚ��
int numMaxMoves;
// dp[t][m] := �ð� t �� �� m �� �������� ���� ��Ȳ���� ���� �� �ִ� �ڵ� ���� ������ �ִ�ġ
// �ڵ� ������ 2 �׷� �����Ƿ� �̵� Ƚ���� �˸� ���� �ڵΰ� �ִ� ��ġ�� �� �� �ִ�.
int dp[1010][40];
/*
    �ڵΰ� �̵��� �� �ִ� Ƚ���� ���ѵǾ� �����Ƿ�,
    dp ���̺��� �� 2����
    �ڵΰ� �̵��� Ƚ��
        - Ȥ�� -
    �̵� ���� Ƚ��
    �� �Ǿ�� �Ѵ�.
*/
// falling[t] := �ð� t �� �� �ڵ� ���Ű� �������� ������ ��ȣ (1 �Ǵ� 2)
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
    //�ʱⰪ
    dp[0][numMaxMoves] = 0;
    //��ȭ��
    for (int time=1; time<=numTimes; time++) {
        //ó������ 1�� ������ ������ ���� ������ �������ش�. (numRemainingMoves�� numMaxMoves�� ���-)
        //�� ��� 1�� ������ �ڵ� ���Ű� ������ �� ���� 1�� ���������ش�.
        dp[time][numMaxMoves] = falling[time] == 1 ? dp[time-1][numMaxMoves]+1 : dp[time-1][numMaxMoves];
        for (int numRemainingMoves=numMaxMoves-1; numRemainingMoves>=0; numRemainingMoves--) {
            int position = ((numMaxMoves-numRemainingMoves)&1) ? 2 : 1;
            dp[time][numRemainingMoves] = max(
                dp[time-1][numRemainingMoves+1], //��ġ�� �����ϴ� ���-
                dp[time-1][numRemainingMoves]    //��ġ�� �������� �ʴ� ���-
            );
            if (falling[time]==position) dp[time][numRemainingMoves]++; //�ڵ� ���Ű� �������� �ùٸ� ��ġ�� �ִ� ��� 1�� ���������ش�.
        } //numRemainingMoves loop
    } //time loop

    int result = 0;
    for (int numRemainingMoves=0; numRemainingMoves<=numMaxMoves; numRemainingMoves++) {
        result = max(result, dp[numTimes][numRemainingMoves]);
    }
    printf("%d", result);
    return 0;
}
