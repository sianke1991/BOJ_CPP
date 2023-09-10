#include <iostream>
// 현재 상태에서 가능한 모든 후보군을 따라가는 탐색방법
// 상태공간트리
using namespace std;
int n, m;
int arr[10];
bool isUsed[10];
            // k: 재귀의 깊이
void func(int k) {
    if (k==m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!isUsed[i]) {
            arr[k] = i;
            isUsed[i] = true;
            func(k+1);
            isUsed[i] = false; //해당 경우를 전부 탐색한 경우 해당 수를 지워야 한다.
        }
    }
}
/*
func(0): arr[0]을 결정, func(1) 호출
func(m): 출력 후 재귀 종료
*/


int main() {



    return 0;
}
