#include <bits/stdc++.h>
using namespace std;

/*cmp(a, a)�� false �� ������ �Լ��� �����ؾ� �Ѵ�.*/
bool cmp(int a, int b) {
    if (abs(a)!=abs(b)) {
        return abs(a)>abs(b); //�켱���� ť���� b�� ���� Ƣ����µ� �� ������ ����Ѵ�.
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
    priority_queue<int, vector<int>, Compare> pq; //cmp ��� Compare�� ����ؾ� �Ѵ�.
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
