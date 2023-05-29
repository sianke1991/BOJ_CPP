#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 15, 100}
    ms.insert(-10); ms.insert(15); //{-10, -10, 15, 15, 100} //multiset은 원소의 중복을 허용한다.
    cout << ms.size() << '\n'; //5

    for (int elem:ms) {
        cout << elem << ' '; //-10 -10 15 15 100
    }
    cout << '\n';

    cout << ms.erase(15) << '\n'; //2 //multiset에서 원소를 지우는 메서드는 중복된 원소에 대해 모든 원소를 지우는 것이다. 지운 원소의 개수를 반환한다.
    for (int elem:ms) {
        cout << elem << ' '; //-10 -10 100
    }
    cout << '\n';

    ms.erase(ms.find(-10)); //{-10, 100} //multiset 내 중복된 원소에 대해 하나만 지우고 싶으면 iterator를 erase 메서드의 인자로 준다.
    ms.insert(100); //{-10, 100, 100}
    for (int elem:ms) {
        cout << elem << ' '; //-10 100 100
    }
    cout << '\n';
    cout << ms.count(100) << '\n'; //2 //multiset내 원소 100의 개수
    ms.insert(50); //{-10, 50, 100, 100}

    //iterator는 set이 unordered_set과 구별되는 점이다.
    multiset<int>::iterator it0 = ms.begin(); //{-10<-it0, 50, 100, 100}
    cout << *it0 << '\n'; //-10

    it0++; //{-10, 50<-it0, 100, 100}
    multiset<int>::iterator it1 = prev(it0); //{-10<-it1, 50<-it0, 100, 100}
    it1 = next(it0); //{-10, 50<-it0, 100<-it1, 100}
    advance(it1, -2); //{-10<-it1, 50<-it0, 100, 100}

    multiset<int>::iterator it2 = ms.lower_bound(40); //{-10<-it1, 50<-it0, it2, 100, 100} //40 이상의 원소 중 최소치를 가리킨다.
    multiset<int>::iterator it3 = ms.upper_bound(40); //{-10<-it1, 50<-it0, it2, it3, 100, 100} //40 초과의 원소 중 최소치를 가리킨다.

    multiset<int>::iterator it4 = ms.lower_bound(50); //{-10<-it1, 50<-it0, it2, it3, it4, 100, 100} //50 이상의 원소 중 최소치를 가리킨다.
    multiset<int>::iterator it5 = ms.upper_bound(50); //{-10<-it1, 50<-it0, it2, it3, it4, 100<-it5, 100} //50 초과의 원소 중 최소치를 가리킨다.

    multiset<int>::iterator it6 = ms.find(-10); //{-10<-it1, it6, 50<-it0, it2, it3, it4, 100<-it5, 100}

    cout << *it0 << '\n'; //50
    cout << *it1 << '\n'; //-10
    cout << *it2 << '\n'; //50
    cout << *it3 << '\n'; //50
    cout << *it4 << '\n'; //50
    cout << *it5 << '\n'; //100
    cout << *it6 << '\n'; //-10

    return 0;
}
