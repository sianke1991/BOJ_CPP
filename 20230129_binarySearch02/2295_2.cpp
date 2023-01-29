#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> elems;
vector<int> twoSums; //elems에서 두 개를 꺼내서 합을 계산한뒤 크기 순으로 정렬한 결과 (O(N2)으로 구성 가능)

bool descendingOrder(const int a, const int b) {
    return a>b;
}

int main() {
    {
        cin >> N;
        int elem;
        for (int i=0; i<N; i++) {
            cin >> elem;
            elems.push_back(elem);
        }
    }

    //twoSums 구성
    for (int elem0:elems) {
        for (int elem1:elems) {
            twoSums.push_back(elem0+elem1);
        }
    }
    sort(twoSums.begin(), twoSums.end()); //이분탐색의 대상이 되는 벡터는 오름차순 정렬한다.

    //elems 내림차순 정렬
    sort(elems.begin(), elems.end(), descendingOrder);

    //elems에서 두 수를 선택하여 그 차이가 twoSums에 있는지를 조사한다.
    //만약 그렇다면 elems에서 선택한 두 수 중 큰 수는 세 수의 합으로 나타낼 수 있는 것이다.
    //세 수의 합으로 나타낼 수 있는 수의 최대치를 구할 것이므로 내림차순으로 정렬하여 차례대로 조사한다.
    //이중 for loop를 사용하므로 O(N2)이고, 이분탐색을 사용하므로 O(logN)이 곱해진다. => O(N2logN) 문제
    for (int elem0:elems) {
        for (int elem1:elems) {
            if (binary_search(twoSums.begin(), twoSums.end(), elem0-elem1)) {
                cout << elem0;
                return 0;
            }
        }
    }

    return 1;
}
