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

void pop() {
    heap[sz] = heap[1]; //������ ���� �����ʿ� �ִ� ������ ��Ʈ�� �̵���Ų��.
    sz--;
    int movedNodeIdx = 1;
    while (heap[movedNodeIdx]>heap[movedNodeIdx*2] || heap[movedNodeIdx]>heap[movedNodeIdx*2+1]) { //�̵��� ��尡 �ڽ� ��庸�� ũ�� ��Ұ��踦 �ľ��Ͽ� �� �ڽ� ��� �� �� ���� �Ͱ� ��ġ�� �����Ѵ�.
        if (heap[movedNodeIdx*2] < heap[movedNodeIdx*2+1]) { //���� �ڽ� ��尡 ������ �ڽ� ��庸�� �� ���� ��� (���� �ڽ� ��尡 �θ� �Ǿ�� �Ѵ�.)

        } else { //������ �ڽ� ��尡 ���� �ڽ� ��庸�� �� ���� ��� (������ �ڽ� ��尡 �θ� �Ǿ�� �Ѵ�.)

        }
    }


}

void test() {
    //�Է� �׽�Ʈ: '91,120,73,222,192,193,210,140,19,251,66,112'
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

}

int main() {
    test();
    return 0;
}
