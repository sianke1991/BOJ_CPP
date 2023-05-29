#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); //{-10, 100, 15} //set�� ���� �ִ´�.
    s.insert(-10); //{-10, 100, 15} //set�� �̹� �� ���� �� �̻� ���� �ʴ´�.

    cout << s.erase(100) << '\n'; //1 //erase�� set�� ���Ҹ� �����, �����ٸ� 1�� ������ ���ߴٸ� 0�� ��ȯ�Ѵ�. (���� ������ ������ ��ȯ�Ѵ�.)
    cout << s.erase(20) << '\n'; //0

    if (s.find(15) != s.end()) { //find�� ���� ã�Ƽ� iterator�� ��ȯ�ϴµ�, ���� �߰����� ���ߴٸ� end()�� ��ȯ�Ѵ�.
        cout << "15 in s.\n";
    } else {
        cout << "15 not in s.\n";
    }

    cout << s.size() << '\n'; //2 //set �� ������ ���� (set�� ũ��)
    cout << s.count(50) << '\n'; //0 //set�� ���� 50�� ���� (�ش� ���Ұ� ������ 1��, ������ 0�� ��ȯ�Ѵ�.)

    for (int elem:s) {
        cout << elem << ' '; //15 -10
    }
    cout << '\n';

    return 0;
}
