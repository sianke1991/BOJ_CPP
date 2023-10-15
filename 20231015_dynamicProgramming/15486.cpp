#include <iostream>

using namespace std;

//timeReq[i]: i번째 일을 하는데 소요되는 시간 (day)
int timeReq[1500001];
//payRcv[i]: i번째 일을 할 때 받을 수 있는 보수
int payRcv[1500001];
//dpCache[i]: i번째 날, i번째 일을 하기 전에 받은 보수의 최대치
int dpCache[1500001];
//현재 dp를 진행한 시점에서의 dpCache의 최대치
int localMax = 0;
int globalMax = 0;

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}


int main() {
    int N; //날짜 수
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> timeReq[i];
        cin >> payRcv[i];
    } //i loop

    for (int i=0; i<N; i++) {
        localMax = max(localMax, dpCache[i]);
        int j=i+timeReq[i]; //i 번째 일을 잡으면 그 보수는 i+timeReq[i] 번째 날에 받는 것으로 계산한다.
        if (j>N) continue; //기한을 넘는 일은 고려할 필요가 없다.
        dpCache[j] = max(dpCache[j], localMax+payRcv[i]);
        globalMax = max(globalMax, dpCache[j]);
    }

    cout << globalMax;

    return 0;
}
