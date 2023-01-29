#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> elems;
vector<int> twoSums; //elems���� �� ���� ������ ���� ����ѵ� ũ�� ������ ������ ��� (O(N2)���� ���� ����)

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

    //twoSums ����
    for (int elem0:elems) {
        for (int elem1:elems) {
            twoSums.push_back(elem0+elem1);
        }
    }
    sort(twoSums.begin(), twoSums.end()); //�̺�Ž���� ����� �Ǵ� ���ʹ� �������� �����Ѵ�.

    //elems �������� ����
    sort(elems.begin(), elems.end(), descendingOrder);

    //elems���� �� ���� �����Ͽ� �� ���̰� twoSums�� �ִ����� �����Ѵ�.
    //���� �׷��ٸ� elems���� ������ �� �� �� ū ���� �� ���� ������ ��Ÿ�� �� �ִ� ���̴�.
    //�� ���� ������ ��Ÿ�� �� �ִ� ���� �ִ�ġ�� ���� ���̹Ƿ� ������������ �����Ͽ� ���ʴ�� �����Ѵ�.
    //���� for loop�� ����ϹǷ� O(N2)�̰�, �̺�Ž���� ����ϹǷ� O(logN)�� ��������. => O(N2logN) ����
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
