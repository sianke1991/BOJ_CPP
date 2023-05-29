#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    q.push(10); //{10}
    q.push(25); //{10, 25}
    q.push(30); //{10, 25, 30}

    cout << q.size() << '\n'; //3
    cout << q.front() << '\n'; //10 //stack에 남아있는 원소 중 가장 오래된 원소를 조회한다.

    if (q.empty()) cout << "q is empty.\n";
    else            cout << "q is not empty.\n";

    q.pop(); //{25, 30} //queue에 남아있는 원소 중 가장 오래된 원소를 제거한다.
             //queue에 남아있는 원소 중 가장 오래된 원소를 제거할 뿐, 그 원소를 반환하지는 않는다.
    cout << q.front() << '\n'; //25

    return 0;
}
