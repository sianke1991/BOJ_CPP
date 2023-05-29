#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); //{-10, 15, 100} //set은 원소가 오름차순으로 들어간다.
    cout << s.size() << '\n'; //3
    s.insert(15); //{-10, 15, 100} //set에 이미 들어간 값은 더 이상 들어가지 않는다.
    cout << s.size() << '\n'; //3

    for (int elem:s) {
        cout << elem << ' '; //-10 15 100
    }
    cout << '\n';

    cout << s.erase(100) << '\n'; //1 //erase는 set의 원소를 지우고, 지웠다면 1을 지우지 못했다면 0을 반환한다. (지운 원소의 개수를 반환한다.)
    cout << s.erase(20) << '\n'; //0

    if (s.find(15) != s.end()) { //find는 값을 찾아서 iterator를 반환하는데, 값을 발견하지 못했다면 end()를 반환한다.
        cout << "15 in s.\n";
    } else {
        cout << "15 not in s.\n";
    }

    cout << s.size() << '\n'; //2
    cout << s.count(50) << '\n'; //0 //set내 원소 50의 개수 (해당 원소가 있으면 1을, 없으면 0을 반환한다.)
    for (int elem:s) {
        cout << elem << ' '; //-10 15
    }
    cout << '\n';
    s.insert(-40); //{-40, -10, 15}

    //iterator는 set이 unordered_set과 구별되는 점이다.
    set<int>::iterator it0 = s.begin(); //{-40<-it0, -10, 15}
    cout << *it0 << '\n'; //-40

    it0++; //{-40, -10<-it0, 15}
    set<int>::iterator it1 = prev(it0); //{-40<-it1, -10<-it0, 15}
    it1 = next(it0); //{-40, -10<-it0, 15<-it1}
    advance(it1, -2); //{-40<-it1, -10<-it0, 15}

    set<int>::iterator it2 = s.lower_bound(-20); //{-40<-it1, -10<-it0, it2, 15} //-20 이상의 원소 중 최소치를 가리킨다.
    set<int>::iterator it3 = s.upper_bound(-20); //{-40<-it1, -10<-it0, it2, it3, 15} //-20 초과의 원소 중 최소치를 가리킨다.

    set<int>::iterator it4 = s.lower_bound(-10); //{-40<-it1, -10<-it0, it2, it3, it4, 15} //-10 이상의 원소 중 최소치를 가리킨다.
    set<int>::iterator it5 = s.upper_bound(-10); //{-40<-it1, -10<-it0, it2, it3, it4, 15<-it5} //-10 초과의 원소 중 최소치를 가리킨다.

    set<int>::iterator it6 = s.find(-40); //{-40<-it1, it6, -10<-it0, it2, it3, it4, 15<-it5}

    cout << *it0 << '\n'; //-10
    cout << *it1 << '\n'; //-40
    cout << *it2 << '\n'; //-10
    cout << *it3 << '\n'; //-10
    cout << *it4 << '\n'; //-10
    cout << *it5 << '\n'; //15
    cout << *it6 << '\n'; //-40

    return 0;
}
