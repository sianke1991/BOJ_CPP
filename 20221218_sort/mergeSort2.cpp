#include <iostream>


using namespace std;

int n=10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001];

//mid=(st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어 있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합침
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
    if (en<=st+1) return ; //길이가 1인 경우
    int mid = (st+en)/2;
    merge_sort(st, mid); //arr[st:mid]를 정렬 (배열의 전반을 정렬)
    merge_sort(mid, en); //arr[mid:en]을 정렬 (배열의 후반을 정렬)
    merge(st, en); //두 배열 합침
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
    return 0;
}
