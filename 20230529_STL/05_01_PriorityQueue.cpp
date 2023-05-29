#include <bits/stdc++.h>

using namespace std;

class Cmp0 {
    public:
        //우선순위 큐에서 b가 먼저 튀어나오는데 (=b가 a보다 더 높은 우선순위를 부여하는데) 그 조건을 명시한다.
        //이 경우 먼저 튀어나오는 값 b는 그렇지 않은 값 a보다 더 작다. 즉, 더 작은 값이 먼저 튀어나오는 최소 힙을 만드는 조건이다.
        bool operator() (int a, int b) {
            return a>b;
        }
};

int main() {
    priority_queue<int> pq0; //최대 힙 //우선순위 큐에 들어간 원소 중 값이 클 수록 우선순위가 크다. 즉, 우선순위 큐에서 값을 꺼낼 때 가장 큰 값이 먼저 빠져나간다.
    pq0.push(10); pq0.push(2); pq0.push(5); pq0.push(9); //{10, 9, 5, 2}
    cout << pq0.top() << '\n'; //10
    pq0.pop(); //{9, 5, 2}
    cout << pq0.size() << '\n'; //3
    if (pq0.empty()) cout << "pq0 is empty.\n";
    else              cout << "pq0 is not empty.\n";
    pq0.pop(); //{5, 2}
    cout << pq0.top() << '\n'; //5
    pq0.push(5); pq0.push(15); //{15, 5, 5, 2}
    cout << pq0.top() << '\n'; //15


    priority_queue<int, vector<int>, greater<int>> pq1; //최소 힙 //우선순위 큐에 들어간 원소 중 값이 작을 수록 우선순위가 크다.
    pq1.push(10); pq1.push(2); pq1.push(5); pq1.push(9); //{2, 5, 9, 10}
    cout << pq1.top() << '\n'; //2
    pq1.pop(); //{5, 9, 10}
    cout << pq1.size() << '\n'; //3
    if (pq1.empty()) cout << "pq1 is empty.\n";
    else              cout << "pq1 is not empty.\n";
    pq1.pop(); //{9, 10}
    cout << pq1.top() << '\n'; //9
    pq1.push(5); pq1.push(15); //{5, 9, 10, 15}
    cout << pq1.top() << '\n'; //5

    priority_queue<int, vector<int>, Cmp0> pq2; //우선순위를 부여하는 조건으로 Cmp0를 사용하는 우선순위 큐
    pq2.push(10); pq2.push(2); pq2.push(5); pq2.push(9); //{2, 5, 9, 10}
    while (!pq2.empty()) {
        cout << pq2.top() << ' '; //2 5 9 10
        pq2.pop();
    }
    cout << '\n';

    priority_queue<pair<int, int>> pq3; //pair의 최대 힙 //first 값이 큰 pair가 더 큰 우선순위를 갖는 우선순위 큐이다.
    pq3.push({3, 2}); pq3.push({2, 6}); pq3.push({4, 5}); pq3.push({3, 4}); pq3.push({6, 3}); pq3.push({4, 1});
    while (!pq3.empty()) {
        pair<int, int> p = pq3.top();
        cout << '{' << p.first << ", " << p.second << "} "; //{6, 3} {4, 5} {4, 1} {3, 4} {3, 2} {2, 6}
        pq3.pop();
    }
    cout << '\n';

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq4; //pair의 최소 힙 //first 값이 더 작은 pair가 더 큰 우선순위를 갖는 우선순위 큐이다.
    pq4.push({3, 2}); pq4.push({2, 6}); pq4.push({4, 5}); pq4.push({3, 4}); pq4.push({6, 3}); pq4.push({4, 1});
    while (!pq4.empty()) {
        pair<int, int> p = pq4.top();
        cout << '{' << p.first << ", " << p.second << "} "; //{2, 6} {3, 2} {3, 4} {4, 1} {4, 5} {6, 3}
        pq4.pop();
    }
    cout << '\n';

    priority_queue<tuple<int, int, int>> pq5; //tuple의 최대 힙 //get<0> 값이 큰 tuple이 더 큰 우선순위를 갖는 우선순위 큐이다.
    pq5.push({4, 3, 3}); pq5.push({1, 1, 3}); pq5.push({5, 6, 3}); pq5.push({6, 1, 2}); pq5.push({1, 6, 3}); pq5.push({1, 6, 1});
    while (!pq5.empty()) {
        tuple<int, int, int> t = pq5.top();
        cout << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ") "; //(6, 1, 2) (5, 6, 3) (4, 3, 3) (1, 6, 3) (1, 6, 1) (1, 1, 3)
        pq5.pop();
    }
    cout << '\n';

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq6; //tuple의 최소 힙 //get<0> 값이 작은 tuple이 더 큰 우선순위를 갖는 우선순위 큐이다.
    pq6.push({4, 3, 3}); pq6.push({1, 1, 3}); pq6.push({5, 6, 3}); pq6.push({6, 1, 2}); pq6.push({1, 6, 3}); pq6.push({1, 6, 1});
    while (!pq6.empty()) {
        tuple<int, int, int> t = pq6.top();
        cout << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ") "; //(1, 1, 3) (1, 6, 1) (1, 6, 3) (4, 3, 3) (5, 6, 3) (6, 1, 2)
        pq6.pop();
    }
    cout << '\n';

    return 0;
}
