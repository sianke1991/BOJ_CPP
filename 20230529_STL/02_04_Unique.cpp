#include <bits/stdc++.h>

using namespace std;

int main() {
    //정렬된 배열의 중복을 제거한다. 제거한 뒤 남은 공간에는 쓰레기 값을 둔다. 쓰레기 값이 시작되는 위치를 반환한다.
    int diceResult[] = {4,5,6,4,5,6,5,5,1,1,2,1,1,5,6,1,4,4,1,5,2,4,4,6,4,5,6,3,4,6,4,5,4,5,5,1,4,2,2,1,6,6,2,5,3,3,4,4,3,5,4,4,6,4,1,1,4,5,5,4,1,6,4,6,6,6,5,2,5,5,6,5,1,2,5,6,3,3,4,1,1,6,1,6,6,2,2,1,3,5,4,1,2,1,6,3,2,1,4,5};
    int len = (int)((sizeof diceResult)/(sizeof *diceResult));
    sort(diceResult, diceResult+len);
    for (int dice:diceResult) {
        cout << dice << ' '; //1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    }
    cout << '\n';

    int* uq = unique(diceResult, diceResult+len); //중복을 제거한다. 제거한 뒤 남은 공간에는 쓰레기 값을 둔다. 쓰레기 값이 시작하는 위치를 반환한다.
    cout << uq-diceResult << '\n'; //6 (쓰레기 값이 시작되는 위치)
    for (int dice:diceResult) {
        cout << dice << ' '; //1 2 3 4 5 6 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    }
    cout << '\n';


    vector<int> diceResultVector = {4,5,6,4,5,6,5,5,1,1,2,1,1,5,6,1,4,4,1,5,2,4,4,6,4,5,6,3,4,6,4,5,4,5,5,1,4,2,2,1,6,6,2,5,3,3,4,4,3,5,4,4,6,4,1,1,4,5,5,4,1,6,4,6,6,6,5,2,5,5,6,5,1,2,5,6,3,3,4,1,1,6,1,6,6,2,2,1,3,5,4,1,2,1,6,3,2,1,4,5};
    sort(diceResultVector.begin(), diceResultVector.end());
    for (int dice:diceResultVector) {
        cout << dice << ' '; //1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    }
    cout << '\n';

    vector<int>::iterator uqVector = unique(diceResultVector.begin(), diceResultVector.end()); //중복을 제거한다. 제거한 뒤 남은 공간에는 쓰레기 값을 둔다. 쓰레기 값이 시작하는 위치를 반환한다.
    cout << uqVector - diceResultVector.begin() << '\n'; //6 (쓰레기 값이 시작되는 위치)
    for (int dice:diceResultVector) {
        cout << dice << ' '; //1 2 3 4 5 6 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    }
    cout << '\n';
    diceResultVector.erase(uqVector, diceResultVector.end()); //uqVector부터 end까지의 원소를 제거한다.
    for (int dice:diceResultVector) {
        cout << dice << ' '; //1 2 3 4 5 6
    }
    cout << '\n';

    return 0;
}
