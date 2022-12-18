#include <iostream>


using namespace std;

int n=10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001];

//mid=(st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ� �ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ħ
void merge(int st, int en) {
    int mid = (st+en)/2;
    int leftIdx = st, rightIdx = mid;
    for (int i=st; i<en; i++) {
        if (leftIdx>=mid) {
            tmp[i]=arr[rightIdx++];
        } else if (rightIdx>=en) {
            tmp[i]=arr[leftIdx++];
        } else {
            if (arr[leftIdx]<arr[rightIdx]) {
                tmp[i]=arr[leftIdx++];
            } else {
                tmp[i]=arr[rightIdx++];
            }
        }
    }
    for (int i=st; i<en; i++) {
        arr[i] = tmp[i];
    }
}



void merge_sort(int st, int en) {
    if (en<=st+1) return ; //���̰� 1�� ���
    int mid = (st+en)/2;
    merge_sort(st, mid); //arr[st:mid]�� ���� (�迭�� ������ ����)
    merge_sort(mid, en); //arr[mid:en]�� ���� (�迭�� �Ĺ��� ����)
    merge(st, en); //�� �迭 ��ħ
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
    return 0;
}
