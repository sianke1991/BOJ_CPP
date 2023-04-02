#include <bits/stdc++.h>
using namespace std;

/*cmp(a, a)는 false 가 나도록 함수를 설계해야 한다.*/
bool cmp(int a, int b) {
    if (abs(a)!=abs(b)) {
        return abs(a)>abs(b); //우선순위 큐에서 b가 먼저 튀어나오는데 그 조건을 명시한다.
    } else {
        return a>b;
    }
}

class Compare {
    public:
        bool operator() (int a, int b) {
            return cmp(a, b);
        }
};

int main() {
    priority_queue<int, vector<int>, Compare> pq; //cmp 대신 Compare를 사용해야 한다.
    int numOperations;
    vector<int> results;
    cin >> numOperations;
    for (int i=0; i<numOperations; i++) {
        int operation;
        cin >> operation;
        if (operation==0) { //pop
            if (pq.empty()) {
                results.push_back(0);
            } else {
                results.push_back(pq.top());
                pq.pop();
            }
        } else { //push
            pq.push(operation);
        }
    }
    for (int result:results) {
        cout << result <<'\n';
    }
    return 0;
}
