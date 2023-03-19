#include <bits/stdc++.h>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;
    vector<string> results; //각 테스트케이스에 대해 최대, 최소치를 저장하는 벡터
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
                    if (dualPQ.empty()) //이중 우선순위 큐가 비어있으면 삭제를 수행하지 않는다.
                        continue;
                    if (operNum==-1) { //최솟값 삭제
                        dualPQ.erase(dualPQ.begin());
                    } else if (operNum==1) { //최댓값 삭제
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
