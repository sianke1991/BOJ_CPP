#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

/*
    �迭 �� �� ���� "���� ��"���� ���θ� �Ǵ��ϱ� ����
    �迭 �� �ٸ� �� ���� �����Ͽ�, "���� ���� ��"�� ����� ���� ������ �迭 ���� �����ϴ���
    �� ���θ� �����Ѵ�.

    �迭 �� �� ���� ���� ���� ���� �ٸ� ���Ҹ� ���ؾ� �ϹǷ�,
    �迭 ���� Ư�� ���� "�� ��" �ִ��� �����ؾ� �� �ʿ䰡 �ְ�,
    ���� �迭 �� ���� ������
    unordered_set<int> ���
    unordered_map<int, int>�� ����Ѵ�.
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
