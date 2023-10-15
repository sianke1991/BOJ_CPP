#include <bits/stdc++.h>

using namespace std;

//timeReq[i]: i번째 일을 하는데 소요되는 시간 (day)
int timeReq[16];
//payRcv[i]: i번째 일을 할 때 받을 수 있는 보수
int payRcv[16];
//dpCache[i]: i번째 날, i번째 일을 하기 전에 받은 보수의 최대치
int dpCache[16];

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
        for (int j=i+timeReq[i]; j<=N; j++) { //i 번째 일을 잡으면 그 보수는 i+timeReq[i] 번째 날에 받는 것으로 계산한다.
            //마지막 날에 종료되는 일도 보수를 받을 수 있으므로 dpCache[N]에 값을 저장한다.
            //예를 들어 퇴사 2일 전에 2일 걸리는 일을 시작한 경우 그 보수는 dpCache[N]에 더해진다.
            dpCache[j] = max(dpCache[j], dpCache[i]+payRcv[i]); //i 번째 일을 하면 받은 보수는 dpCache[i]+payRcv[i]이므로 이 값을 dpCache[j]와 비교하여 최대치를 dpCache에 저장한다.
        } //j loop
    } //i loop

    cout << dpCache[N];

    return 0;
}
