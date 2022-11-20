#include <bits/stdc++.h>

using namespace std;


int main() {

    //순열을 출력하는 방법
    int a[3] = {1, 2, 3};
    do {
        for (int i=0; i<3; i++) {
            cout << a[i];
        }
        cout << '\n';
    } while (next_permutation(a, a+3)); //순열을 돌면서 배열 a의 순서를 변경한다.

    for (int i=0; i<3; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    //조합을 출력하는 방법
    int b[4] = {0, 0, 1, 1}; //0은 해당 위치에 있는 원소를 선택했음을, 1은 해당 위치에 있는 원소를 선택하지 않았음을 나타낸다.
    do {
        for (int i=0; i<4; i++) {
            if (b[i]==0) cout << i+1;
        }
        cout << '\n';
    } while (next_permutation(b, b+4));

    return 0;
}
