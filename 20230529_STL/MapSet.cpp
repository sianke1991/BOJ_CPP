#include <map>
#include <set>
#include <string>
#include <iostream>


using namespace std;

int main() {
    map<string, int> m;

    m["zero"] = 0;
    m.insert({"one", 1}); //insert �޼���� pair�� ���ڷ� �޴´�.
    m.insert(make_pair("two", 2)); //make_pair: pair�� �����ϴ� �Լ�
    m["three"] = 3;

    m.erase("three"); //erase�� key �Ǵ� iterator�� �޴´�. ( m.erase(m.begin()) ���� ���� ���� ���� key�� ������ �� �ִ�. )
    if (m.find("three") == m.end()) { //map�� Ư�� key�� �ִ��� ���θ� Ȯ���Ѵ�. find(key) �޼���� iterator�� ��ȯ�Ѵ�.
        cout << "no key three in m\n";
    }

    for (pair<string, int> p:m) { //���� ��� for loop
        cout << p.first << ", " << p.second << '\n';
    }
    for (auto it=m.begin(); it!=m.end(); it++) { //for loop
        cout << it->first << ", " << it->second << '\n';
    }

    cout << m.count("three") << '\n'; //key�� ���� ��ȯ (int)
    cout << m.empty() << '\n'; //map�� ������� ���� (bool)
    cout << m.size() << '\n'; //map�� ũ�� (key�� ����)


    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(7);

    for (int e:s) {
        cout << e << '\n';
    }

    for (auto it=s.begin(); it!=s.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}
