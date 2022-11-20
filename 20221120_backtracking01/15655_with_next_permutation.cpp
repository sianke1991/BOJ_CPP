#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int numbersSelectable[N];
    for (int i=0; i<N; i++) {
        cin >> numbersSelectable[i];
    }
    sort(numbersSelectable, numbersSelectable+N);
    int isNotSelected[N];
    for (int i=0; i<M; i++) isNotSelected[i] = 0;
    for (int i=M; i<N; i++) isNotSelected[i] = 1;

    do {
        for (int i=0; i<N; i++) {
            if (isNotSelected[i]==0) cout << numbersSelectable[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(isNotSelected, isNotSelected+N));

    return 0;
}
