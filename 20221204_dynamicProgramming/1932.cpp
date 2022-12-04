#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;
    int triangle[n+1][n+1];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> triangle[i][j];
        }
    }

    int dpArray[n+1][n+1];

    //초기값 설정
    dpArray[1][1] = triangle[1][1];
    //점화식 설정
    for (int i=2; i<=n; i++) {
        dpArray[i][1] = dpArray[i-1][1] + triangle[i][1];
        for (int j=2; j<i; j++) {
            dpArray[i][j] = max(dpArray[i-1][j-1], dpArray[i-1][j])+triangle[i][j];
        }
        dpArray[i][i] = dpArray[i-1][i-1] + triangle[i][i];
    }

    int result = 0;
    for (int i=1; i<=n; i++) {
        result = max(result, dpArray[n][i]);
    }
    cout << result;
    return 0;
}
