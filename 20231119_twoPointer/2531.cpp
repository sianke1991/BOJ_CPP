#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/*
2531: 회전 초밥 문제는 13144: List of Unique Number와 달리
하나의 아이템을 여러 개 선택할 수 있으므로 bool 배열이 아닌 int 배열을 사용해야 한다.
*/

int typeAt[30001]; //각 접시에 올려진 초밥의 종류
int selected[30001]; //각 초밥 종류에 대해 해당 초밥을 선택한 개수
int sz = 0; //현재 선택된 초밥 종류의 개수

/**
 * 인자로 받은 번호에 해당하는 초밥을 선택한다.
 */
void add(int typeNumber) {
    if (selected[typeNumber]==0) { //선택하지 않은 초밥을 선택할 경우
        selected[typeNumber] = 1;
        sz++;
    } else { //이미 선택한 초밥을 또 선택한 경우
        selected[typeNumber]++;
    }
}

/**
 * 인자로 받은 번호에 해당하는 초밥을 제거한다.
 */
void remove(int typeNumber) {
    if (selected[typeNumber]==1) { //딱 하나 선택한 초밥을 제거할 경우
        selected[typeNumber] = 0;
        sz--;
    } else if (selected[typeNumber]>1) { //둘 이상 선택한 초밥을 제거할 경우
        selected[typeNumber]--;
    }
}

/**
 * 선택한 초밥의 종류 개수를 반환한다. (쿠폰 번호를 입력받는다.)
 */
int size(int couponNumber) {
    if (selected[couponNumber]!=0) //쿠폰 번호에 해당하는 초밥을 선택한 경우
        return sz;
    else //쿠폰 번호에 해당하는 초밥을 선택하지 않은 경우
        return sz+1;
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    int numDishes; //회전 초밥 벨트에 놓인 접수의 수
    int numTypes; //초밥의 가짓수
    int consecutiveDishSize; //연속해서 먹는 접시의 수
    int couponNumber; //쿠폰 번호

    scanf("%d %d %d %d", &numDishes, &numTypes, &consecutiveDishSize, &couponNumber);

    for (int i=0; i<numDishes; i++) {
        scanf("%d", &typeAt[i]);
    }

    int st=0, ed=consecutiveDishSize-1;
    for (int i=0; i<consecutiveDishSize; i++) {
        add(typeAt[i]);
    }
    int optResult = size(couponNumber);

    for (st=1; st<numDishes; st++) {
        ed = (ed+1)%numDishes;
        add(typeAt[ed]);
        remove(typeAt[st-1]);
        optResult = max(optResult, size(couponNumber));
    } //st loop

    printf("%d", optResult);
    return 0;
}
