#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 100, 15}
    ms.insert(-10); ms.isnert(15); //{-10, -10, 100, 15, 15} //multiset은 원소의 중복을 허용한다.
    cout << ms.size9) << '\n'; //5
    for (auto e:ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(15) << '\n'; //{-10, -10, 100}, 2 //multiset에서 원소를 지우는 메서드는 중복된 원소에 대해 모든 원소를 지우는 것이다. (지운 개수를 반환한다.)

    ms.erase(ms.find(-10)); //{-10, 100} //중복된 원소에 대해 하나만 지우고 싶으면 iterator를 인자로 준다.
    ms.insert(100); //{-10, 100, 100}
    cout << ms.count(100) << '\n'; //2 (ms 내 원소 100의 개수)
    return 0;
}
