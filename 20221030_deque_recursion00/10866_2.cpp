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
    if (tail<=head) return;
    head++;
}

void pop_back() {
    if (tail<=head) return;
    tail--;
}

int front() {
    if (tail<=head) return -1;
    return dat[head];
}

int back() {
    if (tail<=head) return -1;
    return dat[tail-1];
}

int size() {
    return max(tail-head, 0);
}

int empty() {
    return tail<=head ? 1 : 0;
}

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd=="push_front") {
            int val;
            cin >> val;
            push_front(val);
        } else if (cmd=="push_back") {
            int val;
            cin >> val;
            push_back(val);
        } else if (cmd=="pop_front") {
            cout << front() << '\n';
            pop_front();
        } else if (cmd=="pop_back") {
            cout << back() << '\n';
            pop_back();
        } else if (cmd=="size") {
            cout << size() << "\n";
        } else if (cmd=="empty") {
            cout << empty() << "\n";
        } else if (cmd=="front") {
            cout << front() << "\n";
        } else if (cmd=="back") {
            cout << back() << "\n";
        }
    } //cmd loop

    return 0;
}
