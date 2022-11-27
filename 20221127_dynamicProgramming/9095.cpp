#include <iostream>
#include <vector>

using namespace std;


int D[12] = {-1, 1, 2, 4}; //D[i]: i를 1, 2, 3으로 만들 수 있는 경우의 수
vector<int> results;

int getD(int idx) {
    if (D[idx]) return D[idx];
    for (int i=4; i<=idx; i++) {
        D[i] = D[i-3] + D[i-2] + D[i-1]; //점화식
    }
    return D[idx];
}


int main() {
    int T; //테스트 케이스 개수
    cin >> T;

    for (int testCase=0; testCase<T; testCase++) {
        int n;
        cin >> n;
        results.push_back(getD(n));
    } //testCase loop

    for (int result:results) {
        cout << result << '\n';
    }
    return 0;
}
