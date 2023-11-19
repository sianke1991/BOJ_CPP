/*
�� ������: �迭 Ž�� �� ������(�ε���) �� ���� ����Ͽ� o(n)�� �ð����⵵�� ������ �ذ��ϴ� ���
���� for loop�� ����ϸ� o(n2)�� �ȴ�.

#2230
*/


#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int arr[100005];

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int main() {
    int arrLength, targetSum;
    scanf("%d %d", &arrLength, &targetSum);
    for (int i=0; i<arrLength; i++) {
        scanf("%d", &arr[i]);
    }

    int minLength = arrLength+1; //�κ����� targetSum���� �ϴ� �κм����� ���� �� �ּ�ġ
    int st = 0, en = 0; //�� �������� ���� �ε����� �� �ε���
    int currentLength = 1; //���� �κ� �迭�� ����
    int partialSum = arr[0]; //st �̻� en ������ �κ� ������ ��
    for (st = 0; st<arrLength; st++) {
        while (partialSum<targetSum && en<arrLength-1) {
            en++;
            currentLength++;
            partialSum += arr[en];
        }
        if (partialSum>=targetSum)
            minLength = min(minLength, currentLength);
        partialSum -= arr[st]; //st ���� 1 �����ϸ� arr[st]�� �κ� �迭���� ���ŵȴ�.
        currentLength--;
    }

    if (minLength>arrLength)
        printf("0");
    else
        printf("%d", minLength);

    return 0;
}
