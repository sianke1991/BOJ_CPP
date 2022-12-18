#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int arrSize = (int)(sizeof(arr)/sizeof(*arr));

    for (int i=0; i<arrSize-1; i++) {
        for (int j=i+1; j<arrSize; j++) {
            if (arr[j]<arr[i]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        } //j loop
    } //i loop

    for (int i=0; i<arrSize; i++) {
        cout << arr[i] << ' ';
    }

    int arr2[] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    for (int i=n-1; i>0; i--) {
        swap(*max_element(arr, arr+i+1), arr[i]);
    }

    return 0;
}
