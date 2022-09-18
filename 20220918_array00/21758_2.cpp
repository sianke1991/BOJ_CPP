#include <iostream>
using namespace std;

int N; //장소의 개수
int honeyArr[100000] = {0};
int sumArr[100000]   = {0}; //인덱스 0부터 꿀의 합 eg. sumArr[3]은 인덱스 0, 1, 2, 3의 꿀의 합
int maxTotal = -1;

//벌통이 가운데 위치한 경우: 두 벌은 양 끝에 위치해야 꿀을 최대로 딸 수 있다.
//두 벌의 위치를 고정시키고 벌통의 위치만 변경시켜서 (꿀의 양의) 최대치를 조회한다.
void updateMaxTotalBTB(int i) {
    int result = 0;
    result += sumArr[i]-sumArr[0];
    result += sumArr[N-2]-sumArr[i-1];
    if (maxTotal < result) maxTotal = result;
}

//벌통이 한쪽 끝에 위치한 경우: 다른 두 벌 중 하나는 다른쪽 끝에 위치해야 꿀을 최대로 딸 수 있다.
//두 벌 중 가운데 벌의 위치만 변경시켜서 최대치를 조회한다.
void updateMaxTotalBBT(int i) {
    int result = 0;
    result += sumArr[N-1]-sumArr[0] - honeyArr[i];
    result += sumArr[N-1]-sumArr[i];
    if (maxTotal < result) maxTotal = result;
}

void updateMaxTotalTBB(int i) {
    int result = 0;
    result += sumArr[i-1];
    result += sumArr[N-2] - honeyArr[i];
    if (maxTotal < result) maxTotal = result;
}

int main() {
    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> honeyArr[i];
    }
    int partialSum = 0;
    for (int i=0; i<N; i++) {
        partialSum += honeyArr[i];
        sumArr[i] = partialSum;
    }

    //case0. BTB
    for (int i=1; i<N-1; i++) {
        updateMaxTotalBTB(i);
    }

    //case1. BBT
    for (int i=1; i<N-1; i++) {
        updateMaxTotalBBT(i);
    }

    //case2. TBB
    for (int i=1; i<N-1; i++) {
        updateMaxTotalTBB(i);
    }

    cout << maxTotal;
    return 0;
}
