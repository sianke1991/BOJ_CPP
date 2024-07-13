#include <stdio.h>

//각 수강 과목에 투자해야 할 시간
int weightOf[1000];
//각 수강 과목의 중요도
int valueOf[1000];
//dpArray[i] := 투자할 시간 i에 대해 얻을 수 있는 최대 중요도
int dpArray[10001];
//수강에 투자할 수 있는 최대 시간
int maxCapacity;
//수강 과목의 개수
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
