//이진검색트리가 적용된 자료구조는 set, multiset, map이다.
#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    s.insert(-10); s.insert(100); s.insert(15);
    //{-10, 15, 100}
    cout << s.size() << '\n'; //3
    s.insert(15);
    //{-10, 15, 100}
    cout << s.size() << '\n'; //3
    for (auto elem:s) {
        cout << elem << ' '; //-10, 15, 100
    }
    cout << '\n';
    cout << s.erase(100) << '\n'; //{-10, 15}, 1
    cout << s.erase(20) << '\n'; //{-10, 15}, 0
    if (s.find(15) != s.end()) cout << "15 in s\n";
    else cout << "15 not in s\n";
    cout <<s.size()<<"\n"; //2
    cout << s.count(50)<<"\n"; //0
    for (auto e:s) cout << e << ' ';
    cout << '\n';
    s.insert(-40); //{-40, -10, 15}

    //iterator는 unordered set과 구별되는 점이다.
    set<int>::iterator it1 = s.begin(); //{-40<-it1, -10, 15}
    it1++; //{-40, -10<-it1, 15}
    auto it2 = prev(it1); //{-40<-it2, -10<-it1, 15}
    it2 = next(it1); //{-40, -10<-it1, 15<-it2}
    advance(it2, -2); //{-40<-it2, -10<-it1, 15}
    auto it3 = s.lower_bound(-20); //{-40, -10<-it3, 15}
    auto it4 = s.find(15); //{-40, -10, 15<-it4}
    cout << *it1 << '\n'; //-10
    cout << *it2 << '\n'; //-40
    cout << *it3 << '\n'; //-10
    cout << *it4 << '\n'; //15







    return 0;
}
