#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

/*
    배열 내에서 특정 원소의 개수를 구하기 위해
    배열을 정렬한 뒤
    upper_bound 및 lower_bound 함수를 사용할 수 있다.
    두 값의 차이가 배열 내 해당 원소의 개수이다.
*/

int numElems;
int arr[2000];

int countElem(int elem) {
    return upper_bound(arr, arr+numElems, elem) - lower_bound(arr, arr+numElems, elem);
}

int main() {
    scanf("%d", &numElems);
    for (int i=0; i<numElems; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+numElems);


    int result = 0;
    for (int i=0; i<numElems; i++) {
        int sum = arr[i];
        bool flag = false;
        for (int j=0; j<i; j++) {
            if (flag) break;
            int arg0 = arr[j];
            int arg1 = sum-arg0;
            if (arg0==0) {
                if (sum==0) {
                    if (countElem(arg1)>=3) flag = true;
                } else {
                    if (countElem(arg1)>=2) flag = true;
                }
            } else if (arg0==arg1) {
                if (countElem(arg1)>=2) flag = true;
            } else {
                if (countElem(arg1)>=1) flag = true;
            }
        } //j loop - a

        for (int j=i+1; j<numElems; j++) {
            if (flag) break;
            int arg0 = arr[j];
            int arg1 = sum-arg0;
            if (arg0==0) {
                if (sum==0) {
                    if (countElem(arg1)>=3) flag = true;
                } else {
                    if (countElem(arg1)>=2) flag = true;
                }
            } else if (arg0==arg1) {
                if (countElem(arg1)>=2) flag = true;
            } else {
                if (countElem(arg1)>=1) flag = true;
            }
        } //j loop - b

        if (flag) {
            result++;
        }
    } //i loop

    printf("%d", result);
    return 0;

}
