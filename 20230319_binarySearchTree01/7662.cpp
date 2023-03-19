#include <bits/stdc++.h>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;
    vector<string> results; //�� �׽�Ʈ���̽��� ���� �ִ�, �ּ�ġ�� �����ϴ� ����
    for (int testCase=0; testCase<numTestCases; testCase++) {
        int numOperators;
        multiset<int> dualPQ;
        cin >> numOperators;
        for (int oper=0; oper<numOperators; oper++) {
            char operType;
            int operNum;
            cin >> operType >> operNum;
            switch (operType) {
                case 'I': case 'i':
                    dualPQ.insert(operNum);
                    break;
                case 'D': case 'd':
                    if (dualPQ.empty()) //���� �켱���� ť�� ��������� ������ �������� �ʴ´�.
                        continue;
                    if (operNum==-1) { //�ּڰ� ����
                        dualPQ.erase(dualPQ.begin());
                    } else if (operNum==1) { //�ִ� ����
                        dualPQ.erase(prev(dualPQ.end()));
                    }
                    break;
            }
        } //oper loop
        string result="";
        if (dualPQ.empty()) {
            result="EMPTY";
        } else {
            result = to_string(*(prev(dualPQ.end())))+" "+to_string(*(dualPQ.begin()));
        }
        results.push_back(result);
    } //testCase loop

    for (string result:results) {
        cout << result << '\n';
    }
    return 0;
}
