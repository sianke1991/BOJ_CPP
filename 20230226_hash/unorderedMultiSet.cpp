#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 100, 15}
    ms.insert(-10); ms.isnert(15); //{-10, -10, 100, 15, 15} //multiset�� ������ �ߺ��� ����Ѵ�.
    cout << ms.size9) << '\n'; //5
    for (auto e:ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(15) << '\n'; //{-10, -10, 100}, 2 //multiset���� ���Ҹ� ����� �޼���� �ߺ��� ���ҿ� ���� ��� ���Ҹ� ����� ���̴�. (���� ������ ��ȯ�Ѵ�.)

    ms.erase(ms.find(-10)); //{-10, 100} //�ߺ��� ���ҿ� ���� �ϳ��� ����� ������ iterator�� ���ڷ� �ش�.
    ms.insert(100); //{-10, 100, 100}
    cout << ms.count(100) << '\n'; //2 (ms �� ���� 100�� ����)
    return 0;
}
