// 다이나믹 프로그래밍
// 여러 개의 하위 문제를 먼저 푼 후 그 결과를 이용하여 주어진 문제를 해결하는 알고리즘

// 1. 테이블 정의하기
// 2. 점화식 찾기
// 3. 초기값 정하기
// 4. 반복을 통해 배열을 채워나간다.

#include <iostream>

using namespace std;

// 1463 (1로 만들기)
// 1. 테이블 정의하기
// D[i] := i를 1로 만들기 위해 적용해야 할 최소 연산 횟수
// 2. 점화식 찾기
// D[12] ?
// D[12] = min(D[4]+1, D[6]+1, D[11]+1)
// 3. 초기값 정하기
// D[1] = 0

int D[1000001];
int N;

int minVal(int val0) {
    return val0;
}
int minVal(int val0, int val1) {
    return min(val0, val1);
}
int minVal(int val0, int val1, int val2) {
    return min(min(val0, val1), val2);
}


/*
이 방법을 사용하면 getD 함수를 너무 많이 호출하게 된다.
int getD(int idx) {
    if (idx <= 1) {
        return 0;
    } else if (D[idx]!=0) {
        return D[idx];
    } else if (idx%6==0) {
        D[idx] = minVal(getD(idx/3)+1, getD(idx/2)+1, getD(idx-1)+1);
        return D[idx];
    } else if (idx%3==0) {
        D[idx] = minVal(getD(idx/3)+1, getD(idx-1)+1);
        return D[idx];
    } else if (idx%2==0) {
        D[idx] = minVal(getD(idx/2)+1, getD(idx-1)+1);
        return D[idx];
    } else {
        D[idx] = getD(idx-1)+1;
        return D[idx];
    }
}
*/

int getD(int idx) {
    for (int i=2; i<=idx; i++) {
        //if (D[i]) continue; //빈 배열을 채워나가는 방식이므로, 배열이 이미 채워져 있는 경우를 고려할 필요가 없다.
        if (i%6==0) {
            D[i] = minVal(D[i-1], D[i/2], D[i/3])+1;
        } else if (i%3==0) {
            D[i] = minVal(D[i-1], D[i/3])+1;
        } else if (i%2==0) {
            D[i] = minVal(D[i-1], D[i/2]) +1;
        } else {
            D[i] = D[i-1]+1;
        }
    } //i loop
    return D[idx];
}

int getD2(int idx) {
    for (int i=2; i<=idx; i++) {
        D[i] = D[i-1]+1;
        if (i%2==0) D[i] = min (D[i], D[i/2]+1);
        if (i%3==0) D[i] = min (D[i], D[i/3]+1);
    }
    return D[idx];
}

int main() {
    cin >> N;
    cout << getD(N);
    return 0;
}
