#include <iostream>
#include <math.h>

using namespace std;

long long func1(int N)
{ // N까지의 자연수 중 3의 배수 또는 5의 배수의 합
    long long result(0); //0으로 초기화하여 변수 생성

    for (int i=1; i<=N; i++) {
        if (i%3 && i%5 ) continue;
        result += i ;
    }
    return result;
}

int func2(int* arr, int len) { //배열 내에 임의의 두 원소를 뽑아서 합이 100 이 될 수 있는지 여부
    for (int i=0; i<len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if ((*(arr+i)) + (*(arr+j)) == 100) return 1;
        } //j loop
    } //i loop
    return 0;
}

int func3(int n){ //n이 제곱수인지 여부를 반환
    if (n < 0) return 0;
    for (int i=0; i*i<=n; i++) {
        if (i*i==n) return 1;
    }
    return 0;
}

int func4(int n){ //n이하의 자연수 중 가장 큰 2의 거듭제곱수를 반환
    /*
    if (n <= 0) return 0;
    int i;
    for (i=1; i<=n; i*=2) {
    }
    if (i==n) return i;
    else      return i/2;
    */
    int val = 1;
    while (2*val <= n){
        val *= 2;
    }
    return val;
}

int main(){

    /*
    시간복잡도
    O(N)
    O(N^2) 가장 significant 한 항만을 남긴다.
    O(sqrt(N))
    O(log N)
    */

    /* int 자료형을 1.2억개 정도 사용하면 512 MB를 사용하게 된다. */

    /*
    int N;
    cin >> N;
    int arr[N];
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    cout << func2(arr, N);
    */

    int N;
    cin >> N;
    cout << func4(N);
    return 0;
}
