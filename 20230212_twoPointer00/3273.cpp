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
        if (sum==x) { //�迭�� idxSt ��ġ�� ���� idxEd ��ġ�� ���� ���� x�� ���-
            cnt++;
            idxSt++;
        } else if (sum<x) { //�迭�� idxSt ��ġ�� ���� idxEd ��ġ�� ���� ���� x���� ���� ��� ���� Ű��� ���� idxSt�� �������Ѿ� �Ѵ�.
            idxSt++;
        } else { //�迭�� idxSt ��ġ�� ���� idxEd ��ġ�� ���� ���� x���� ū ��� ���� ���̱� ���� idxEd�� ���ҽ��Ѿ� �Ѵ�.
            idxEd--;
        }
    } //while loop
    cout << cnt;
    return 0;
}
