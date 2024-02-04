#include <stdio.h>

int totalPrice;
int numCoinTypes;
int coinValues[110];
int coinNums[110];
int dpArray[110][11000]; //dpArray[i][j]:= ���� i ������ ����Ͽ� j ���� ���� �� �ִ� ����� ��
                        //���� ��� dpArray[3][10000]�� ���� 3 ������ ����Ͽ� 10000���� ����� ����� ���̴�.

int main() {
    scanf("%d", &totalPrice);
    scanf("%d", &numCoinTypes);
    for (int coinIndex=1; coinIndex<=numCoinTypes; coinIndex++) {
        scanf("%d %d", &coinValues[coinIndex], &coinNums[coinIndex]);
    } //coinIndex loop

    dpArray[0][0] = 1; // ���� 0������ ����Ͽ� 0���� ����� ����� ���� 1���� �ִ�. (��� ������ ������� ����)
    for (int i=1; i<=numCoinTypes; i++) {
        for (int j=0; j<=coinNums[i]; j++) {
            for (int l=0; l<=totalPrice-coinValues[i]*j; l++) {
                dpArray[i][l+coinValues[i]*j] += dpArray[i-1][l]; //������ ���� i-1 ������ ������ l���� ������ ����� ������
                                            //���� ���� i ������ ������ l+coinValues[i]*j���� �����ϴ� ����� ���� ���Ѵ�.
            } //l loop (���� ��ġ �� loop)
        } //j loop (���� ���� loop)
    } //i loop (���� ���� loop)

    printf("%d", dpArray[numCoinTypes][totalPrice]);
    return 0;

}
