#include <map>
#include <set>
#include <string>
#include <iostream>


using namespace std;

int main() {
    map<string, int> m;

    m["zero"] = 0;
    m.insert({"one", 1}); //insert 메서드는 pair를 인자로 받는다.
    m.insert(make_pair("two", 2)); //make_pair: pair를 생성하는 함수
    m["three"] = 3;

    m.erase("three"); //erase는 key 또는 iterator를 받는다. ( m.erase(m.begin()) 으로 가장 값이 낮은 key를 삭제할 수 있다. )
    if (m.find("three") == m.end()) { //map에 특정 key가 있는지 여부를 확인한다. find(key) 메서드는 iterator를 반환한다.
        cout << "no key three in m\n";
    }

    for (pair<string, int> p:m) { //범위 기반 for loop
        cout << p.first << ", " << p.second << '\n';
    }
    for (auto it=m.begin(); it!=m.end(); it++) { //for loop
        cout << it->first << ", " << it->second << '\n';
    }

    cout << m.count("three") << '\n'; //key의 개수 반환 (int)
    cout << m.empty() << '\n'; //map이 비었는지 여부 (bool)
    cout << m.size() << '\n'; //map의 크기 (key의 개수)


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
