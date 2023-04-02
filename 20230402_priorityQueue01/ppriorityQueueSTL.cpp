#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int> pq; //최대 힙
    // priority_queue<int, vector<int>, greater<int>> 로 선언 시 최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9); // {10, 2, 5, 9}
    cout << pq.top() << '\n'; //10
    pq.pop(); //{2, 5, 9}
    cout << pq.size() << '\n'; //3
    if (pq.empty()) cout << "PQ is empty\n";
    else cout << "PQ is not empty\n";
    pq.pop(); //{2, 5}
    cout << pq.top() << '\n'; //5
    pq.push(5); pq.push(15); //{2, 5, 5, 15}
    cout << pq.top() << '\n'; //15
    return 0;
}

/*
priority queue가 수행하는 연산은 set (TreeSet)도 지원을 하고 시간복잡도도 같다.
하지만 실제 연산을 수행할 때에는 priority queue가 set보다 적게 걸리고, 공간도 적게 사용한다.
(set은 이진 탐색 트리에 편향이 일어날 때, 균형을 맞추는데 시간이 걸린다.)
*/
