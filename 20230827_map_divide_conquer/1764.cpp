#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<string> setA; //�赵 ���� ��� ���
    vector<string> setB; //���� ���� ��� ���
    set<string> intersection;
    string strInput;

    for (int i=0; i<N; i++) {
        cin >> strInput;
        setA.insert(strInput);
    }

    for (int i=0; i<M; i++) {
        cin >> strInput;
        setB.push_back(strInput);
    }

    for (string b:setB) {
        if (setA.find(b)!=setA.end()) {
            intersection.insert(b);
        }
    }

    cout << intersection.size() << '\n';
    for (string i:intersection) {
        cout << i << '\n';
    }

    return 0;
}
