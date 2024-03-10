#include <stdio.h>
#define MOD 1000000000LL

/*
    dpArray[n][m][b]:= ���� n, ������ �ڸ��� m, ����� ���� ���� b�� ��ܼ� ����
    ����� ���� ������ 10 ��Ʈ ������ ����Ѵ�. ���� ��� ���� 2, 3, 4�� ����ߴٸ�
    b = 0b0000011100
    �� ����Ѵ�.
*/
long long dpArray[101][10][1024];

/*
    2�� �ŵ������� ��ȯ�Ѵ�.
*/
int twoTo(int power) {
    return 1 << power;
}

/*
    bits���� index ��ġ�� ��Ʈ�� �� ����� ��ȯ�Ѵ�.
*/
int turnOnBitAt(int index, int bits) {
    return twoTo(index) | bits;
}


int main() {
    //�ʱ�ȭ ����
    for (int i=1; i<=9; i++) {
        dpArray[1][i][twoTo(i)] = 1LL;
    }

    int numDigits;
    scanf("%d", &numDigits);

    //��ȭ��
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
        } //j loop (��� ���� ������ �ڸ����� ���� loop)

        j = 9;
        for (int k=0; k<1024; k++) {
            dpArray[i+1][8][turnOnBitAt(8, k)] += dpArray[i][j][k];
            dpArray[i+1][8][turnOnBitAt(8, k)] %= MOD;
        }

    } //i loop (numDigits �ڸ� ��� ���� �ϴ��� �� �ڸ� ���ڿ� ���� �� ������ �и��Ǿ� �����Ƿ�, �� ��� �� ������ ���Ϸ��� �ջ��� �ʿ��ϴ�.)


    long long result = 0LL;
    for (int i=0; i<10; i++) {
        result += dpArray[numDigits][i][1023]; //0���� 9���� ��� ���ڸ� ����ϴ� ��ܼ��� ��Ƹ���.
        result %= MOD;
    }

    printf("%lld", result);
    return 0;
}
