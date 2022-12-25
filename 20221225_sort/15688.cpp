#include<iostream>
//counting sort
using namespace std;

int profile[2000001];
int n;
int beforeSorting[1000000];
//int afterSorting[1000000];
//int afterSortingIdx=0;

int valToIdx (int val) {
    return val+1000000;
}
int idxToVal (int idx) {
    return idx-1000000;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> beforeSorting[i];
    for (int i=0; i<n; i++) {
        profile[valToIdx(beforeSorting[i])]++;
    }
    int j=0;
    for (int i=0; i<n; i++) {
        while (profile[j]==0) j++;
        profile[j]--;
        //afterSorting[i] = idxToVal(j);
        cout << idxToVal(j) << '\n';
    }
    /*
    for (int i=0; i<n; i++) {
        cout << afterSorting[i] << '\n';
    }
    */
    return 0;
}
