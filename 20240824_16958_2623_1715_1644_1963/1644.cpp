/*
    4000000 ������ �Ҽ��� ã�Ƽ� ����Ʈ�� ���� ��,
    �� ������ ����� ����Ѵ�.
    left �ε��� �̻�, right �ε��� �̸��� ���� �Ҽ��� ���� �����Ѵ�,
    �� �Ҽ��� ���� ��ǥġ���� ������ right �ε����� �ϳ� ������Ų��.
    �� �Ҽ��� ���� ��ǥġ���� ũ�� left �ε����� �ϳ� ������Ų��.
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
    while (left<numPrimes && primes[left]<=target) { //left<numPrimes ������ ���� ������ out of bounds ��Ÿ�� ������ ��������.
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
