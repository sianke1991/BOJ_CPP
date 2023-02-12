#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M; //N: ������ ����, M: ���� ��ǥġ
    cin >> N >> M;
    vector<int> arr;
    for (int i=0; i<N; i++) {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }

    //step0. accumSum(����) ����
    vector<int> accumSum;
    accumSum.push_back(arr[0]); //accumSum 0��°���� arr�� 0��° ���Ұ� �״�� ���� �Ѵ�.
    for (int i=1; i<N; i++) {
        accumSum.push_back(accumSum[i-1]+arr[i]); //accumSum i��°���� accumSum i-1��° ���ҿ� arr�� i��° ������ ���� ���� �Ѵ�.
    }

    /*
    for (int accum:accumSum) {
        cout << accum << ' ';
    }
    return 0;
    */
    //step1. �� ������ ����
    int idxSt=0, idxEd=0;
    int cnt=0, partialSum=0;
    /*
        partialSum(�κ���)
        i ��° ���Һ��� j ��° ���ұ����� ���� ����ϱ� ���ؼ���
        accumSum[j] - accumSum[i-1] (where i!=0)
        accumSum[j] (where i==0)
        �� ����Ѵ�.
    */
    while (idxSt<N) {
        partialSum = idxSt!=0 ? accumSum[idxEd]-accumSum[idxSt-1] : accumSum[idxEd];
        if (partialSum==M) {
            cnt++;
            idxEd++;
        } else if (partialSum>M) { //�κ����� M���� ū ��� �κ����� ���̱� ���� idxSt�� ������Ų��.
            idxSt++;
        } else { //�κ����� M���� ���� ��� �κ����� �ø��� ���� idxEd�� ������Ų��.
            idxEd++;
            if (idxEd>=N) break; //idxEd�� ���� �����ϸ� �� �̻� ã�� ��찡 ���� ���̴�.
        }
    } //while loop
    cout << cnt;
    return 0;
}
