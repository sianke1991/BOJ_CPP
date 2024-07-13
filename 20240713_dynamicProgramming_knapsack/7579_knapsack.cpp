#include <stdio.h>

//���� ���� ���� ����
int numItems;
//Ȯ���ؾ� �� �޸� ��
int targetValue;
//�� ���� ������� �޸� ��
int valueOf[100];
//�� ���� ����� �� �ʿ��� ���
int costOf[100];
//dpArray[i] := ��� i �� Ȯ���� �� �ִ� �޸� ���� �ִ�ġ
//�� ���� targetValue�� �Ǵ� �ּ��� �ε����� ���Ѵ�.
int dpArray[10001];

int max(int num0, int num1) {
    return num0>num1? num0 : num1;
}

int main() {
    scanf("%d %d", &numItems, &targetValue);
    for (int i=0; i<numItems; i++)
        scanf("%d", &valueOf[i]);
    for (int i=0; i<numItems; i++)
        scanf("%d", &costOf[i]);

    for (int itemIndex=0; itemIndex<numItems; itemIndex++) {
        for (int w=10000; w>=costOf[itemIndex]; w--) {
            dpArray[w] = max(dpArray[w], dpArray[w-costOf[itemIndex]]+valueOf[itemIndex]);
        } //w loop
    } //itemIndex loop

    //dpArray[i]>=targetValue�� ������Ű�� �ּ��� i�� ���Ѵ�.
    //�� ������ ���� Ž���� ����� �� ������?
    for (int w=0; w<=10000; w++) {
        if (dpArray[w]>=targetValue) {
            printf("%d", w);
            return 0;
        }
    }

    return 1;
}
