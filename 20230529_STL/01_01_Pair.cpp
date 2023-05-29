#include <bits/stdc++.h>

using namespace std;

int main() {
    pair<int, int> p = {6, 4};
    cout << p.first << ", " << p.second << '\n'; //6, 4
    p.first = 3;
    p.second = 1;
    cout << p.first << ", " << p.second << '\n'; //3, 7

    pair<int, int> pairs[10];
    pairs[0] = {1, 3};
    pairs[1] = {1, 2};
    pairs[2] = {2, 3};
    pairs[3] = {3, 1};
    pairs[4] = {3, 3};
    pairs[5] = {1, 2};
    pairs[6] = {2, 5};
    pairs[7] = {2, 6};
    pairs[8] = {5, 3};
    pairs[9] = {2, 4};

    for (int i=0; i<10; i++) {
        cout << '{' << pairs[i].first << ", " << pairs[i].second << "} "; //{1, 3} {1, 2} {2, 3} {3, 1} {3, 3} {1, 2} {2, 5} {2, 6} {5, 3} {2, 4}
    }
    cout << '\n';

    sort(pairs, pairs+10); //pair 배열을 정렬하면 first를 기준으로 우선 정렬하고, first가 동일한 두 pair는 second를 기준으로 정렬한다.
    for (int i=0; i<10; i++) {
        cout << '{' << pairs[i].first << ", " << pairs[i].second << "} "; //{1, 2} {1, 2} {1, 3} {2, 3} {2, 4} {2, 5} {2, 6} {3, 1} {3, 3} {5, 3}
    }
    cout << '\n';
    sort(pairs, pairs+10, greater<pair<int, int>>()); //greater 함수를 사용하여 내림차순 정렬을 할 수 있다.
    for (int i=0; i<10; i++) {
        cout << '{' << pairs[i].first << ", " << pairs[i].second << "} "; //{5, 3} {3, 3} {3, 1} {2, 6} {2, 5} {2, 4} {2, 3} {1, 3} {1, 2} {1, 2}
    }
    cout << '\n';

    return 0;
}
