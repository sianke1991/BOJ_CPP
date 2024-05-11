#include <bits/stdc++.h>
#include <stdio.h>
#define INFINITE 2147483647

using namespace std;

// ������ ����
int numBulbs;
// ����ġ ���� �� ������ ����
char originalState[100001];
// ��ǥ ����
char targetState[100001];
// currentState[0]: 0 �� ����ġ�� �������� ���� �� ������ ����, currentState[1]: 0�� ����ġ�� ������ �� ������ ����
char currentState[2][100001];
// numSwitchesMoved[0]: 0�� ����ġ�� ������ �� ����ġ�� ������ Ƚ��, numSwitchesMoved[1]: 0�� ����ġ�� ������ �� ������ ����
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

    //originalState -> currentState[0]. currentState[1] �� �����Ѵ�.
    for (int i=0; i<numBulbs; i++) {
        currentState[0][i] = originalState[i];
        currentState[1][i] = originalState[i];
    }

    // 0�� ����ġ�� �������� �ʰ� targetState�� ������ ����.
    for (int i=1; i<numBulbs; i++) {
        if (targetState[i-1] != currentState[0][i-1]) {
            numSwitchesMoved[0]++;
            moveSwitchAt(i, currentState[0]);
        }
    }
    if (currentState[0][numBulbs-1]!=targetState[numBulbs-1]) //������ ������ ��ġ���� ������, target�� ������ �� ���� ���̴�.
        numSwitchesMoved[0] = INFINITE;

    // 0�� ����ġ�� �����ϰ� targetState�� ������ ����.
    numSwitchesMoved[1]++;
    moveSwitchAt(0, currentState[1]);
    for (int i=1; i<numBulbs; i++) {
        if (targetState[i-1] != currentState[1][i-1]) {
            numSwitchesMoved[1]++;
            moveSwitchAt(i, currentState[1]);
        }
    }
    if (currentState[1][numBulbs-1]!=targetState[numBulbs-1]) //������ ������ ��ġ���� ������, target�� ������ �� ���� ���̴�.
        numSwitchesMoved[1] = INFINITE;

    int minNumSwitchesMoved = min(numSwitchesMoved[0], numSwitchesMoved[1]);
    if (minNumSwitchesMoved==INFINITE)
        printf("-1");
    else
        printf("%d", minNumSwitchesMoved);

    return 0;
}
