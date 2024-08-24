/*
    ī�� ���� �߿���
    ���� ���� ���� �� ���� �̾� �ϳ��� ���̷� �����.
    ī�� ���� ũ����� �����ϱ� ����
    �켱���� ť�� ����� �� �ִ�.
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
