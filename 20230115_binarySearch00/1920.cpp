#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> numSet;
vector<int> targetSet;
vector<int> containessList;

bool binarySearch(int from, int to, int target) {
    if (to<=from) return false;
    if (to==from+1) {
        return numSet[from]==target;
    }
    int center = (from+to)/2;
    if (numSet[center]==target) return true;
    if (numSet[center]<target) return binarySearch(center+1, to, target);
    return binarySearch(from, center, target);
}

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int n;
        cin >> n;
        numSet.push_back(n);
    }
    sort(numSet.begin(), numSet.end());
    int M;
    cin >> M;
    for (int i=0; i<M; i++) {
        int m;
        cin >> m;
        targetSet.push_back(m);
    }
    for (int i=0; i<M; i++) {
        if (binarySearch(0, numSet.size(), targetSet[i]))
            containessList.push_back(1);
        else
            containessList.push_back(0);
    }
    for (int containess:containessList) {
        cout << containess << '\n';
    }
    return 0;
}
