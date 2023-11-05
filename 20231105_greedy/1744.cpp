#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int numElems;
    cin >> numElems;
    vector<int> elemsGreaterThanOne;
    int numOnes=0;
    vector<int> elemsLessThanOne;

    int elem;
    for (int i=0; i<numElems; i++) {
        cin >> elem;
        if (elem>1) {
            elemsGreaterThanOne.push_back(elem);
        } else if (elem<1) {
            elemsLessThanOne.push_back(elem);
        } else {
            numOnes++;
        }
    } //i loop

    sort(elemsGreaterThanOne.begin(), elemsGreaterThanOne.end(), greater<int>());
    sort(elemsLessThanOne.begin(), elemsLessThanOne.end());

    /*
    for (int e:elemsGreaterThanOne) {
        cout << e << ' ';
    }
    cout << '\n';
    for (int e:elemsLessThanOne) {
        cout << e << ' ';
    }
    cout << '\n';
    */
    int answer = numOnes;

    //1���� ū ���Ҵ� ū ���Һ��� �� ���� ¦�� ��� ���� �� ���Ѵ�.
    if (elemsGreaterThanOne.size()%2==1) {
        elemsGreaterThanOne.push_back(1);
    }
    for (int i=0; i<elemsGreaterThanOne.size(); i+=2) {
        answer+=elemsGreaterThanOne[i]*elemsGreaterThanOne[i+1];
    }

    //1���� ���� ���Ҵ� ���� ���Һ��� �� ���� ¦�� ��� ���� �� ���Ѵ�.
    //�� ������ ���ϸ� ����� �Ǵµ�, �� �������� ����ġ�� Ŭ ���� ���� ����� Ŀ����.
    if (elemsLessThanOne.size()%2==1) {
        elemsLessThanOne.push_back(1);
    }
    for (int i=0; i<elemsLessThanOne.size(); i+=2) {
        answer+=elemsLessThanOne[i]*elemsLessThanOne[i+1];
    }


    cout << answer;
    return 0;
}
