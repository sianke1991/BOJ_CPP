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
    cout << *(dq.end()-1) << '\n'; //72 //dq.end()�� deque�� ������ ���� ���� �ּҸ� ����Ų��.

    dq.push_back(12); //{10, 72, 12}
    dq[2] = 17; //{10, 72, 17}

    dq.insert(dq.begin()+1, 33); //{10, 33, 72, 17} //�ε��� 1 ��ġ�� ���� 33�� �ְ� �� ������ ���Ҵ� ���������� �̵��Ѵ�.
    dq.insert(dq.begin()+4, 60); //{10, 33, 72, 17, 60} //�ε��� 4 ��ġ�� ���� 60�� �ְ� �� ������ ���Ҵ� ���������� �̵��Ѵ�.
    dq.insert(dq.end(), 99); //{10, 33, 72, 17, 60, 99} //�� ������ ���� ������ ��ġ�� 99�� �ִ´�.

    for (auto elem:dq) {
        cout << elem << ' '; //10 33 72 17 60 99
    }
    cout << '\n';

    dq.erase(dq.begin()+3); //{10, 33, 72, 60, 99} //�ε��� 3 ��ġ�� ���Ҹ� �����ϰ� �� ������ ���Ҵ� �������� �̵��Ѵ�.
    cout << dq[3] << '\n'; //60
    dq.clear();
    cout << dq.empty() << '\n'; //1

    return 0;
}
