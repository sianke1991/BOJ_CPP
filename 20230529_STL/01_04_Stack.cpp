#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> s;
    s.push(10); //{10}
    s.push(25); //{10, 25}
    s.push(30); //{10, 25, 30}

    cout << s.size() << '\n'; //3
    if (s.empty()) cout << "s is empty.\n";
    else            cout << "s is not empty.\n";

    s.pop(); //{10, 25} //stack�� �����ִ� ���� �� ���� ���ο� ���Ҹ� �����Ѵ�.
             //stack�� �����ִ� ���� �� ���� ���ο� ���Ҹ� ������ ��, �� ���Ҹ� ��ȯ������ �ʴ´�.
    cout << s.top() << '\n'; //25 //stack�� �����ִ� ���� �� ���� ���ο� ���Ҹ� ��ȸ�Ѵ�.

    return 0;
}
