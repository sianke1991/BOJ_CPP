#include <stdio.h>

long long dp[110] = {0};

long long max(long long num0, long long num1) {
    return num0 > num1 ? num0 : num1;
}

int min(int num0, int num1) {
    return num0 < num1 ? num0 : num1;
}

int main() {
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1]+1; //문자 하나 추가하는 입력
        for (int j=min(1, i-2); j<i-2; j++) {
            int t = i-j-1; //붙여넣기 횟수
            dp[i] = max(dp[i], dp[j]*t);
        } //j loop
    } //i loop
    printf("%lld", dp[n]);
    return 0;
}
