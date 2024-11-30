#include <stdio.h>
#include <vector>

//dp[i][j] := 최대 정수 j를 (반드시) 사용하여 정수 i를 만들 수 있는 경우의 수
//e.g. dp[4][2] := 2이하의 정수를 사용하여 (2는 반드시 사용) 4를 만들 수 있는 경우의수
// 2 + 2
// 2 + 1 + 1
//의 두 가지가 있으므로 dp[4][2] = 2
long long dp[10001][4] = {0LL};

int main() {
    //초기값
    dp[1][1] = 1LL;
    dp[2][1] = 1LL;
    dp[2][2] = 1LL;
    dp[3][1] = 1LL;
    dp[3][2] = 1LL;
    dp[3][3] = 1LL;
    //점화식
    for (int i=4; i<=10000; i++) {
        // i = (i-1) + 1
        dp[i][1] = dp[i-1][1];
        // i = (i-2) + 2
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        // i = (i-3) + 3
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    std::vector<long long> results;
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int testCase=0; testCase<numTestCases; testCase++) {
        int target;
        scanf("%d", &target);
        results.push_back(dp[target][1] + dp[target][2] + dp[target][3]);
    } //testCase loop
    for (long long result:results)
        printf("%lld\n", result);
    return 0;
}
