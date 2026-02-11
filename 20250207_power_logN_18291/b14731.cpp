#include <stdio.h>

const long long MOD = 1000000007LL;
const long long BASE = 2LL;
long long sq(long long num) {
    return num*num;
}
long long powerOfTwo(int exponent) {
    if (exponent==0) return 1LL;
    if (exponent==1) return BASE;
    if (exponent%2==0) {
        //지수가 짝수인 경우
        return sq(powerOfTwo(exponent/2)%MOD)%MOD;
    }  else {
        //지수가 홀수인 경우
        return sq(powerOfTwo(exponent/2)%MOD)%MOD*BASE%MOD;
    }
}
long long differentiate(int coefficient, int degree) {
    return 1LL * coefficient * degree % MOD * powerOfTwo(degree-1) % MOD;
}

int main() {
    int numTerms;
    scanf("%d", &numTerms);
    long long result = 0LL;
    for (int i=0; i<numTerms; i++) {
        int coefficient, degree;
        scanf("%d %d", &coefficient, &degree);
        result += differentiate(coefficient, degree);
        result %= MOD;
    }
    printf("%d\n", result);
    return 0;
}
