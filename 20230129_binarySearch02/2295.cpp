#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //자연수의 개수 (집합의 크기)
vector<int> elems; //자연수의 집합

bool descendingOrder(const int a, const int b) {
    return a>b;
}


bool isConstructable(int elem, int idx) {
    int partialSum = 0;
    for (int i=idx; i<elems.size(); i++) {
        partialSum = elems[i];
        for (int j=idx; j<elems.size(); j++) {
            if (partialSum+elems[j]>elem) continue;
            partialSum+=elems[j];
            for (int k=idx; k<elems.size(); k++) {
                if (partialSum+elems[k]==elem) return true;
                else if (partialSum+elems[k]<elem) {
                    partialSum-=elems[j];
                    break;
                }
            } //k loop
        } //j loop
    } //i loop
    return false;
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
    //입력받은 자연수 집합을 내림차순으로 정렬
    sort(elems.begin(), elems.end(), descendingOrder);
    {
        int elem;
        for (int i=0; i<elems.size(); i++) {
            elem = elems[i];
            if (isConstructable(elem, i)) {
                cout << elem;
                break;
            }
        }
    }

    return 0;
}
