#include<iostream>

using namespace std;

int D[301][2]; //D[i][0]: 바로 이전 계단을 밟지 않고 i 계단까지 오를때 받을 수 있는 점수의 최대치, D[i][1]: 바로 이전 계단을 밟고 i 계단까지 오를 때 받을 수 있는 점수의 최대치
int pointArr[301]; //i 계산을 밟을 때 얻을 수 있는 점수


int main() {
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> pointArr[i];
    }
    //초기값 정하기
    D[1][0] = pointArr[1];
    D[2][0] = pointArr[2];
    D[2][1] = pointArr[1]+pointArr[2];
    D[3][0] = D[1][0] + pointArr[3];
    D[3][1] = D[2][0] + pointArr[3];
    //점화식
    for (int i=4; i<=N; i++) {
        D[i][0] = max(D[i-2][0], D[i-2][1])+pointArr[i]; //바로 이전 계단을 밟지 않는 경우에는 두 계단 전 계단을 밟을 때 0 버전과 1 버전 전부 고려한다.
        D[i][1] = D[i-1][0]+pointArr[i]; //바로 이전 계단을 밟는 경우에는 한 계단 전 계단을 밟을 때 0 버전만 고려한다.
    } //i loop
    cout << max(D[N][0], D[N][1]); //N 번째 계단까지 오를 때 받는 점수는 0버전과 1버전 중 최대치를 따른다.
    return 0;
}
