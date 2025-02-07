#include <stdio.h>

const long long MOD = 1000000007LL;

long long power(long long base, long long exponent) {
    if (exponent==0LL) {
        return 1LL;
    }
    if (exponent%2LL==1LL) {
        return base*power(base, exponent-1LL)%MOD;
    }
    long long sqrt = power(base, exponent/2LL)%MOD;
    return sqrt*sqrt%MOD;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i=0; i<numTestCases; i++) {
        long long tc;
        scanf("%lld", &tc);
        if (tc==1 || tc==2) {
            printf("1\n");
        } else {
            printf("%lld\n", power(2LL, tc-2LL));
        }

    }
    return 0;
}
