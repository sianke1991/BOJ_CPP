#include <iostream>

using namespace std;

int arr[] = {6, -8, 1, 12, 8, 3, 7, -7};
//int leftIdx = 1;
//int rightIdx = sizeof(arr)/sizeof(*arr)-1;
//int pivotIdx = 0;

int splitArray(int leftIdx, int rightIdx);

/**
 * �迭 arr�� �����Ѵ�. (leftIdx���� rightIdx-1����)
 */
void quickSort(int leftIdx, int rightIdx) {
    //base case
    if (rightIdx<=leftIdx+1) {
        return;
    }
    int splitIdx = splitArray(leftIdx, rightIdx);
    quickSort(leftIdx, splitIdx); //���ڸ��� ã�� pivot�� ���� �κ��� �����Ѵ�.
    quickSort(splitIdx+1, rightIdx); //���ڸ��� ã�� pivot�� ������ �κ��� �����Ѵ�.
}

/**
 * �迭 arr�� pivot�� �߽����� �ѷ� ������. (leftIdx���� rightIdx-1������ �������� ����Ѵ�.)
 * �迭�� ���� �� pivot�� ��ġ�� ��ȯ�Ѵ�.
 */
int splitArray(int leftIdx, int rightIdx) {
    int pivotIdx = leftIdx;
    rightIdx--;
    while (1) { //leftIdx�� �ش� ��ġ�� ���� pivot���� ū ��쿡 �����Ѵ�. rightIdx�� �ش� ��ġ�� ���� pivot���� �۰ų� ���� ��쿡 �����Ѵ�. �� �ݺ��� leftIdx�� rightIdx���� Ŭ �� �����.
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
    while (1) { //leftIdx�� �ش� ��ġ�� ���� pivot���� ū ��쿡 �����Ѵ�. rightIdx�� �ش� ��ġ�� ���� pivot���� �۰ų� ���� ��쿡 �����Ѵ�. �� �ݺ��� leftIdx�� rightIdx���� Ŭ �� �����.
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
    //��κ��� ���� quick sort�� �����Ǿ� �ִ�.
    //�� �ܰ踶�� pivot�̶�� �θ��� ���Ҹ� �����Ѵ�.
    quickSort(0, sizeof(arr)/sizeof(*arr));
    for (int i=0; i<sizeof(arr)/sizeof(*arr); i++) {
        cout << arr[i] << ' ';
    } //i loop
    cout << '\n';
    return 0;
}

/*
 * ��������� quickSort�� mergeSort���� ������.
 * overhead(�߰������� �ʿ��� ����): mergeSort�� �ݵ�� �ʿ�, quickSort�� ���ʿ�
 * in-place sort: �߰����� ������ ���ʿ��� ����
 *
 */

