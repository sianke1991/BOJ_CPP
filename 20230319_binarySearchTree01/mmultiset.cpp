//이진검색트리가 적용된 자료구조는 set, multiset, map이다.
#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 15, 100}
    ms.insert(-10); ms.insert(15); //{-10, -10, 15, 15, 100}
    cout << ms.size() << '\n'; //5
    for (auto e:ms) cout << e <<' '; cout << '\n';
    cout << ms.erase(15) << '\n'; //{-10, -10, 100}, 2
    ms.erase(ms.find(-10)); //{-10, 100}
    ms.insert(100); //{-10, 100, 100}
    cout <<ms.count(100) << '\n'; //2 //log n 이 아니라 n에 비례한다.

    auto it1 = ms.begin(); //{-10<-it1, 100, 100}
    auto it2 = ms.upper_bound(100); //{-10, 100, 100} <-it2 //오름차순이 유지되는 가장 오른쪽 인덱스
    auto it3 = ms.find(100); //{-10, 100<-it3, 100} //ms에 들어있는 100 중 아무 하나를 가리킨다. 특별히 가장 낮은 idx를 가리키고 싶으면 lower_bound를 사용한다.
    cout << *it1 << '\n'; //-10
    cout << (it2==ms.end()) << '\n'; //1 //
    cout << *it3 << '\n'; //100
    return 0;


}
