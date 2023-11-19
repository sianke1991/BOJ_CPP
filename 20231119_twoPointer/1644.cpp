#include <stdio.h>
#include <vector>
using namespace std;

char primeCheck[4000001];
vector<int> primes;

const char NOT_DETERMINED = 0;
const char IS_PRIME = 1;
const char IS_NOT_PRIME = 2;

void setPrimeCheck(int upper) {
    primeCheck[0] = IS_NOT_PRIME;
    primeCheck[1] = IS_NOT_PRIME;
    for (int i=2; i<=upper; i++) {
        if (primeCheck[i]==NOT_DETERMINED) {
            primeCheck[i] = IS_PRIME;
            primes.push_back(i);
            for (int j=2*i; j<=upper; j+=i) {
                primeCheck[j] = IS_NOT_PRIME;
            }
        }
    }
}


int main() {
    int targetSum;
    scanf("%d", &targetSum);
    setPrimeCheck(targetSum);
    if (primes.empty()) { //primes에 원소가 없으면 int partialSum = primes[0]; 문장에서 오류가 떨어진다.
        printf("0");
        return 0;
    }
    int numCases = 0;
    int st, en = 0; //투 포인터의 두 인덱스 (소수 배열 primes에 대해 투 포인터를 적용한다.)
    int partialSum = primes[0]; //primes에 대해 st 이상 en 이하의 부분 배열의 합
    for (st = 0; st<primes.size(); st++) {
        while (partialSum<targetSum && en<primes.size()-1) {
            en++;
            partialSum += primes[en];
        }
        if (partialSum==targetSum)
            numCases++;
        partialSum -= primes[st];
    } //st loop

    printf("%d", numCases);
    return 0;
}
