#include <iostream>


using namespace std;

//dpCache[i][j]: i 자리 자연수에 대해 j로  끝나는 계단수의 개수 (1000000000 으로 나눈 나머지)
long long dpCache[102][10];


int main() {
    int N; // 자리 개수
    cin >> N;

    //베이스 케이스
    for (int j=1; j<=9; j++)
        dpCache[1][j] = 1;

    //점화식
    for (int i=2; i<=N; i++) {
        dpCache[i][0] = dpCache[i-1][1]; //0으로 끝나는 i+1 자리 계단수를 만드려면 1로 끝나는 i 자리 계단수 뒤에 0을 붙인다.
        for (int j=1; j<=8; j++) {
            dpCache[i][j] = (dpCache[i-1][j-1]+dpCache[i-1][j+1]) % 1000000000; //j로 끝나는 i+1 자리 계단수를 만드려면 j-1 또는 j+1로 끝나는 i 자리 계단수 뒤에 0을 붙인다.
            //예를 들어 4로 끝나는 10자리 계단수를 만드려면 3 또는 5로 끝나는 9자리 계단수 뒤에 4를 붙인다.
        }
        dpCache[i][9] = dpCache[i-1][8]; //9로 끝나는 i+1 자리 계단수를 만드려면 8로 끝나는 i자리 계단수 뒤에 9를 붙인다.
    }

    long long result = 0;
    for (int j=0; j<=9; j++) { //자리수 N에 대해 0-9로 끝나는 계단수의 개수를 합한다.
        result = (result+dpCache[N][j])%1000000000;
    }

    cout << result;
    return 0;
}
