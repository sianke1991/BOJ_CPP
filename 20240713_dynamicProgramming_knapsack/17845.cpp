#include <stdio.h>

//�� ���� ���� �����ؾ� �� �ð�
int weightOf[1000];
//�� ���� ������ �߿䵵
int valueOf[1000];
//dpArray[i] := ������ �ð� i�� ���� ���� �� �ִ� �ִ� �߿䵵
int dpArray[10001];
//������ ������ �� �ִ� �ִ� �ð�
int maxCapacity;
//���� ������ ����
int numItems;

int max(int num0, int num1) {
	return num0>num1 ? num0 : num1;
}

int main() {
	scanf("%d %d", &maxCapacity, &numItems);
	for (int i=0; i<numItems; i++)
		scanf("%d %d", &valueOf[i], &weightOf[i]);

	for (int itemIndex=0; itemIndex<numItems; itemIndex++) {
		for (int w=maxCapacity; w>=weightOf[itemIndex]; w--) {
			dpArray[w] = max(dpArray[w], dpArray[w-weightOf[itemIndex]]+valueOf[itemIndex]);
		} //w loop
	} //itemIndex loop

	printf("%d", dpArray[maxCapacity]);
	return 0;
}
