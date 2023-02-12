#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n); //sort an array
    int x;
    cin >> x;

    int idxSt = 0, idxEd = n-1;
    int cnt = 0, sum=0;
    while (idxEd>idxSt) {
        sum = arr[idxSt] + arr[idxEd];
        if (sum==x) { //배열의 idxSt 위치의 값과 idxEd 위치의 값의 합이 x인 경우-
            cnt++;
            idxSt++;
        } else if (sum<x) { //배열의 idxSt 위치의 값과 idxEd 위치의 값의 합이 x보다 작은 경우 합을 키우기 위해 idxSt를 증가시켜야 한다.
            idxSt++;
        } else { //배열의 idxSt 위치의 값과 idxEd 위치의 값의 합이 x보다 큰 경우 합을 줄이기 위해 idxEd를 감소시켜야 한다.
            idxEd--;
        }
    } //while loop
    cout << cnt;
    return 0;
}
