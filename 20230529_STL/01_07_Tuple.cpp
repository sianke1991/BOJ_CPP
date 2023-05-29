#include <bits/stdc++.h>

using namespace std;

int main() {
    tuple<int, int, int> t = {6, 5, 2};
    cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '\n'; //6, 5, 2

    t = {1, get<1>(t), get<2>(t)};
    cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '\n'; //1, 5, 2

    tuple<int, int, int> tuples[10];
    tuples[0] = {5, 2, 5};
    tuples[1] = {2, 4, 6};
    tuples[2] = {5, 4, 4};
    tuples[3] = {4, 6, 6};
    tuples[4] = {3, 6, 3};
    tuples[5] = {1, 3, 5};
    tuples[6] = {3, 5, 1};
    tuples[7] = {2, 6, 3};
    tuples[8] = {4, 6, 3};
    tuples[9] = {2, 1, 6};

    for (tuple<int, int, int> tt:tuples) {
        cout << '{' << get<0>(tt) << ", " << get<1>(tt) << ", " << get<2>(tt) << "} "; //{5, 2, 5} {2, 4, 6} {5, 4, 4} {4, 6, 6} {3, 6, 3} {1, 3, 5} {3, 5, 1} {2, 6, 3} {4, 6, 3} {2, 1, 6}
    }
    cout << '\n';

    sort(tuples, tuples+10); //tuple 배열 정렬
    for (tuple<int, int, int> tt:tuples) {
        cout << '{' << get<0>(tt) << ", " << get<1>(tt) << ", " << get<2>(tt) << "} "; //{1, 3, 5} {2, 1, 6} {2, 4, 6} {2, 6, 3} {3, 5, 1} {3, 6, 3} {4, 6, 3} {4, 6, 6} {5, 2, 5} {5, 4, 4}
    }
    cout << '\n';

    sort(tuples, tuples+10, greater<tuple<int, int, int>>()); //tuple 배열 내림차순 정렬
    for (tuple<int, int, int> tt:tuples) {
        cout << '{' << get<0>(tt) << ", " << get<1>(tt) << ", " << get<2>(tt) << "} "; //{5, 4, 4} {5, 2, 5} {4, 6, 6} {4, 6, 3} {3, 6, 3} {3, 5, 1} {2, 6, 3} {2, 4, 6} {2, 1, 6} {1, 3, 5}
    }
    cout << '\n';

    return 0;
}
