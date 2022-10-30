#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> dq;
    for (int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd=="push_front") {
            int val;
            cin >> val;
            dq.push_front(val);
        } else if (cmd=="push_back") {
            int val;
            cin >> val;
            dq.push_back(val);
        } else if (cmd=="pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (cmd=="pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (cmd=="size") {
            cout << dq.size() << "\n";
        } else if (cmd=="empty") {
            cout << (dq.empty() ? 1 : 0) << "\n";
        } else if (cmd=="front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << "\n";
            }
        } else if (cmd=="back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << "\n";
            }
        }
    } //cmd loop

    return 0;


}
