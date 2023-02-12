#include <iostream>

//sliding window: 두 포인터와 유사하되, 구간의 길이가 고정된 경우

using namespace std;


int main() {
    int N; //배열의 길이
    int K; //슬라이딩 윈도의 폭
    cin >> N >> K;
    int temperatures[N];
    for (int i=0; i<N; i++) {
        cin >> temperatures[i];
    }
    int currentVal = 0;
    for (int i=0; i<K; i++) {
        currentVal+=temperatures[i]; //currentVal의 초기값은 첫 K개의 합으로 정한다.
    }
    int optVal = currentVal;
    for (int i=0; i<N-K; i++) {
        currentVal+=temperatures[i+K]-temperatures[i]; //윈도를 오른쪽으로 옮기면서 해당 온도를 더하고 뺀다.
        if (currentVal>optVal) optVal = currentVal;
    } //i loop
    cout << optVal;
    return 0;
}
