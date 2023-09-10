#include <bits/stdc++.h>

using namespace std;

int numAvailableElems; //선택 가능한 수의 개수 (선택해야 할 수의 개수가 아니다. 언제나 수 6개를 선택한다.)
int availableElements[13];
int selectedElements[13];
//bool isElementUsed[13]; //출력 답안은 오름차순으로 정렬되어야 하므로 각 원소의 사용 여부는 기록할 필요가 없다.

void backtrack(int depth) {
    if (depth==6) {
        for (int i=0; i<6; i++) {
            cout << selectedElements[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<numAvailableElems; i++) {
        if (depth>0 && availableElements[i]<=selectedElements[depth-1]) continue;
        selectedElements[depth] = availableElements[i];
        backtrack(depth+1);
    }
}


int main() {
    while (true) {
        cin >> numAvailableElems;
        if (numAvailableElems==0)
            break;
        for (int i=0; i<numAvailableElems; i++) {
            cin >> availableElements[i];
        }
        backtrack(0);
        cout << '\n';
    } //while loop
    return 0;
}
