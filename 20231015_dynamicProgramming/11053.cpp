#include <iostream>

using namespace std;

/**이 문제는 11055 문제와 유사하므로 해당 문제의 해설을 참조할 것*/

int arr[1001];
int dpCache[1001];

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i]>arr[j]) {
                dpCache[i] = max(dpCache[i], dpCache[j]+1);
            }
        } //j loop
    } //i loop

    int optResult = 0;
    for (int i=0; i<n; i++) {
        optResult = max(optResult, dpCache[i]);
    }
    cout << optResult+1 << '\n';
    /*
    for (int i=0; i<n; i++) {
        cout << dpCache[i] << ' ';
    }
    */
    return 0;
}
