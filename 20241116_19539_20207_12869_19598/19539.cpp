#include <stdio.h>

/*
    1만큼 성장시키는 물뿌리개를 사용하여, 식물의 키의 "홀짝성"을 변화시킬 수 있다.
    1만큼 성장시키는 물뿌리개를 사용한 다음 남은 식물이 전부
    짝수 만큼 성장하여 목표치에 도달할 수 있는지 여부를 조사한다.
*/

int numTrees;
int heights[100000];
int sumHeights = 0;
int numOdds = 0; //목표값 중 홀수의 개수


void input() {
    scanf("%d", &numTrees);
    for (int i=0; i<numTrees; i++) {
        scanf("%d", &heights[i]);
        sumHeights += heights[i];
        if (heights[i]&1) numOdds++;
    }
}

int main() {
    input();
    if (sumHeights%3!=0) { //목표 합이 3의 배수가 아닌 경우-
        printf("NO");
        return 0;
    }
    int numOnes = sumHeights/3; //물 뿌리기 할 횟수
    //case a. 목표치 중 홀수가 물 뿌리기 횟수보다 큰 경우-
    //1만큼 성장시키는 물뿌리기를 사용하더라도 짝수 차이로 만들 수 없다.
    if (numOdds > numOnes) {
        printf("NO");
        return 0;
    }
    int diff = numOnes - numOdds; //홀수 만큼 키워야 하는 식물에 대해 1만큼 키우고 난 후
                                    //1만큼 성장시키는 물뿌리기의 남은 횟수
    if (diff&1) { //남은 횟수가 홀수라면 목표에 도달할 수 없다.
        printf("NO");
        return 0;
    } else {
        printf("YES");
        return 0;
    }
}
