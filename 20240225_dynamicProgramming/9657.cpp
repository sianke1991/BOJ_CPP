#include <stdio.h>

//남은 돌의 개수에 따른 승자
//0: 선수의 승리, 1: 후수의 승리
//돌이 0개 남아있는 경우 선수가 돌을 가져올 수 없으므로 후수의 승리이다. dpArray[0] = 1
//돌이 1개 남아있는 경우 선수가 돌을 1개 가져와서 선수의 승리이다. dpArray[1] = 0
//돌이 2개 남아있는 경우 선수와 후수가 각각 돌을 1개 가져와서 후수의 승리이다. dpArray[2] = 1
//돌이 3개 남아있는 경우 선수가 돌을 3개 가져와서 선수의 승리이다. dpArray[3] = 0
//돌이 4개 남아있는 경우 선수가 돌을 4개 가져와서 선수의 승리이다. dpArray[4] = 0
int dpArray[1001] = {1, 0, 1, 0, 0};


int main() {
    int numStones;
    scanf("%d", &numStones);
    for (int i=5; i<=numStones; i++) {
        //돌을 1개, 3개 혹은 4개를 제거하여 후수가 이길 수 있는 상황을 만들 수 있다면 해당 상황은 선수가 이긴다.
        //그렇지 않은 경우 해당 상황은 후수가 이긴다. (선수가 돌을 1개, 3개, 4개를 제거하더라도 후수가 이기는 상황으로 이어진다.)
        dpArray[i] = !(dpArray[i-1] || dpArray[i-3] || dpArray[i-4]);
    }

    if (dpArray[numStones]) { //dpArray의 원소 값이 1이어서 후수가 이기는 경우-
        printf("CY");
    } else {
        printf("SK");
    }

    return 0;
}
