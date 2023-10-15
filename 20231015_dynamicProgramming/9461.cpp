#include <iostream>
#include <vector>

using namespace std;

long long p[101];

int main() {
    //base cases
    p[0] = 1;
    p[1] = p[0];
    p[2] = p[1];
    p[3] = p[0]+p[2];
    p[4] = p[3];
    //점화식 (새로 그려지는 삼각형은 바로 직전 삼각형과 5번째 전 삼각형과 맞닿게 된다.)
    for (int i=5; i<100; i++) {
        p[i] = p[i-5]+p[i-1];
    }

    int numCases;
    cin >> numCases;
    vector<long long> results;
    for (int caseNumber=0; caseNumber<numCases; caseNumber++) {
        int N;
        cin >> N;
        results.push_back(p[N-1]);
    } //caseNumber loop

    for (long long result:results) {
        cout << result << '\n';
    }

    return 0;
}
