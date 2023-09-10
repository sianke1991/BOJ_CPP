#include <bits/stdc++.h>

using namespace std;

int numAvailableElems; //���� ������ ���� ���� (�����ؾ� �� ���� ������ �ƴϴ�. ������ �� 6���� �����Ѵ�.)
int availableElements[13];
int selectedElements[13];
//bool isElementUsed[13]; //��� ����� ������������ ���ĵǾ�� �ϹǷ� �� ������ ��� ���δ� ����� �ʿ䰡 ����.

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
