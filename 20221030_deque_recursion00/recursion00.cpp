#include <bits/stdc++.h>
using namespace std;

void print(int num) {
    cout << num << "\n";
    if (num>1) print(num-1);
}

void print2(int num) {
    if (num<=0) return;
    cout << num << "\n";
    print2(num-1);
}

/*
void sum(int& sum, int num) {
    if (num<=0) return;
    sum += num;
    sum(sum, num-1);
}
*/

//매우 비효율적인 코드
int fibo(int n) {
    if (n<=1) return n;
    return fibo(n-1) + fibo(n-2);
}

int mod(int a, int b, int m) {
    int val = 1;
    while(b--) {
        val *= a;
        val %= m;
    }
    return val;
}


int main () {
    cout << mod (2, 100, 10);

    return 0;
}
