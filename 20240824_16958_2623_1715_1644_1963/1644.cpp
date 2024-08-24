/*
    4000000 이하의 소수를 찾아서 리스트에 넣은 뒤,
    투 포인터 방법을 사용한다.
    left 인덱스 이상, right 인덱스 미만에 속한 소수의 합을 관리한다,
    이 소수의 합이 목표치보다 낮으면 right 인덱스를 하나 증가시킨다.
    이 소수의 합이 목표치보다 크면 left 인덱스를 하나 증가시킨다.
*/

#include <stdio.h>
#include <vector>
using namespace std;

bool isNotPrime[4000001] = {true, true};
vector<int> primes;

void getPrimes() {
    for (int i=2; i<=2000; i++) {
        if (isNotPrime[i]) continue;
        for (int j=2*i; j<=4000000; j+=i) isNotPrime[j] = true;
    }
    for (int i=2; i<=4000000; i++) {
        if (!isNotPrime[i]) primes.push_back(i);
    }
}


int main() {
    int target;
    scanf("%d", &target);

    getPrimes();
    int numPrimes = primes.size();
    long long cnt = 0;
    int left = 0, right = 1, sum = primes[0];
    while (left<numPrimes && primes[left]<=target) { //left<numPrimes 조건이 들어가지 않으면 out of bounds 런타임 에러가 떨어진다.
        while (right<numPrimes && sum<target) {
            sum += primes[right];
            right++;
        } //inner while loop
        if (sum==target) cnt++;
        sum -= primes[left];
        left++;
    } //outer while loop
    printf("%lld", cnt);
    return 0;
}
