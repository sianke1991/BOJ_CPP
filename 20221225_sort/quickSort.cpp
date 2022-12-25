#include <iostream>

using namespace std;

int arr[] = {6, -8, 1, 12, 8, 3, 7, -7};
//int leftIdx = 1;
//int rightIdx = sizeof(arr)/sizeof(*arr)-1;
//int pivotIdx = 0;

int splitArray(int leftIdx, int rightIdx);

/**
 * 배열 arr을 정렬한다. (leftIdx부터 rightIdx-1까지)
 */
void quickSort(int leftIdx, int rightIdx) {
    //base case
    if (rightIdx<=leftIdx+1) {
        return;
    }
    int splitIdx = splitArray(leftIdx, rightIdx);
    quickSort(leftIdx, splitIdx); //제자리를 찾은 pivot의 왼쪽 부분을 정렬한다.
    quickSort(splitIdx+1, rightIdx); //제자리를 찾은 pivot의 오른쪽 부분을 정렬한다.
}

/**
 * 배열 arr를 pivot을 중심으로 둘로 나눈다. (leftIdx부터 rightIdx-1까지의 범위만을 고려한다.)
 * 배열을 나눈 뒤 pivot의 위치를 반환한다.
 */
int splitArray(int leftIdx, int rightIdx) {
    int pivotIdx = leftIdx;
    rightIdx--;
    while (1) { //leftIdx는 해당 위치의 값이 pivot보다 큰 경우에 정지한다. rightIdx는 해당 위치의 값이 pivot보다 작거나 같은 경우에 정지한다. 이 반복은 leftIdx가 rightIdx보다 클 때 멈춘다.
        while (arr[leftIdx]<=arr[pivotIdx]) leftIdx++;
        while (arr[rightIdx]>arr[pivotIdx]) rightIdx--;
        if (leftIdx<=rightIdx) {
            int tmp = arr[rightIdx];
            arr[rightIdx] = arr[leftIdx];
            arr[leftIdx] = tmp;
        } else {
            int tmp = arr[rightIdx];
            arr[rightIdx] = arr[pivotIdx];
            arr[pivotIdx] = tmp;
            break;
        }
    } //while loop
    return rightIdx;
}

/*
void locatePivot() {
    while (1) { //leftIdx는 해당 위치의 값이 pivot보다 큰 경우에 정지한다. rightIdx는 해당 위치의 값이 pivot보다 작거나 같은 경우에 정지한다. 이 반복은 leftIdx가 rightIdx보다 클 때 멈춘다.
        while (arr[leftIdx]<=arr[pivotIdx]) {
            leftIdx++;
        }
        while (arr[rightIdx]>arr[pivotIdx]) {
            rightIdx--;
        }
        if (leftIdx<=rightIdx) {
            int tmp = arr[rightIdx];
            arr[rightIdx] = arr[leftIdx];
            arr[leftIdx] = tmp;
        } else {
            int tmp = arr[rightIdx];
            arr[rightIdx] = arr[pivotIdx];
            arr[pivotIdx] = tmp;
            pivotIdx = rightIdx;
            break;
        }
    }
}
*/

int main() {
    //대부분의 언어는 quick sort로 구현되어 있다.
    //매 단계마다 pivot이라고 부르는 원소를 지정한다.
    quickSort(0, sizeof(arr)/sizeof(*arr));
    for (int i=0; i<sizeof(arr)/sizeof(*arr); i++) {
        cout << arr[i] << ' ';
    } //i loop
    cout << '\n';
    return 0;
}

/*
 * 평균적으로 quickSort가 mergeSort보다 빠르다.
 * overhead(추가적으로 필요한 공간): mergeSort는 반드시 필요, quickSort는 불필요
 * in-place sort: 추가적인 공간이 불필요한 정렬
 *
 */

