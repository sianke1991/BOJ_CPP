#include <iostream>
#include <algorithm>
#include <cstdlib> //for the function abs

using namespace std;

int main() {
    int N; //수열의 길이
    cin >> N;
    int solution[N];
    for (int i=0; i<N; i++) {
        cin >> solution[i];
    }
    sort(solution, solution+N);
    int idxLeft = 0;
    int idxRight = N-1;
    int currentVal, optVal=2147483647;
    while (idxRight>idxLeft) {
        currentVal = solution[idxLeft]+solution[idxRight];
        if (abs(currentVal)<abs(optVal)) optVal = currentVal;

        if (currentVal<0) { //용액 합계가 음수인 경우 idxLeft를 증가시킨다.
            idxLeft++;
        } else if (currentVal>0) { //용액 합계가 양수인 경우 idxRight를 감소시킨다.
            idxRight--;
        } else { //용액 합계가 0인 경우 최적을 찾은 것이다.
            break;
        }
    } //while loop

    cout << optVal;
    return 0;
}
