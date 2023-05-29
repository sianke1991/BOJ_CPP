#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); //t는 1의 위치를 가리킨다.
    cout << *t << '\n'; //1

    L.push_front(10); //{10, 1, 2}
    cout << *t << '\n'; //1 //push_front 메서드를 호출해도 t가 가리키는 위치는 변경되지 않는다.

    L.push_back(5); //{10, 1, 2, 5}

    L.insert(t, 6); //{10, 6, 1, 2, 5} //t가 가리키는 곳에 6을 넣는다. 그 다음 원소는 뒤로 밀린다.
    cout << *t << '\n'; //1 //insert 메서드를 호출해도 t가 가리키는 위치는 변경되지 않는다.

    t++; //t가 가리키는 주소값을 1 키운다. t는 2의 위치를 가리킨다.
    cout << *t << '\n'; //2

    t = L.erase(t); //{10, 6, 1, 5} //t가 가리키고 있는 2를 지운다. t는 5를 가리키게 된다.
    cout << *t << '\n'; //5

    //C++ 11 이후의 버전에는 auto 라는 기능이 추가되었다.
    //auto로 자료형을 선언할 경우 자동으로 자료형이 결정된다.
    for (auto elem:L) {
        cout << elem << ' '; //10 6 1 5
    }
    cout << '\n';

    for (list<int>::iterator it=L.begin(); it!=L.end(); it++) { //L.end()는 list의 마지막 원소 다음 주소를 가리킨다.
        cout << *it << ' '; //10 6 1 5
    }
    cout << '\n';

    cout << L.size() << '\n'; //4

    return 0;
}
