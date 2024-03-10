#include <stdio.h>
#define MOD 1000000000LL

/*
    dpArray[n][m][b]:= 길이 n, 마지막 자리수 m, 사용한 숫자 종류 b의 계단수 개수
    사용한 숫자 종류는 10 비트 정수를 사용한다. 예를 들어 숫자 2, 3, 4를 사용했다면
    b = 0b0000011100
    을 사용한다.
*/
long long dpArray[101][10][1024];

/*
    2의 거듭제곱을 반환한다.
*/
int twoTo(int power) {
    return 1 << power;
}

/*
    bits에서 index 위치의 비트를 켠 결과를 반환한다.
*/
int turnOnBitAt(int index, int bits) {
    return twoTo(index) | bits;
}


int main() {
    //초기화 조건
    for (int i=1; i<=9; i++) {
        dpArray[1][i][twoTo(i)] = 1LL;
    }

    int numDigits;
    scanf("%d", &numDigits);

    //점화식
    for (int i=1; i<numDigits; i++) {
        int j=0;
        for (int k=0; k<1024; k++) {
            dpArray[i+1][1][turnOnBitAt(1, k)] += dpArray[i][j][k];
            dpArray[i+1][1][turnOnBitAt(1, k)] %= MOD;
        }

        for (j=1; j<=8; j++) {
            for (int k=0; k<1024; k++) {
                dpArray[i+1][j-1][turnOnBitAt(j-1, k)] += dpArray[i][j][k];
                dpArray[i+1][j-1][turnOnBitAt(j-1, k)] %= MOD;
                dpArray[i+1][j+1][turnOnBitAt(j+1, k)] += dpArray[i][j][k];
                dpArray[i+1][j+1][turnOnBitAt(j+1, k)] %= MOD;
            }
        } //j loop (계단 수의 마지막 자리수에 대한 loop)

        j = 9;
        for (int k=0; k<1024; k++) {
            dpArray[i+1][8][turnOnBitAt(8, k)] += dpArray[i][j][k];
            dpArray[i+1][8][turnOnBitAt(8, k)] %= MOD;
        }

    } //i loop (numDigits 자리 계단 수라 하더라도 끝 자리 숫자에 따라 그 개수가 분리되어 있으므로, 총 계단 수 개수를 구하려면 합산이 필요하다.)


    long long result = 0LL;
    for (int i=0; i<10; i++) {
        result += dpArray[numDigits][i][1023]; //0부터 9까지 모든 숫자를 사용하는 계단수만 헤아린다.
        result %= MOD;
    }

    printf("%lld", result);
    return 0;
}
