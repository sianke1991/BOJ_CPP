#include <bits/stdc++.h>
#include <stdio.h>
#define INFINITE 2147483647

using namespace std;

// 전구의 개수
int numBulbs;
// 스위치 조작 전 전구의 상태
char originalState[100001];
// 목표 상태
char targetState[100001];
// currentState[0]: 0 번 스위치를 조작하지 않을 때 전구의 상태, currentState[1]: 0번 스위치를 조작할 때 전구의 상태
char currentState[2][100001];
// numSwitchesMoved[0]: 0번 스위치를 조작할 때 스위치를 조작한 횟수, numSwitchesMoved[1]: 0번 스위치를 조작할 때 전구의 상태
int numSwitchesMoved[2];

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

void moveSwitchAt(int index, char* state) {
    if (index==0) {
        (*(state)) ^= 1;
        (*(state+1)) ^= 1;
    } else if (index==numBulbs-1) {
        (*(state+numBulbs-1)) ^= 1;
        (*(state+numBulbs-2)) ^= 1;
    } else {
        (*(state+index-1)) ^= 1;
        (*(state+index)) ^= 1;
        (*(state+index+1)) ^= 1;
    }
}


int main() {
    scanf("%d", &numBulbs);
    scanf("%s", originalState);
    scanf("%s", targetState);

    //originalState -> currentState[0]. currentState[1] 로 복사한다.
    for (int i=0; i<numBulbs; i++) {
        currentState[0][i] = originalState[i];
        currentState[1][i] = originalState[i];
    }

    // 0번 스위치를 조작하지 않고 targetState에 도달해 본다.
    for (int i=1; i<numBulbs; i++) {
        if (targetState[i-1] != currentState[0][i-1]) {
            numSwitchesMoved[0]++;
            moveSwitchAt(i, currentState[0]);
        }
    }
    if (currentState[0][numBulbs-1]!=targetState[numBulbs-1]) //마지막 전구가 일치하지 않으면, target에 도달할 수 없는 것이다.
        numSwitchesMoved[0] = INFINITE;

    // 0번 스위치를 조작하고 targetState에 도달해 본다.
    numSwitchesMoved[1]++;
    moveSwitchAt(0, currentState[1]);
    for (int i=1; i<numBulbs; i++) {
        if (targetState[i-1] != currentState[1][i-1]) {
            numSwitchesMoved[1]++;
            moveSwitchAt(i, currentState[1]);
        }
    }
    if (currentState[1][numBulbs-1]!=targetState[numBulbs-1]) //마지막 전구가 일치하지 않으면, target에 도달할 수 없는 것이다.
        numSwitchesMoved[1] = INFINITE;

    int minNumSwitchesMoved = min(numSwitchesMoved[0], numSwitchesMoved[1]);
    if (minNumSwitchesMoved==INFINITE)
        printf("-1");
    else
        printf("%d", minNumSwitchesMoved);

    return 0;
}
