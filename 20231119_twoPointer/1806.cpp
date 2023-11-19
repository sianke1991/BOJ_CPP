/*
투 포인터: 배열 탐색 시 포인터(인덱스) 두 개를 사용하여 o(n)의 시간복잡도로 문제를 해결하는 방법
이중 for loop를 사용하면 o(n2)가 된다.

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

    int minLength = arrLength+1; //부분합을 targetSum으로 하는 부분수열의 길이 중 최소치
    int st = 0, en = 0; //투 포인터의 시작 인덱스와 끝 인덱스
    int currentLength = 1; //현재 부분 배열의 길이
    int partialSum = arr[0]; //st 이상 en 이하의 부분 수열의 합
    for (st = 0; st<arrLength; st++) {
        while (partialSum<targetSum && en<arrLength-1) {
            en++;
            currentLength++;
            partialSum += arr[en];
        }
        if (partialSum>=targetSum)
            minLength = min(minLength, currentLength);
        partialSum -= arr[st]; //st 값이 1 증가하면 arr[st]는 부분 배열에서 제거된다.
        currentLength--;
    }

    if (minLength>arrLength)
        printf("0");
    else
        printf("%d", minLength);

    return 0;
}
