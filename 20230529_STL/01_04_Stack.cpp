#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> s;
    s.push(10); //{10}
    s.push(25); //{10, 25}
    s.push(30); //{10, 25, 30}

    cout << s.size() << '\n'; //3
    if (s.empty()) cout << "s is empty.\n";
    else            cout << "s is not empty.\n";

    s.pop(); //{10, 25} //stack에 남아있는 원소 중 가장 새로운 원소를 제거한다.
             //stack에 남아있는 원소 중 가장 새로운 원소를 제거할 뿐, 그 원소를 반환하지는 않는다.
    cout << s.top() << '\n'; //25 //stack에 남아있는 원소 중 가장 새로운 원소를 조회한다.

    return 0;
}
