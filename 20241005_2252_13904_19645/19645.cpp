#include <stdio.h>
#include <vector>

/*
bool 2차원 배열을 사용하는
배낭 문제
cf. b26607: 시로코와 은행털기
*/

using namespace std;

int numHamburgers, sumHamburgers=0;
vector<int> hamburgers; //각 햄버거의 효용
bool dp[2510][2510] = {}; // dp[i][j]:= 관우가 i 만큼 효용을, 철환이가 j 만큼 효용을 얻을 수 있는지 여부

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    scanf("%d", &numHamburgers);
    for (int i=0; i<numHamburgers; i++) {
        int ham;
        scanf("%d", &ham);
        hamburgers.push_back(ham);
        sumHamburgers += ham;
    }

    //초기 조건
    dp[0][0] = true;

    //점화식
    for (int hamburger:hamburgers) {
        for (int j=sumHamburgers; j>=0; j--) {
            for (int k=sumHamburgers; k>=0; k--) {
                if (j-hamburger>=0 && dp[j-hamburger][k]) dp[j][k] = true;
                if (k-hamburger>=0 && dp[j][k-hamburger]) dp[j][k] = true;
            } //k loop
        } //j loop
    } //hamburger loop

    int result = 0;
    for (int j=0; j<=sumHamburgers; j++) {
        for (int k=0; k<=sumHamburgers; k++) {
            if (!dp[j][k]) continue;
            int i = sumHamburgers-j-k;
            int minValue = min(min(j, k), i);
            result = max(result, minValue);
        }
    }
    printf("%d", result);
}
