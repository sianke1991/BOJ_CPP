#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, S; //N: 수열의 길이, S: 부분합 목표치 (부분합이 S 이상이 되어야 한다.)
    cin >> N >> S;
    vector<int> numbers; //길이 N 짜리 수열
    {
        int number;
        for (int i=0; i<N; i++) {
            cin >> number;
            numbers.push_back(number);
        } //i loop
    }

    int leftIdx = 0, rightIdx = 0, currentPartialSum = numbers[0], currentLength = 1;
    int optLength = 2147483647;

    while (leftIdx<N) {
        //cout << leftIdx << ", " << rightIdx << ", " << currentPartialSum << "\n";
        if (currentPartialSum>=S) { //optLength를 갱신하는 로직
            optLength = min(optLength, currentLength);
        }

        if (currentPartialSum>=S) { //현재 부분합이 S보다 큰 경우 leftIdx를 1 증가시켜서 현재 구간의 길이를 줄여준다.
            currentPartialSum-=numbers[leftIdx];
            leftIdx++;
            currentLength--;
        } else if (currentPartialSum<S) { //현재 부분합이 S보다 작은 경우 rightIdx를 1 증가시켜서 부분합을 증가시켜준다.
            if (rightIdx>=N-1) break;
            rightIdx++;
            currentPartialSum+=numbers[rightIdx];
            currentLength++;

        }
        /*
            현재 부분합이 정확하게 S 더라도 현재 최적을 찾았다고 볼 수 없기 때문에
            이 경우 break 처리는 하지 않는다.
        */
    } //while loop
    if (optLength<=N) cout << optLength;
    else cout << 0;
    return 0;
}
