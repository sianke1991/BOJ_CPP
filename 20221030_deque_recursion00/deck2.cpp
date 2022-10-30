#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(10); //10
    dq.push_back(50); //10 50
    dq.push_front(24); //24 10 50

    for (auto x:dq) { //24 10 50
        cout << x << ' ';
    }
    cout << '\n';
    for (int i=0; i<dq.size(); i++) {
        cout << dq[i]<<' ';
    }
    if (dq.empty()) cout<<"\n dq is empty.\n";
    else             cout<<"dq is not empty.\n";
    dq.pop_front(); //10 50
    dq.pop_back(); //10
    cout << dq.front() << '\n'; //10

    dq.push_back(72); //10 72
    cout << dq.front() << '\n'; //10
    dq.push_back(12); //10 72 12
    dq[2] = 17; //10 72 17

    dq.insert(dq.begin()+1, 33); //10 33 72 17
    dq.insert(dq.begin()+4, 60); //10 33 72 17 60

    for (auto x:dq) {
        cout << x << ' ';
    }

    dq.erase(dq.begin()+3); //10 33 72 60
    cout << '\n' << dq[3]; //60
    dq.clear(); //초기화 (dq가 비워진다.)

    return 0;
}
