#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 100, 15}
    ms.insert(-10); ms.insert(15); //{-10, -10, 100, 15, 15} //multiset�� ������ �ߺ��� ����Ѵ�.

    cout << ms.size() << '\n'; //5 //multiset ������ ������ ���� (�ߺ��� ���ҵ� ���� �� ���� ��Ƹ���.)
    for (int elem:ms) {
        cout << elem << ' '; //15 15 -10 -10 100
    }
    cout << '\n';

    cout << ms.erase(15) << '\n'; //2 //multiset���� ���Ҹ� ����� �޼���� �ߺ��� ���ҿ� ���� ��� ���Ҹ� ����� ���̴�. ���� ������ ������ ��ȯ�Ѵ�.
    for (int elem:ms) {
        cout << elem << ' '; //-10 -10 100
    }
    cout << '\n';

    ms.erase(ms.find(-10)); //{-10, 100} //multiset �� �ߺ��� ���ҿ� ���� �ϳ��� ����� ������ iterator�� erase �޼����� ���ڷ� �ش�.
    ms.insert(100); //{-10, 100, 100}
    for (int elem:ms) {
        cout << elem << ' '; //-10 100 100
    }
    cout << '\n';
    cout << ms.count(100) << '\n'; //2 //multiset�� ���� 100�� ����

    return 0;
}
