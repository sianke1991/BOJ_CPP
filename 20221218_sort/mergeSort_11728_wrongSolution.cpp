#include <iostream>


using namespace std;


int n, m;
int a[1000005], b[1000005], c[2000005];
int aIdx = 0, bIdx = 0;
int input() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<m; i++) {
        cin >> b[i];
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //input();
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    for (int i=0; i<n+m; i++) {
        if (aIdx>=n) {
            c[i] = b[bIdx++];
            //bIdx++;
        } else if (bIdx>=m) {
            c[i] = a[aIdx++];
            //aIdx++;
        } else {
            if (a[aIdx]<b[bIdx]) {
                c[i] = a[aIdx++];
                //aIdx++;
            } else {
                c[i] = b[bIdx++];
                //bIdx++;
            }
        }
    }
    for (int i=0; i<n+m; i++) {
        cout << c[i] << ' ';
    }
    return 0;
}
