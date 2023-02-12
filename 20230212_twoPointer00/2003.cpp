#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M; //N: 수열의 길이, M: 합의 목표치
    cin >> N >> M;
    vector<int> arr;
    for (int i=0; i<N; i++) {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }

    //step0. accumSum(누적) 구성
    vector<int> accumSum;
    accumSum.push_back(arr[0]); //accumSum 0번째에는 arr의 0번째 원소가 그대로 들어가야 한다.
    for (int i=1; i<N; i++) {
        accumSum.push_back(accumSum[i-1]+arr[i]); //accumSum i번째에는 accumSum i-1번째 원소와 arr의 i번째 원소의 합이 들어가야 한다.
    }

    /*
    for (int accum:accumSum) {
        cout << accum << ' ';
    }
    return 0;
    */
    //step1. 두 포인터 적용
    int idxSt=0, idxEd=0;
    int cnt=0, partialSum=0;
    /*
        partialSum(부분합)
        i 번째 원소부터 j 번째 원소까지의 합을 계산하기 위해서는
        accumSum[j] - accumSum[i-1] (where i!=0)
        accumSum[j] (where i==0)
        을 사용한다.
    */
    while (idxSt<N) {
        partialSum = idxSt!=0 ? accumSum[idxEd]-accumSum[idxSt-1] : accumSum[idxEd];
        if (partialSum==M) {
            cnt++;
            idxEd++;
        } else if (partialSum>M) { //부분합이 M보다 큰 경우 부분합을 줄이기 위해 idxSt를 증가시킨다.
            idxSt++;
        } else { //부분합이 M보다 작은 경우 부분합을 늘리기 위해 idxEd를 증가시킨다.
            idxEd++;
            if (idxEd>=N) break; //idxEd가 끝에 도달하면 더 이상 찾는 경우가 없는 것이다.
        }
    } //while loop
    cout << cnt;
    return 0;
}
