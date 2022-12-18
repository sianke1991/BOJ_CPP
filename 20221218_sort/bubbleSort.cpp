#include <iostream>


using namespace std;


int main() {
    int arr[] = {2, 13, 6, 4, -2};
    int arrSize = (sizeof arr)/(sizeof *arr);

    for (int i=0; i<arrSize-1; i++) {
        for (int j=0; j<arrSize-1; j++) {
            if (arr[j]>arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        } //j loop
    } //i loop

    for (int i=0; i<arrSize; i++) {
        cout << arr[i] <<' ';
    }
    return 0;
}
