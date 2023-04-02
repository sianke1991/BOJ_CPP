#include <bits/stdc++.h>
using namespace std;
/*
�� ī�� ������ �����ϴ� ���- �� ������ ī�� ������ (������������) a, b, c��� ����
�� ��� �� Ƚ����
(a+b)+(a+b+c)  //a, b�� ���� ���� ���
(a+c)+(a+b+c)  //a, c�� ���� ���� ���
(b+c)+(a+b+c)  //b, c�� ���� ���� ���
�ε� �� �߿��� a, b�� ���� ���� ��찡 �� Ƚ���� �ּҰ� �ȴ�.
��, ī�� ������ 3 ���� �� ũ�Ⱑ ���� ���� ���� 2���� ���� ����� �� Ƚ���� �ּҰ� �ȴ�.

ī�� ������ n���� ��� (n>3), ī�� ���� �� 2���� ��� ������ ������ (n������) n-1���� ���� �� �ִ�.
�� ī�� ������ ���̴� �������� �����ϴ� ī�� ���� �� ���� ���� ���� 2���� ����� �� Ƚ���� �ּҷ� �� �� �ִ�.

ī�� ���� �߿��� �ּ� ���� 2���� �����ϰ� �� ������ �ϳ��� ���Ͽ� ī�� ���� ���տ� �ٽ� �־��־�� �ϴµ�, �� ������ �ּ����� ����Ͽ� ������ �� �ִ�.
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
    while (pq.size()>1) { //ī�� ������ 1�� ���ϰ� �Ǹ� �� �̻� ī�� ������ ������ �ʴ´�.
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
