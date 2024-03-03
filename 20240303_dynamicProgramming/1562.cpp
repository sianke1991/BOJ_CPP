#include <stdio.h>
#include <bits/stdc++.h>
#define MOD 1000000000LL

using namespace std;
/**
 * dpArray[i][j]: ���̰� i�̰� ������ �ڸ����� j�� ��� ���� ����
 * minDigit�� maxDigit�� ���� ��� ���� ������ �и��Ͽ� �����Ѵ�.
 */
map<pair<int, int>, long long> dpArray[101][10];

/*
    �� �� ���� �Է¹޾� pair<int, int>�� ��ȯ�Ѵ�.
    pair�� first�� �Է¹��� �� �� ���� ��, pair�� second�� �Է¹��� �� �� ū ���̴�.
 */
pair<int, int> makePair(int digit0, int digit1) {
    if (digit0<digit1) return {digit0, digit1};
    else return {digit1, digit0};
}

/*
 * ������ ��� ���� ���� �ϳ��� �߰� �Ǿ��� ��,
 * ���� ������ ��� ���� �ּ� digit, �ִ� digit ������ ���� pair<int, int>�� ��ȯ�Ѵ�.
 */
pair<int, int> makePair(int digit, pair<int, int> digits) {
    if (digit<digits.first) return {digit, digits.second};
    else if (digit>digits.second) return {digits.first, digit};
    else return {digits.first, digits.second};
}



int main() {
    //�ʱⰪ ����
    for (int i=1; i<=9; i++) {
        dpArray[1][i][{i, i}] = 1;
    }

    int numDigits;
    scanf("%d", &numDigits);

    //��ȭ��
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
        } //j loop (��� ���� ������ �ڸ����� ���� loop)

        j = 9;
        for (pair<pair<int, int>, long long> entry:dpArray[i][j]) {
            dpArray[i+1][8][makePair(8, entry.first)] += entry.second;
            dpArray[i+1][8][makePair(8, entry.first)] %= MOD;
        }
    } //i loop (��� ���� �ڸ����� ���� loop)

    long long result = 0LL;
    for (int i=0; i<10; i++) {
        result += dpArray[numDigits][i][{0, 9}]; //�ּ� digit�� 0�̰�, �ִ� digit�� 9 �̸�, 0���� 9���� ��� ���ڸ� ����� ���� �ȴ�.
        result %= MOD;
    } //i loop (numDigits �ڸ� ��� ���� �ϴ��� �� �ڸ� ���ڿ� ���� �� ������ �и��Ǿ� �����Ƿ�, �� ��� �� ������ ���Ϸ��� �ջ��� �ʿ��ϴ�.)

    printf("%lld", result);
    return 0;
}
