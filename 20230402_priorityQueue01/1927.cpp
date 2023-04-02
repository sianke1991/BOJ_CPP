#include <bits/stdc++.h>

using namespace std;
int heap[100005];
int sz = 0; //heap에 들어있는 원소의 수

void push(int x) {
    sz++;
    heap[sz]=x; //배열의 가장 오른쪽 칸에 새로 추가할 값을 넣는다.
    int newElemIdx = sz; //새로 추가된 원소의 위치
    while (newElemIdx>1 && heap[newElemIdx/2]>heap[newElemIdx]) { //새로 추가된 원소는 리프로써 트리에 추가되는데, 자식이 부모보다 작으면 자식과 부모의 값이 서로 뒤바뀌어야 한다.
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
    heap[1] = heap[sz]; //힙에서 가장 오른쪽에 있는 리프를 루트로 이동시킨다.
    heap[sz] = 0;
    sz--;
    int movedNodeIdx = 1;
    while ((movedNodeIdx*2<=sz && heap[movedNodeIdx]>heap[movedNodeIdx*2]) || (movedNodeIdx*2+1<=sz && heap[movedNodeIdx]>heap[movedNodeIdx*2+1])) { //이동한 노드가 자식 노드보다 크면 대소관계를 파악하여 두 자식 노드 중 더 작은 것과 위치를 변경한다.
        if (movedNodeIdx*2+1>sz || heap[movedNodeIdx*2] < heap[movedNodeIdx*2+1]) { //왼쪽 자식 노드가 오른쪽 자식 노드보다 더 작은 경우 (왼쪽 자식 노드가 부모가 되어야 한다.)
			int temp = heap[movedNodeIdx*2];
			heap[movedNodeIdx*2] = heap[movedNodeIdx];
			heap[movedNodeIdx] = temp;
			movedNodeIdx = movedNodeIdx*2;
        } else { //오른쪽 자식 노드가 왼쪽 자식 노드보다 더 작은 경우 (오른쪽 자식 노드가 부모가 되어야 한다.)
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
