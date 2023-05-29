#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v0;
    v0.push_back(6);
    v0.push_back(2);
    v0.push_back(3);
    v0.push_back(4);
    v0.push_back(4);
    v0.push_back(3);
    v0.push_back(6);
    v0.push_back(1);

    cout << v0.empty() << '\n'; //0
    cout << v0.size() << '\n'; //7
    cout << *v0.begin() << '\n'; //6
    cout << *(v0.end()-1) << '\n'; //1 //v0.end()는 vector의 마지막 원소 다음 주소를 가리킨다.

    for (int i=0; i<v0.size(); i++) {
        cout << v0[i] << ' '; //6 2 3 4 4 3 6 1
    }
    cout << '\n';

    for (int elem:v0) { //range-based for loop
        cout << elem << ' '; //6 2 3 4 4 3 6 1
    }
    cout << '\n';

    sort(v0.begin(), v0.end()); //vector 내 원소 정렬
    for (int elem:v0) {
        cout << elem << ' '; //1 2 3 3 4 4 6 6
    }
    cout << '\n';

    sort(v0.begin(), v0.end(), greater<int>()); //vector 내 원소 내림차순 정렬
    for (int elem:v0) {
        cout << elem << ' '; //6 6 4 4 3 3 2 1
    }
    cout << '\n';

    vector<pair<int, int>> v1;
    v1.push_back({1, 2});
    v1.push_back({1, 3});
    v1.push_back({2, 3});
    v1.push_back({3, 1});
    v1.push_back({3, 3});
    v1.push_back({1, 2});
    v1.push_back({2, 5});
    v1.push_back({2, 6});
    v1.push_back({5, 3});
    v1.push_back({2, 4});

    for (pair<int, int> p:v1) {
        cout << '{' << p.first << ", " << p.second << "} "; //{1, 2} {1, 3} {2, 3} {3, 1} {3, 3} {1, 2} {2, 5} {2, 6} {5, 3} {2, 4}
    }
    cout << '\n';

    sort(v1.begin(), v1.end());
    for (pair<int, int> p:v1) {
        cout << '{' << p.first << ", " << p.second << "} "; //{1, 2} {1, 2} {1, 3} {2, 3} {2, 4} {2, 5} {2, 6} {3, 1} {3, 3} {5, 3}
    }
    cout << '\n';

    sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    for (pair<int, int> p:v1) {
        cout << '{' << p.first << ", " << p.second << "} "; //{5, 3} {3, 3} {3, 1} {2, 6} {2, 5} {2, 4} {2, 3} {1, 3} {1, 2} {1, 2}
    }
    cout << '\n';

    vector<int> v2 = {1, 3, 5}; //vector를 선언할 때 가지고 있을 원소들을 지정할 수 있다.
    v2.push_back(4);
    for (int elem:v2) {
        cout << elem << ' '; //1 3 5 4
    }
    cout << '\n';

    v2[0] = 2;
    for (int elem:v2) {
        cout << elem << ' '; //2 3 5 4
    }
    cout << '\n';

    return 0;
}
