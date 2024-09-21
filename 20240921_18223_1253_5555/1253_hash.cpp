#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

/*
    배열 내 한 값이 "좋은 수"인지 여부를 판단하기 위해
    배열 내 다른 한 값을 선정하여, "예비 좋은 수"를 만들기 위한 보수가 배열 내에 존재하는지
    그 여부를 조사한다.

    배열 내 두 수를 더할 때는 서로 다른 원소를 더해야 하므로,
    배열 내에 특정 값이 "몇 개" 있는지 조사해야 할 필요가 있고,
    따라서 배열 내 값의 분포는
    unordered_set<int> 대신
    unordered_map<int, int>를 사용한다.
*/

int numElems;
int arr[2000];
unordered_map<int, int> freq;

int main() {
    scanf("%d", &numElems);
    for (int i=0; i<numElems; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]] += 1;
    }

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
                    if (freq[arg1]>=3) flag = true;
                } else {
                    if (freq[arg1]>=2) flag = true;
                }
            } else if (arg0==arg1) {
                if (freq[arg1]>=2) flag = true;
            } else {
                if (freq[arg1]>=1) flag = true;
            }
        } //j loop-a

        for (int j=i+1; j<numElems; j++) {
            if (flag) break;
            int arg0 = arr[j];
            int arg1 = sum-arg0;
            if (arg0==0) {
                if (sum==0) {
                    if (freq[arg1]>=3) flag = true;
                } else {
                    if (freq[arg1]>=2) flag = true;
                }
            } else if (arg0==arg1) {
                if (freq[arg1]>=2) flag = true;
            } else {
                if (freq[arg1]>=1) flag = true;
            }
        } //j loop-b

        if (flag) {
            result++;
        }
    } //i loop

    printf("%d", result);
    return 0;
}
