#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int isNotSelected[N]; //�ش� ��ġ�� �ִ� ���Ұ� ���õǴ��� ���θ� ��� �迭 (0: �ش� ��ġ�� �ִ� ���Ұ� ���õ�, 1: �ش� ��ġ�� �ִ� ���Ұ� ���õ��� ����)
    for (int i=0; i<M; i++) isNotSelected[i] = 0; //M���� ���Ҵ� ���õǾ�� �Ѵ�.
    for (int i=M; i<N; i++) isNotSelected[i] = 1; //N-M���� ���Ҵ� ���õ��� �ʴ´�.

    do {
        for (int i=0; i<N; i++) {
            if (isNotSelected[i]==0) cout << i+1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(isNotSelected, isNotSelected+N));

    return 0;
}
