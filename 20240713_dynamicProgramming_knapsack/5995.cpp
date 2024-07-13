#include <stdio.h>

// 0/1knapsack problem
//dpArray[i] := 하루에 섭취할 수 있는 양이 i일 때 실제 섭취할 수 있는 양의 최대치
int dpArray[45001];
//각 건초의 양 (실제로는 weightOf[500] 으로 선언해도 된다.
int weightOf[45001];

/**
 이 문제는 0/1 배낭 문제로 볼 수 있다.
 각 건초 더미의 무게도, 가치도 해당 건초 더미의 양이 된다.
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
