#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int isNotSelected[N]; //해당 위치에 있는 원소가 선택되는지 여부를 담는 배열 (0: 해당 위치에 있는 원소가 선택됨, 1: 해당 위치에 있는 원소가 선택되지 않음)
    for (int i=0; i<M; i++) isNotSelected[i] = 0; //M개의 원소는 선택되어야 한다.
    for (int i=M; i<N; i++) isNotSelected[i] = 1; //N-M개의 원소는 선택되지 않는다.

    do {
        for (int i=0; i<N; i++) {
            if (isNotSelected[i]==0) cout << i+1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(isNotSelected, isNotSelected+N));

    return 0;
}
