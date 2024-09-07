#include <stdio.h>

int digitProfile[10];

void digitsOf(long long num) {
    for (int i=0; i<10; i++)
        digitProfile[i] = 0;
    if (num==0) return;

    while (num!=0) {
        digitProfile[num%10]++;
        num/=10;
    }
    //printf(", results: %d %d %d %d %d %d %d %d %d %d\n", result[0], result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9]);
}

long long target;
bool used[10];
long long num0;
long long num1;

bool checkDigitUniqueness(long long remains) {
    //printf("remains: %d, used: %d %d %d %d %d %d %d %d %d %d\n", remains, used[0], used[1], used[2], used[3], used[4], used[5], used[6], used[7], used[8], used[9]);
    digitsOf(remains);
    for (int elem:digitProfile)
        if (elem>1) return false;
    for (int i=0; i<10; i++) {
        if (!used[i]) continue;
        if (digitProfile[i]) return false;
    }
    return true;
}


void recursive(long long currentNumber) {
    if (num0!=0 && num1!=0)
        return;
    if (currentNumber>=target)
        return;
    if (currentNumber!=0) {
        long long remains = target-currentNumber;
        //printf("currentNumber: %d, remains: %d, checkDigitUniqueness: %d\n", currentNumber, remains, checkDigitUniqueness(remains));
        if (checkDigitUniqueness(remains)) {
            num0 = currentNumber;
            num1 = remains;
            return;
        }

        for (int nextDigit=0; nextDigit<10; nextDigit++) {
            if (used[nextDigit]) continue;
            used[nextDigit] = true;
            recursive(currentNumber*10+nextDigit);
            used[nextDigit] = false;
        }
    } else {
        for (int nextDigit=1; nextDigit<10; nextDigit++) {
            if (used[nextDigit]) continue;
            used[nextDigit] = true;
            recursive(currentNumber*10+nextDigit);
            used[nextDigit] = false;
        }
    }
}

int main() {
    scanf("%lld", &target);
    if (target>987654321LL) {
        printf("-1");
        return 0;
    }
    recursive(0);
    if (num0==0 || num1==0) {
        printf("-1");
    } else {
        printf("%d + %d", num0, num1);
    }
    return 0;
}
