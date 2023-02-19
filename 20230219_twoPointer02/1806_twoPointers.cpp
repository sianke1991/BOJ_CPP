#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, S; //N: ������ ����, S: �κ��� ��ǥġ (�κ����� S �̻��� �Ǿ�� �Ѵ�.)
    cin >> N >> S;
    vector<int> numbers; //���� N ¥�� ����
    {
        int number;
        for (int i=0; i<N; i++) {
            cin >> number;
            numbers.push_back(number);
        } //i loop
    }

    int leftIdx = 0, rightIdx = 0, currentPartialSum = numbers[0], currentLength = 1;
    int optLength = 2147483647;

    while (leftIdx<N) {
        //cout << leftIdx << ", " << rightIdx << ", " << currentPartialSum << "\n";
        if (currentPartialSum>=S) { //optLength�� �����ϴ� ����
            optLength = min(optLength, currentLength);
        }

        if (currentPartialSum>=S) { //���� �κ����� S���� ū ��� leftIdx�� 1 �������Ѽ� ���� ������ ���̸� �ٿ��ش�.
            currentPartialSum-=numbers[leftIdx];
            leftIdx++;
            currentLength--;
        } else if (currentPartialSum<S) { //���� �κ����� S���� ���� ��� rightIdx�� 1 �������Ѽ� �κ����� ���������ش�.
            if (rightIdx>=N-1) break;
            rightIdx++;
            currentPartialSum+=numbers[rightIdx];
            currentLength++;

        }
        /*
            ���� �κ����� ��Ȯ�ϰ� S ���� ���� ������ ã�Ҵٰ� �� �� ���� ������
            �� ��� break ó���� ���� �ʴ´�.
        */
    } //while loop
    if (optLength<=N) cout << optLength;
    else cout << 0;
    return 0;
}
