#include <bits/stdc++.h>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;
    int results[numTestCases];
    for (int testCase=0; testCase<numTestCases; testCase++) {
        int numNodes, numEdges;
        cin >> numNodes >> numEdges;
        for (int edge=0; edge<numEdges; edge++) {
            int u, v;
            cin >> u >> v;
        } //edge loop
        results[testCase] = numNodes-1;
    } //testCase loop
    for (int result:results) {
        cout << result << '\n';
    }
    return 0;
}
