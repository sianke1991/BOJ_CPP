#include <stdio.h>
#include <vector>

/*
bool 2���� �迭�� ����ϴ�
�賶 ����
cf. b26607: �÷��ڿ� �����б�
*/

using namespace std;

int numHamburgers, sumHamburgers=0;
vector<int> hamburgers; //�� �ܹ����� ȿ��
bool dp[2510][2510] = {}; // dp[i][j]:= ���찡 i ��ŭ ȿ����, öȯ�̰� j ��ŭ ȿ���� ���� �� �ִ��� ����

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

    //�ʱ� ����
    dp[0][0] = true;

    //��ȭ��
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
