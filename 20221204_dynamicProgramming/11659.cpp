#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int valArr[N];
    for (int i=0; i<N; i++) {
        cin >> valArr[i];
    }
    //prefix sum
    int dpArray[N]; //인덱스 0번부터 인덱스 N번 까지의 합
    //초기값 설정
    dpArray[0] = valArr[0];
    //점화식 설정
    for (int i=1; i<N; i++) {
        dpArray[i] = dpArray[i-1] + valArr[i];
    } //i loop

    int results[M];
    for (int testcase=0; testcase<M; testcase++) {
        int i, j;
        cin >> i >> j;
        if (i==1)
            results[testcase] = dpArray[j-1];
        else
            results[testcase] = dpArray[j-1] - dpArray[i-2];
    }

    for (int result:results) {
        cout << result << '\n';
    }
    return 0;
}
