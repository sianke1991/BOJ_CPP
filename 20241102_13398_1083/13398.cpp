#include <iostream>

using namespace std;

int n;
int arr[100000] = {};
int dp[100000][2] = {}; //dp[i][0] := ���Ҹ� �������� �ʰ� ���� �� �ִ� ���� �ִ�ġ, dp[i][1] := ���Ҹ� �����ϰ� ���� �� �ִ� ���� �ִ�ġ

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    int result = arr[0];
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];

    for (int i=1; i<n; i++) {
        dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);

        result = max(result, dp[i][0]);
        result = max(result, dp[i][1]);
    } //i loop

    cout << result;
    return 0;
}
