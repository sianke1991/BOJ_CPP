#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M; //N=정수의 개수, M=두 정수의 차이의 최소치(목표)
    cin >> N >> M;
    vector<int> numbers;
    {
        int num;
        for (int i=0; i<N; i++) {
            cin >> num;
            numbers.push_back(num);
        } //i loop
    }
    sort(numbers.begin(), numbers.end());

    int leftIdx = 0, rightIdx = 0;
    int optVal = 2147483647, currentVal;

    while (leftIdx<N && rightIdx<N) {
        currentVal = numbers[rightIdx]-numbers[leftIdx];
        if (currentVal>=M) { //optVal을 갱신하는 로직
            optVal = min(optVal, currentVal);
        }

        if (currentVal>M) { //두 정수의 차이가 M보다 큰 경우 leftIdx를 1 증가시켜서 차이를 감소시켜야 한다.
            leftIdx = leftIdx+1;
        } else if (currentVal<M) { //두 정수의 차이가 M보다 작은 경우 rightIdx를 1 증가시켜서 차이를 증가시켜야 한다.
            rightIdx = rightIdx+1;
        } else { //두 정수의 차이가 M인 경우 최적을 찾은 것이다.
            break;
        }
    } //while loop
    cout << optVal;
    return 0;
}
