#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int arr[100001];
bool containess[100001];
int sz = 0;

bool contains(int elem) {
    return containess[elem];
}

void add(int elem) {
    if (!containess[elem]) {
        containess[elem] = true;
        sz++;
    }
}

void remove(int elem) {
    if (containess[elem]) {
        containess[elem] = false;
        sz--;
    }
}

int size() {
    return sz;
}

int main() {
    int arrLength;
    scanf("%d", &arrLength);
    for (int i=0; i<arrLength; i++)
        scanf("%d", &arr[i]);

    long long numCases = 0;
    int st=0, ed=0;
    for (st=0; st<arrLength; st++) {
        while (ed<arrLength && !contains(arr[ed])) { //ed �����͸� ���������� �и鼭 numSet�� �ߺ��� �߻��� �� ���� numSet�� ���Ҹ� �ִ´�.
            add(arr[ed]);				//st���� ed���� ���Ұ� unique ���� �˰� �����Ƿ� st�� �� ĭ ���������� �з��� ������ st���� ed ������ ���Ҵ� unique�� ���̴�.
            ed++;					//st�� �� ĭ ���������� �и� ��(���� for loop�� ������ ��) ���� ed �����͸� st�� �ʱ�ȭ�� �ʿ䰡 ����.
        }
        numCases += size(); //numSet�� ũ�Ⱑ �־��� st�� ���� unique numbers lists�� �����̴�.
        remove(arr[st]); //st�� 1 ������Ű�� ���� numSet�� arr[st]�� �����Ѵ�.
    } //st loop

    printf("%lld", numCases);
    return 0;
}
