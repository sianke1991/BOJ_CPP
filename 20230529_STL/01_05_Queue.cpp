#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    q.push(10); //{10}
    q.push(25); //{10, 25}
    q.push(30); //{10, 25, 30}

    cout << q.size() << '\n'; //3
    cout << q.front() << '\n'; //10 //stack�� �����ִ� ���� �� ���� ������ ���Ҹ� ��ȸ�Ѵ�.

    if (q.empty()) cout << "q is empty.\n";
    else            cout << "q is not empty.\n";

    q.pop(); //{25, 30} //queue�� �����ִ� ���� �� ���� ������ ���Ҹ� �����Ѵ�.
             //queue�� �����ִ� ���� �� ���� ������ ���Ҹ� ������ ��, �� ���Ҹ� ��ȯ������ �ʴ´�.
    cout << q.front() << '\n'; //25

    return 0;
}
