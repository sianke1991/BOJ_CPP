#include <stdio.h>
#include <vector>

using namespace std;

/*
    배열의 길이(최대 100000)에 비해 각 원소가 가질 수 있는 값(1-999)의 범위는 좁다.
    배열 a는 "서로 겹치는 원소"가 많다.
    이 중복을 제거하면 곱셈 연산의 횟수를 줄일 수 있다.
*/

//배열 a의 길이: 값을 입력받는다.
int arrLength;
//배열 a 내 각 원소의 개수: 하나의 값을 두 번을 초과하여 받을 필요는 없다.
int elemCount[1001];
//중복을 제거하여 재구성한 배열 a (하나의 값에 대해 최대 두 번 담을 수 있다,)
vector<int> arr;

void input() {
    scanf("%d", &arrLength);
    for (int i=0; i<arrLength; i++) {
        int elem;
        scanf("%d", &elem);
        elemCount[elem]++;
        if (elemCount[elem]<3)
            arr.push_back(elem);
    } //i loop
    arrLength = arr.size();
    //printf("==============%d\n", arrLength);
    //printf("input done\n");
}

//배열 내 두 원소를 입력 받아, 획득할 수 있는 점수를 계산하여 반환한다.
int point(int num0, int num1) {
    int product = num0*num1;
    int result = 0;
    while (product) {
        result += product%10;
        product /= 10;
    } //while loop
    return result;
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    input();
    int result = 0;
    for (int i=0; i<arrLength; i++) {
        for (int j=i+1; j<arrLength; j++) {
            result = max(result, point(arr[i], arr[j]));
        } //j loop
    } //i loop
    printf("%d", result);
    return 0;
}
