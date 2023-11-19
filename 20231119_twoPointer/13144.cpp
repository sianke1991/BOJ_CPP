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
        while (ed<arrLength && !contains(arr[ed])) { //ed 포인터를 오른쪽으로 밀면서 numSet에 중복이 발생할 때 까지 numSet에 원소를 넣는다.
            add(arr[ed]);				//st부터 ed까지 원소가 unique 함을 알고 있으므로 st가 한 칸 오른쪽으로 밀려도 여전히 st부터 ed 까지의 원소는 unique한 것이다.
            ed++;					//st가 한 칸 오른쪽으로 밀릴 때(다음 for loop를 수행할 때) 굳이 ed 포인터를 st로 초기화할 필요가 없다.
        }
        numCases += size(); //numSet의 크기가 주어진 st에 대해 unique numbers lists의 개수이다.
        remove(arr[st]); //st를 1 증가시키기 전에 numSet에 arr[st]를 제거한다.
    } //st loop

    printf("%lld", numCases);
    return 0;
}
