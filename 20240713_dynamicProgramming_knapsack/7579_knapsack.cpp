#include <stdio.h>

//실행 중인 앱의 개수
int numItems;
//확보해야 할 메모리 양
int targetValue;
//각 앱이 사용중인 메모리 양
int valueOf[100];
//각 앱이 재실행 시 필요한 비용
int costOf[100];
//dpArray[i] := 비용 i 시 확보할 수 있는 메모리 양의 최대치
//이 값이 targetValue가 되는 최소의 인덱스를 구한다.
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

    //dpArray[i]>=targetValue를 만족시키는 최소의 i를 구한다.
    //이 과정에 이진 탐색을 사용할 수 있을까?
    for (int w=0; w<=10000; w++) {
        if (dpArray[w]>=targetValue) {
            printf("%d", w);
            return 0;
        }
    }

    return 1;
}
