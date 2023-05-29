#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(10); //{10}
    dq.push_back(50); //{10, 50}
    dq.push_front(24); //{24, 10, 50}

    for (int i=0; i<dq.size(); i++) {
        cout << dq[i] << ' '; //24 10 50
    }
    cout << '\n';

    for (auto elem:dq) {
        cout << elem << ' '; //24 10 50
    }
    cout << '\n';

    if (dq.empty()) cout << "dq is empty.\n";
    else             cout << "dq is not empty.\n";

    dq.pop_front(); //{10, 50}
    dq.pop_back(); //{10}
    dq.push_back(72); //{10, 72}

    cout << dq.front() << '\n'; //10
    cout << dq.back() << '\n'; //72
    cout << *dq.begin() << '\n'; //10
    cout << *(dq.end()-1) << '\n'; //72 //dq.end()는 deque의 마지막 원소 다음 주소를 가리킨다.

    dq.push_back(12); //{10, 72, 12}
    dq[2] = 17; //{10, 72, 17}

    dq.insert(dq.begin()+1, 33); //{10, 33, 72, 17} //인덱스 1 위치에 원소 33을 넣고 그 이후의 원소는 오른쪽으로 이동한다.
    dq.insert(dq.begin()+4, 60); //{10, 33, 72, 17, 60} //인덱스 4 위치에 원소 60을 넣고 그 이후의 원소는 오른쪽으로 이동한다.
    dq.insert(dq.end(), 99); //{10, 33, 72, 17, 60, 99} //맨 마지막 원소 다음의 위치에 99를 넣는다.

    for (auto elem:dq) {
        cout << elem << ' '; //10 33 72 17 60 99
    }
    cout << '\n';

    dq.erase(dq.begin()+3); //{10, 33, 72, 60, 99} //인덱스 3 위치의 원소를 제거하고 그 이후의 원소는 왼쪽으로 이동한다.
    cout << dq[3] << '\n'; //60
    dq.clear();
    cout << dq.empty() << '\n'; //1

    return 0;
}
