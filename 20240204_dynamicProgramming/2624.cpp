#include <stdio.h>

int totalPrice;
int numCoinTypes;
int coinValues[110];
int coinNums[110];
int dpArray[110][11000]; //dpArray[i][j]:= 동전 i 종류를 사용하여 j 원을 만들 수 있는 경우의 수
                        //예를 들어 dpArray[3][10000]은 동전 3 종류를 사용하여 10000원을 만드는 경우의 수이다.

int main() {
    scanf("%d", &totalPrice);
    scanf("%d", &numCoinTypes);
    for (int coinIndex=1; coinIndex<=numCoinTypes; coinIndex++) {
        scanf("%d %d", &coinValues[coinIndex], &coinNums[coinIndex]);
    } //coinIndex loop

    dpArray[0][0] = 1; // 동전 0가지를 사용하여 0원을 만드는 경우의 수는 1개가 있다. (모든 동전을 사용하지 않음)
    for (int i=1; i<=numCoinTypes; i++) {
        for (int j=0; j<=coinNums[i]; j++) {
            for (int l=0; l<=totalPrice-coinValues[i]*j; l++) {
                dpArray[i][l+coinValues[i]*j] += dpArray[i-1][l]; //이전에 동전 i-1 종류를 가지고 l원을 생성한 경우의 수에서
                                            //현재 동전 i 종류를 가지고 l+coinValues[i]*j원을 생성하는 경우의 수를 구한다.
            } //l loop (동전 가치 합 loop)
        } //j loop (동전 개수 loop)
    } //i loop (동전 종류 loop)

    printf("%d", dpArray[numCoinTypes][totalPrice]);
    return 0;

}
