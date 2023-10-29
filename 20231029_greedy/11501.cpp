#include <iostream>
#include <vector>

using namespace std;

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int stoke[1000001];
int localMax[1000001];
vector<long long> results;
int main() {
    int numTests;
    cin >> numTests;
    for (int testCase=0; testCase<numTests; testCase++) {
        int numStokes;
        cin >> numStokes;
        for (int i=0; i<numStokes; i++) {
            cin >> stoke[i];
        }
        localMax[numStokes] = 0;
        for (int i=numStokes-1; i>=0; i--) {
            localMax[i] = max(stoke[i], localMax[i+1]);
        }
        long long result = 0LL;
        for (int i=0; i<numStokes; i++) {
            result += localMax[i]-stoke[i];
        }
        results.push_back(result);
    } //testCase loop


    for (long long result:results) {
        cout << result << '\n';
    }
    return 0;
}
