/*
    카드 더미 중에서
    가장 작은 더미 두 개를 뽑아 하나의 더미로 만든다.
    카드 더미 크기들을 관리하기 위해
    우선순위 큐를 사용할 수 있다.
*/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main() {
    int numStacks;
    scanf("%d", &numStacks);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<numStacks; i++) {
        int sz;
        scanf("%d", &sz);
        pq.push(sz);
    }
    long long cnt = 0LL;
    while (pq.size()>1) {
        int sz0 = pq.top();
        pq.pop();
        int sz1 = pq.top();
        pq.pop();
        int sum = sz0+sz1;
        cnt += sum;
        pq.push(sum);
    }
    printf("%lld", cnt);
    return 0;
}
