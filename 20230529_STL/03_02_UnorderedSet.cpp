#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); //{-10, 100, 15} //set에 값을 넣는다.
    s.insert(-10); //{-10, 100, 15} //set에 이미 들어간 값은 더 이상 들어가지 않는다.

    cout << s.erase(100) << '\n'; //1 //erase는 set의 원소를 지우고, 지웠다면 1을 지우지 못했다면 0을 반환한다. (지운 원소의 개수를 반환한다.)
    cout << s.erase(20) << '\n'; //0

    if (s.find(15) != s.end()) { //find는 값을 찾아서 iterator를 반환하는데, 값을 발견하지 못했다면 end()를 반환한다.
        cout << "15 in s.\n";
    } else {
        cout << "15 not in s.\n";
    }

    cout << s.size() << '\n'; //2 //set 내 원소의 개수 (set의 크기)
    cout << s.count(50) << '\n'; //0 //set내 원소 50의 개수 (해당 원소가 있으면 1을, 없으면 0을 반환한다.)

    for (int elem:s) {
        cout << elem << ' '; //15 -10
    }
    cout << '\n';

    return 0;
}
