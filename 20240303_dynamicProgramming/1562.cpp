#include <stdio.h>
#include <bits/stdc++.h>
#define MOD 1000000000LL

using namespace std;
/**
 * dpArray[i][j]: 길이가 i이고 마지막 자리수가 j인 계단 수의 개수
 * minDigit와 maxDigit에 따라 계단 수의 개수를 분리하여 관리한다.
 */
map<pair<int, int>, long long> dpArray[101][10];

/*
    수 두 개를 입력받아 pair<int, int>로 반환한다.
    pair의 first는 입력받은 값 중 작은 값, pair의 second는 입력받은 값 중 큰 값이다.
 */
pair<int, int> makePair(int digit0, int digit1) {
    if (digit0<digit1) return {digit0, digit1};
    else return {digit1, digit0};
}

/*
 * 기존의 계단 수에 숫자 하나가 추가 되었을 때,
 * 새로 생성된 계단 수의 최소 digit, 최대 digit 정보를 담은 pair<int, int>를 반환한다.
 */
pair<int, int> makePair(int digit, pair<int, int> digits) {
    if (digit<digits.first) return {digit, digits.second};
    else if (digit>digits.second) return {digits.first, digit};
    else return {digits.first, digits.second};
}



int main() {
    //초기값 설정
    for (int i=1; i<=9; i++) {
        dpArray[1][i][{i, i}] = 1;
    }

    int numDigits;
    scanf("%d", &numDigits);

    //점화식
    for (int i=1; i<numDigits; i++) {
        int j=0;
        for (pair<pair<int, int>, long long> entry:dpArray[i][j]) {
            dpArray[i+1][1][makePair(1, entry.first)] += entry.second;
            dpArray[i+1][1][makePair(1, entry.first)] %= MOD;
        } //entry loop

        for (j=1; j<=8; j++) {
            for (pair<pair<int, int>, long long> entry:dpArray[i][j]) {
                dpArray[i+1][j-1][makePair(j-1, entry.first)] += entry.second;
                dpArray[i+1][j-1][makePair(j-1, entry.first)] %= MOD;
                dpArray[i+1][j+1][makePair(j+1, entry.first)] += entry.second;
                dpArray[i+1][j+1][makePair(j+1, entry.first)] %= MOD;
            } //entry loop
        } //j loop (계단 수의 마지막 자리수에 대한 loop)

        j = 9;
        for (pair<pair<int, int>, long long> entry:dpArray[i][j]) {
            dpArray[i+1][8][makePair(8, entry.first)] += entry.second;
            dpArray[i+1][8][makePair(8, entry.first)] %= MOD;
        }
    } //i loop (계단 수의 자리수에 대한 loop)

    long long result = 0LL;
    for (int i=0; i<10; i++) {
        result += dpArray[numDigits][i][{0, 9}]; //최소 digit가 0이고, 최대 digit가 9 이면, 0부터 9까지 모든 숫자를 사용한 것이 된다.
        result %= MOD;
    } //i loop (numDigits 자리 계단 수라 하더라도 끝 자리 숫자에 따라 그 개수가 분리되어 있으므로, 총 계단 수 개수를 구하려면 합산이 필요하다.)

    printf("%lld", result);
    return 0;
}
