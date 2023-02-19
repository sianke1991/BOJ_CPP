#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M; //N=������ ����, M=�� ������ ������ �ּ�ġ(��ǥ)
    cin >> N >> M;
    vector<int> numbers;
    {
        int num;
        for (int i=0; i<N; i++) {
            cin >> num;
            numbers.push_back(num);
        } //i loop
    }
    sort(numbers.begin(), numbers.end());

    int leftIdx = 0, rightIdx = 0;
    int optVal = 2147483647, currentVal;

    while (leftIdx<N && rightIdx<N) {
        currentVal = numbers[rightIdx]-numbers[leftIdx];
        if (currentVal>=M) { //optVal�� �����ϴ� ����
            optVal = min(optVal, currentVal);
        }

        if (currentVal>M) { //�� ������ ���̰� M���� ū ��� leftIdx�� 1 �������Ѽ� ���̸� ���ҽ��Ѿ� �Ѵ�.
            leftIdx = leftIdx+1;
        } else if (currentVal<M) { //�� ������ ���̰� M���� ���� ��� rightIdx�� 1 �������Ѽ� ���̸� �������Ѿ� �Ѵ�.
            rightIdx = rightIdx+1;
        } else { //�� ������ ���̰� M�� ��� ������ ã�� ���̴�.
            break;
        }
    } //while loop
    cout << optVal;
    return 0;
}
