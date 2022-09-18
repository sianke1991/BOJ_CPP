#include <iostream>


using namespace std;

//insert, erase -  array를 이용한 함수
void insert(int idx, int num, int arr[], int& len) {
    for (int i=len; i>idx; i--) {
        arr[i] = arr[i-1];
    }
    arr[idx] = num;
    len++;
}

void insertTest() {
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    insert(3, 40, arr, len); // {10, 50, 40, 40, 30, 70, 20}
    for (int i=0; i<len; i++) {
        cout << arr[i] << ' ';
    }
}


void erase(int idx, int arr[], int& len) {
    for (int i=idx; i<len-1; i++) {
        arr[i] = arr[i+1];
    }
    len--;
}

void eraseTest() {
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    erase(4, arr, len); //{10, 50, 40, 30, 20}
    for (int i=0; i<len; i++) {
        cout << arr[i] << ' ';
    }
}


int main() {
    eraseTest();

    return 0;
}
