#include <bits/stdc++.h>

using namespace std;

class Cmp0 {
    public:
        //�켱���� ť���� b�� ���� Ƣ����µ� (=b�� a���� �� ���� �켱������ �ο��ϴµ�) �� ������ ����Ѵ�.
        //�� ��� ���� Ƣ����� �� b�� �׷��� ���� �� a���� �� �۴�. ��, �� ���� ���� ���� Ƣ����� �ּ� ���� ����� �����̴�.
        bool operator() (int a, int b) {
            return a>b;
        }
};

int main() {
    priority_queue<int> pq0; //�ִ� �� //�켱���� ť�� �� ���� �� ���� Ŭ ���� �켱������ ũ��. ��, �켱���� ť���� ���� ���� �� ���� ū ���� ���� ����������.
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


    priority_queue<int, vector<int>, greater<int>> pq1; //�ּ� �� //�켱���� ť�� �� ���� �� ���� ���� ���� �켱������ ũ��.
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

    priority_queue<int, vector<int>, Cmp0> pq2; //�켱������ �ο��ϴ� �������� Cmp0�� ����ϴ� �켱���� ť
    pq2.push(10); pq2.push(2); pq2.push(5); pq2.push(9); //{2, 5, 9, 10}
    while (!pq2.empty()) {
        cout << pq2.top() << ' '; //2 5 9 10
        pq2.pop();
    }
    cout << '\n';

    priority_queue<pair<int, int>> pq3; //pair�� �ִ� �� //first ���� ū pair�� �� ū �켱������ ���� �켱���� ť�̴�.
    pq3.push({3, 2}); pq3.push({2, 6}); pq3.push({4, 5}); pq3.push({3, 4}); pq3.push({6, 3}); pq3.push({4, 1});
    while (!pq3.empty()) {
        pair<int, int> p = pq3.top();
        cout << '{' << p.first << ", " << p.second << "} "; //{6, 3} {4, 5} {4, 1} {3, 4} {3, 2} {2, 6}
        pq3.pop();
    }
    cout << '\n';

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq4; //pair�� �ּ� �� //first ���� �� ���� pair�� �� ū �켱������ ���� �켱���� ť�̴�.
    pq4.push({3, 2}); pq4.push({2, 6}); pq4.push({4, 5}); pq4.push({3, 4}); pq4.push({6, 3}); pq4.push({4, 1});
    while (!pq4.empty()) {
        pair<int, int> p = pq4.top();
        cout << '{' << p.first << ", " << p.second << "} "; //{2, 6} {3, 2} {3, 4} {4, 1} {4, 5} {6, 3}
        pq4.pop();
    }
    cout << '\n';

    priority_queue<tuple<int, int, int>> pq5; //tuple�� �ִ� �� //get<0> ���� ū tuple�� �� ū �켱������ ���� �켱���� ť�̴�.
    pq5.push({4, 3, 3}); pq5.push({1, 1, 3}); pq5.push({5, 6, 3}); pq5.push({6, 1, 2}); pq5.push({1, 6, 3}); pq5.push({1, 6, 1});
    while (!pq5.empty()) {
        tuple<int, int, int> t = pq5.top();
        cout << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ") "; //(6, 1, 2) (5, 6, 3) (4, 3, 3) (1, 6, 3) (1, 6, 1) (1, 1, 3)
        pq5.pop();
    }
    cout << '\n';

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq6; //tuple�� �ּ� �� //get<0> ���� ���� tuple�� �� ū �켱������ ���� �켱���� ť�̴�.
    pq6.push({4, 3, 3}); pq6.push({1, 1, 3}); pq6.push({5, 6, 3}); pq6.push({6, 1, 2}); pq6.push({1, 6, 3}); pq6.push({1, 6, 1});
    while (!pq6.empty()) {
        tuple<int, int, int> t = pq6.top();
        cout << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ") "; //(1, 1, 3) (1, 6, 1) (1, 6, 3) (4, 3, 3) (5, 6, 3) (6, 1, 2)
        pq6.pop();
    }
    cout << '\n';

    return 0;
}
