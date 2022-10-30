#include <bits/stdc++.h>

using namespace std;
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX; //deque의 길이는 tail-head

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int front() {
    if (tail==head) return -2147483648;
    return dat[head];
}

int back() {
    if (tail==head) return -2147483648;
    return dat[tail-1];
}

void test() {
    cout << front() << '\n';

    push_back(30); //30
    cout << front() << '\n'; //30
    cout << back() << '\n'; //30

    push_front(25); //25 30      //head 인덱스 쪽에서 넣는 것이 push_front
    push_back(12); //25 30 12    //back 인덱스 쪽에서 넣는 것이 push_back
    cout << back() << '\n'; //12

    push_back(62); //25 30 12 62
    pop_front(); //30 12 62
    cout << front() << '\n'; //30
    pop_front(); //12 62
    cout << back() << '\n'; //62

}

int main() {
    test();


    return 0;
}
