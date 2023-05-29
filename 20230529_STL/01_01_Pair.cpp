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

    sort(pairs, pairs+10); //pair �迭�� �����ϸ� first�� �������� �켱 �����ϰ�, first�� ������ �� pair�� second�� �������� �����Ѵ�.
    for (int i=0; i<10; i++) {
        cout << '{' << pairs[i].first << ", " << pairs[i].second << "} "; //{1, 2} {1, 2} {1, 3} {2, 3} {2, 4} {2, 5} {2, 6} {3, 1} {3, 3} {5, 3}
    }
    cout << '\n';
    sort(pairs, pairs+10, greater<pair<int, int>>()); //greater �Լ��� ����Ͽ� �������� ������ �� �� �ִ�.
    for (int i=0; i<10; i++) {
        cout << '{' << pairs[i].first << ", " << pairs[i].second << "} "; //{5, 3} {3, 3} {3, 1} {2, 6} {2, 5} {2, 4} {2, 3} {1, 3} {1, 2} {1, 2}
    }
    cout << '\n';

    return 0;
}
