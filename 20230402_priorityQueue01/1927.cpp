#include <bits/stdc++.h>

using namespace std;
int heap[100005];
int sz = 0; //heap�� ����ִ� ������ ��

void push(int x) {
    sz++;
    heap[sz]=x; //�迭�� ���� ������ ĭ�� ���� �߰��� ���� �ִ´�.
    int newElemIdx = sz; //���� �߰��� ������ ��ġ
    while (newElemIdx>1 && heap[newElemIdx/2]>heap[newElemIdx]) { //���� �߰��� ���Ҵ� �����ν� Ʈ���� �߰��Ǵµ�, �ڽ��� �θ𺸴� ������ �ڽİ� �θ��� ���� ���� �ڹٲ��� �Ѵ�.
        int temp = heap[newElemIdx/2];
        heap[newElemIdx/2] = heap[newElemIdx];
        heap[newElemIdx] = temp;
        newElemIdx/=2;
    }
}

int top() {
    return heap[1];
}

bool isEmpty() {
	return sz<=0;
}

void pop() {
    heap[1] = heap[sz]; //������ ���� �����ʿ� �ִ� ������ ��Ʈ�� �̵���Ų��.
    heap[sz] = 0;
    sz--;
    int movedNodeIdx = 1;
    while ((movedNodeIdx*2<=sz && heap[movedNodeIdx]>heap[movedNodeIdx*2]) || (movedNodeIdx*2+1<=sz && heap[movedNodeIdx]>heap[movedNodeIdx*2+1])) { //�̵��� ��尡 �ڽ� ��庸�� ũ�� ��Ұ��踦 �ľ��Ͽ� �� �ڽ� ��� �� �� ���� �Ͱ� ��ġ�� �����Ѵ�.
        if (movedNodeIdx*2+1>sz || heap[movedNodeIdx*2] < heap[movedNodeIdx*2+1]) { //���� �ڽ� ��尡 ������ �ڽ� ��庸�� �� ���� ��� (���� �ڽ� ��尡 �θ� �Ǿ�� �Ѵ�.)
			int temp = heap[movedNodeIdx*2];
			heap[movedNodeIdx*2] = heap[movedNodeIdx];
			heap[movedNodeIdx] = temp;
			movedNodeIdx = movedNodeIdx*2;
        } else { //������ �ڽ� ��尡 ���� �ڽ� ��庸�� �� ���� ��� (������ �ڽ� ��尡 �θ� �Ǿ�� �Ѵ�.)
			int temp = heap[movedNodeIdx*2+1];
			heap[movedNodeIdx*2+1] = heap[movedNodeIdx];
			heap[movedNodeIdx] = temp;
			movedNodeIdx = movedNodeIdx*2+1;
        }
    }
}

int main() {
    int numOperations;
    cin >> numOperations;
    vector<int> results;
    for (int i=0; i<numOperations; i++) {
        int operation;
        cin >> operation;
        if (operation==0) { //pop
            if (isEmpty()) {
                results.push_back(0);
            } else {
                results.push_back(top());
                pop();
            }
        } else { //insert
            push(operation);
        }
    } //i loop

    for (int result:results) {
        cout << result << '\n';
    }
    return 0;
}
