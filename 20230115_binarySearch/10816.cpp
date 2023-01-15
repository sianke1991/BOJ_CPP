#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cards;
vector<int> targets;
vector<int> results;

//target에서 target이 아닌 수로 변하는 시점을 반환한다.
int binarySearch3(int from, int to, int target) {
    if (cards[to-1]==target) return to;
    int mid = (from+to)/2;
    if (cards[mid]>target) return binarySearch3(from, mid, target);
    if (cards[mid]<target) return binarySearch3(mid+1, to, target);
    if (cards[mid+1]!=target) return mid+1;
    return binarySearch3(mid+1, to, target);
}

// target이 아닌 수에서 target으로 변하는 시점을 반환한다.
int binarySearch2(int from, int to, int target) {
    if (cards[from]==target) return from;
    int mid = (from+to)/2;
    if (cards[mid]>target) return binarySearch2(from, mid, target);
    if (cards[mid]<target) return binarySearch2(mid+1, to, target);
    if (cards[mid-1]!=target) return mid;
    return binarySearch2(from, mid, target);
}


int binarySearch(int from, int to, int target) {
    if (to<=from) return 0;
    int mid = (from+to)/2;
    if (cards[mid]>target) return binarySearch(from, mid, target);
    if (cards[mid]<target) return binarySearch(mid+1, to, target);
    /*
    int leftLimit = mid;
    int rightLimit = mid;
    while (leftLimit>=1 && cards[leftLimit-1]==target) leftLimit--;
    while (rightLimit<cards.size()-1 && cards[rightLimit+1]==target) rightLimit++;
    */
    return binarySearch3(mid, cards.size(), target) - binarySearch2(0, mid, target);
}


int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int n;
        cin >> n;
        cards.push_back(n);
    }
    sort(cards.begin(), cards.end());
    int M;
    cin >> M;
    for (int i=0; i<M; i++) {
        int m;
        cin >> m;
        targets.push_back(m);
    }
    for (int target:targets) {
        results.push_back(binarySearch(0, N, target));
    }
    for (int result:results) {
        cout << result << ' ';
    }
    return 0;
}
