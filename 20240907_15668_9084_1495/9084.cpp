#include <stdio.h>

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    int result[11];
    for (int testCase=0; testCase<numTestCases; testCase++) {
        int numCoinTypes;
        int coinTypes[21];
        int targetValue;
        scanf("%d", &numCoinTypes);
        for (int i=0; i<numCoinTypes; i++) {
            scanf("%d", &coinTypes[i]);
        }
        scanf("%d", &targetValue);
        int dp[10001] = {1};
        for (int coinTypeIndex=0; coinTypeIndex<numCoinTypes; coinTypeIndex++) {
            int coinType = coinTypes[coinTypeIndex];
            for (int value=coinType; value<=targetValue; value++) {
                //(value-coinType)원에서 coinType 동전 하나를 추가하여 value원을 만들 수 있다.
                //따라서 value원을 만들 수 있는 경우의 수가
                //(value-coinType)원을 만들 수 있는 경우의 수 만큼 증가한다.
                if (dp[value-coinType]) dp[value] += dp[value-coinType];
            } //value loop
        } //coinTypeIndex loop
        result[testCase] = dp[targetValue];
    } //testCase loop

    for (int i=0; i<numTestCases; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}
