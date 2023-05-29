#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); //t�� 1�� ��ġ�� ����Ų��.
    cout << *t << '\n'; //1

    L.push_front(10); //{10, 1, 2}
    cout << *t << '\n'; //1 //push_front �޼��带 ȣ���ص� t�� ����Ű�� ��ġ�� ������� �ʴ´�.

    L.push_back(5); //{10, 1, 2, 5}

    L.insert(t, 6); //{10, 6, 1, 2, 5} //t�� ����Ű�� ���� 6�� �ִ´�. �� ���� ���Ҵ� �ڷ� �и���.
    cout << *t << '\n'; //1 //insert �޼��带 ȣ���ص� t�� ����Ű�� ��ġ�� ������� �ʴ´�.

    t++; //t�� ����Ű�� �ּҰ��� 1 Ű���. t�� 2�� ��ġ�� ����Ų��.
    cout << *t << '\n'; //2

    t = L.erase(t); //{10, 6, 1, 5} //t�� ����Ű�� �ִ� 2�� �����. t�� 5�� ����Ű�� �ȴ�.
    cout << *t << '\n'; //5

    //C++ 11 ������ �������� auto ��� ����� �߰��Ǿ���.
    //auto�� �ڷ����� ������ ��� �ڵ����� �ڷ����� �����ȴ�.
    for (auto elem:L) {
        cout << elem << ' '; //10 6 1 5
    }
    cout << '\n';

    for (list<int>::iterator it=L.begin(); it!=L.end(); it++) { //L.end()�� list�� ������ ���� ���� �ּҸ� ����Ų��.
        cout << *it << ' '; //10 6 1 5
    }
    cout << '\n';

    cout << L.size() << '\n'; //4

    return 0;
}
