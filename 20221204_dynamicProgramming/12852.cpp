#include <iostream>
#include <algorithm>

using namespace std;

int dpArray[1000002][2];    //dpArray[i][0]: i를 1로 만들기 위해 필요한 연산 횟수의 최소치 (값 테이블)
                            //dpArray[i][1]: i를 1로 만들기 위해 적용해야 할 연산의 결과 (경로 복원 테이블)

int main() {
    int N;
    cin >> N;
    //초기값 설정
    dpArray[1][0] = 0;
    dpArray[1][1] = 0;
    dpArray[2][0] = 1;
    dpArray[2][1] = 1;
    dpArray[3][0] = 1;
    dpArray[3][1] = 1;
    for (int i=4; i<=N; i++) {
        dpArray[i][0] = dpArray[i-1][0]+1;
        dpArray[i][1] = i-1;
        if (i%2==0 && dpArray[i/2][0]+1 < dpArray[i][0]) {
            dpArray[i][0] = dpArray[i/2][0]+1;
            dpArray[i][1] = i/2;
        }
        if (i%3==0 && dpArray[i/3][0]+1 < dpArray[i][0]) {
            dpArray[i][0] = dpArray[i/3][0]+1;
            dpArray[i][1] = i/3;
        }
    }

    cout << dpArray[N][0] << '\n';
    int path = N;
    while (1) {
        cout << path << ' ';
        if (path==1) break;
        path = dpArray[path][1];
    }
    return 0;
}
