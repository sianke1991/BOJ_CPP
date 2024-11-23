#include <stdio.h>
#include <vector>
using namespace std;

int isPrime[1000001] = {-1, -1};
vector<int> primes;

void setIsPrimeArray() {
    for (int num=2; num<=1000000; num++) {
        if (isPrime[num]) continue;
        isPrime[num] = 1;
        primes.push_back(num);
        for (int mul=num*2; mul<=1000000; mul+=num) {
            isPrime[mul] = -1;
        }
    } //num loop
}

bool checkPrime(int num) {
    return isPrime[num]==1;
}

int main() {
    setIsPrimeArray();
    while (true) {
        int num;
        scanf("%d", &num);
        if (num==0)
             break;
        for (int prime:primes) {
            int remainder = num-prime;
            if (checkPrime(remainder)) {
                printf("%d = %d + %d\n", num, prime, remainder);
                break;
            }
        } //prime loop
    } //while loop

    return 0;
}
