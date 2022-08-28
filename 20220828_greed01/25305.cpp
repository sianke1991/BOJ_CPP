#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int x, int y){
    return x>y;
}

int main() {
    int N, k;
    cin >> N >> k;

    int points[N];
    for (int i=0; i<N; i++) {
        cin >> points[i];
    }

    sort(points, points+N, compare);

    cout << points[k-1];

    return 0;
}
