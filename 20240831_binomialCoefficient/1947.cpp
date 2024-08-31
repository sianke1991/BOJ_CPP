#include <stdio.h>
long long dp[1000001] = {1};
int main() {
    int n;
    scanf("%d", &n);
    for (long long i=2; i<=n; i++) {
        if (i%2==0) dp[i] = (i*dp[i-1]+1)%1000000000;
        else dp[i] = (i*dp[i-1]-1)%1000000000;
    } //i loop
    printf("%lld", dp[n]);
    return 0;
}
