#include <bits/stdc++.h>
using namespace std;
/*
세 카드 묶음을 정렬하는 경우- 각 묶음의 카드 개수를 (오름차순으로) a, b, c라고 하자
이 경우 비교 횟수는
(a+b)+(a+b+c)  //a, b를 먼저 묶는 경우
(a+c)+(a+b+c)  //a, c를 먼저 묶는 경우
(b+c)+(a+b+c)  //b, c를 먼저 묶는 경우
인데 이 중에서 a, b를 먼저 묶는 경우가 비교 횟수가 최소가 된다.
즉, 카드 묶음이 3 개일 때 크기가 가장 작은 묶음 2개를 먼저 묶어야 비교 횟수가 최소가 된다.

카드 묶음이 n개인 경우 (n>3), 카드 묶음 중 2개를 묶어서 묶음의 개수를 (n개에서) n-1개로 줄일 수 있다.
이 카드 묶음을 줄이는 과정에도 현존하는 카드 묶음 중 가장 작은 묶음 2개를 묶어야 비교 횟수를 최소로 할 수 있다.

카드 묶음 중에서 최소 묶음 2개를 선택하고 그 묶음을 하나로 합하여 카드 묶음 집합에 다시 넣어주어야 하는데, 이 연산은 최소힙을 사용하여 수행할 수 있다.
*/
int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int numStacks;
    cin >> numStacks;
    for (int i=0; i<numStacks; i++) {
        int stackSize;
        cin >> stackSize;
        pq.push(stackSize);
    }
    int numCompares = 0;
    while (pq.size()>1) { //카드 묶음이 1개 이하가 되면 더 이상 카드 묶음을 합하지 않는다.
        int least = pq.top();
        pq.pop();
        int secondLeast = pq.top();
        pq.pop();
        int combinedStackSize = least+secondLeast;
        numCompares += combinedStackSize;
        pq.push(combinedStackSize);
    }
    cout << numCompares;
    return 0;
}
