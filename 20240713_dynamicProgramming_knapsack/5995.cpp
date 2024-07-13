#include <stdio.h>

// 0/1knapsack problem
//dpArray[i] := �Ϸ翡 ������ �� �ִ� ���� i�� �� ���� ������ �� �ִ� ���� �ִ�ġ
int dpArray[45001];
//�� ������ �� (�����δ� weightOf[500] ���� �����ص� �ȴ�.
int weightOf[45001];

/**
 �� ������ 0/1 �賶 ������ �� �� �ִ�.
 �� ���� ������ ���Ե�, ��ġ�� �ش� ���� ������ ���� �ȴ�.
 */

int max(int num0, int num1) {
	return num0>num1 ? num0:num1;
}

int main() {
	//H: max capacity
	//N: num items
	int H, N;
	scanf("%d %d", &H, &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &weightOf[i]);
	}

	for (int itemIndex=0; itemIndex<N; itemIndex++) {
		for (int w=H; w>=weightOf[itemIndex]; w--) {
			dpArray[w] = max(dpArray[w], dpArray[w-weightOf[itemIndex]]+weightOf[itemIndex]);
		}
	}

	printf("%d", dpArray[H]);

	return 0;
}
