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

string toString() {
    string result = "";
    int currentIdx = 1;
    while (heap[currentIdx]>0) {
        result += to_string(heap[currentIdx]);
        result += " ";
        currentIdx++;
    }
    return result;
}

int top() {
    return heap[1];
}

int getSize() {
    return sz;
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

void test() {
    //입력 테스트: '91,120,73,222,192,193,210,140,19,251,66,112'
    push(91);
    push(120);
    push(73);
    push(222);
    push(192);
    push(193);
    push(210);
    push(140);
    push(19);
    push(251);
    push(66);
    push(112);
    cout << toString() << '\n'; //19 66 91 120 73 112 210 222 140 251 192 193
    cout << top() << '\n'; //19
    pop();
    cout << toString() << '\n'; //66 73 91 120 192 112 210 222 140 251 193
    cout << top() << '\n'; //66
    pop();
    cout << toString() << '\n'; //73 120 91 140 192 112 210 222 193 251
    cout << top() << '\n'; //73
    pop();
    cout << toString() << '\n'; //91 120 112 140 192 251 210 222 193
	cout << top() << '\n'; //91
	pop();
	cout << toString() << '\n'; //112 120 193 140 192 251 210 222
	cout << top() << '\n'; //112
	while (!isEmpty()) {
		cout << top() << ' '; //112 120 140 192 193 210 222 251
		pop();
	}
}

int main() {
    test();
    return 0;
}
