#include <stdio.h>

/*
    1��ŭ �����Ű�� ���Ѹ����� ����Ͽ�, �Ĺ��� Ű�� "Ȧ¦��"�� ��ȭ��ų �� �ִ�.
    1��ŭ �����Ű�� ���Ѹ����� ����� ���� ���� �Ĺ��� ����
    ¦�� ��ŭ �����Ͽ� ��ǥġ�� ������ �� �ִ��� ���θ� �����Ѵ�.
*/

int numTrees;
int heights[100000];
int sumHeights = 0;
int numOdds = 0; //��ǥ�� �� Ȧ���� ����


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
    if (sumHeights%3!=0) { //��ǥ ���� 3�� ����� �ƴ� ���-
        printf("NO");
        return 0;
    }
    int numOnes = sumHeights/3; //�� �Ѹ��� �� Ƚ��
    //case a. ��ǥġ �� Ȧ���� �� �Ѹ��� Ƚ������ ū ���-
    //1��ŭ �����Ű�� ���Ѹ��⸦ ����ϴ��� ¦�� ���̷� ���� �� ����.
    if (numOdds > numOnes) {
        printf("NO");
        return 0;
    }
    int diff = numOnes - numOdds; //Ȧ�� ��ŭ Ű���� �ϴ� �Ĺ��� ���� 1��ŭ Ű��� �� ��
                                    //1��ŭ �����Ű�� ���Ѹ����� ���� Ƚ��
    if (diff&1) { //���� Ƚ���� Ȧ����� ��ǥ�� ������ �� ����.
        printf("NO");
        return 0;
    } else {
        printf("YES");
        return 0;
    }
}
