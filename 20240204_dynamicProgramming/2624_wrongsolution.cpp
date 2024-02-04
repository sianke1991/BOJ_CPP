#include <stdio.h>
#include <algorithm>

struct Coin {
    int value;
    int num;
};

bool compare(Coin c0, Coin c1) {
    return c0.value > c1.value;
}

int totalValue;
int numCoinTypes;
Coin coins[100];
int numMethods = 0;

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

void backtrack(int remainingValue, int coinIndex) {
    //베이스 케이스
    if (coinIndex==numCoinTypes) {
        //printf("%d\n", remainingValue);
        if (remainingValue==0) numMethods++;
        return;
    }

    for (int numCoins=0; numCoins<=min(coins[coinIndex].num, remainingValue/coins[coinIndex].value); numCoins++) {
        backtrack(remainingValue-coins[coinIndex].value*numCoins, coinIndex+1);
    } //numCoins loop
}

int main() {
    scanf("%d", &totalValue);
    scanf("%d", &numCoinTypes);
    for (int i=0; i<numCoinTypes; i++) {
        int value, num;
        scanf("%d %d", &value, &num);
        coins[i] = {value, num};
    }
    std::sort(coins, coins+numCoinTypes, compare);
    backtrack(totalValue, 0);
    printf("%d", numMethods);


    return 0;




}
