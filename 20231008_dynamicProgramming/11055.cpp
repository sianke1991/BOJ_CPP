#include <iostream>

using namespace std;
//입력받는 수열
int sequence[1002];
//dpArray[i]:= sequence[i]를 최대치로 갖는 부분 증가 수열의 합의 최대치
int dpArray[1002];
int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> sequence[i];
        dpArray[i] = sequence[i];
    } //i loop

    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            //sequence[i]를 최대치로 갖는 부분 증가 수열을 고려해야 하므로,
            //sequence[j]>=sequence[i]를 만족하는 sequence[j]는 무시한다.
            if (sequence[j]>=sequence[i])
                continue;

            //dpArray[i] = max(dpArray[j]+sequence[i]) (for all j<i, sequence[j]<sequence[i])
            // => 위 등식 설명
            // dpArray[j]는 sequence[j]를 최대치로 갖는 부분 증가 수열의 합의 최대치이다.
            // j<i이고, sequence[j]<sequence[i]를 만족한다면 dpArray[j]에 sequence[i]를 더하여
            // sequence[i]를 최대치로 갖는 부분 증가 수열의 합을 구할 수 있다.
            // 하지만 dpArray[i]는 sequence[i]를 최대치로 갖는 부분 증가 수열의 합의 "최대치"이므로,
            // 가능한 j에 대해 dpArray[j]+sequence[i]를 모두 구해 그 중 최대치가 dpArray[i]가 된다.
            //이 등식을 구현하기 위해서 주어진 i에 대해 j loop가 필요하다.
            //이 값을 모든 i에 대해서 구해야 하므로 결국 2중 for loop가 필요하다.
            if (dpArray[i]<dpArray[j]+sequence[i])
                dpArray[i] = dpArray[j]+sequence[i];
        } //j loop
    } //i loop

    int optResult = 0;
    for (int elem:dpArray) {
        if (elem>optResult)
            optResult = elem;
    }
    cout << optResult << '\n';
    return 0;
}
