#include <bits/stdc++.h>

using namespace std;

int main() {
    //���ĵ� �迭�� �ߺ��� �����Ѵ�. ������ �� ���� �������� ������ ���� �д�. ������ ���� ���۵Ǵ� ��ġ�� ��ȯ�Ѵ�.
    int diceResult[] = {4,5,6,4,5,6,5,5,1,1,2,1,1,5,6,1,4,4,1,5,2,4,4,6,4,5,6,3,4,6,4,5,4,5,5,1,4,2,2,1,6,6,2,5,3,3,4,4,3,5,4,4,6,4,1,1,4,5,5,4,1,6,4,6,6,6,5,2,5,5,6,5,1,2,5,6,3,3,4,1,1,6,1,6,6,2,2,1,3,5,4,1,2,1,6,3,2,1,4,5};
    int len = (int)((sizeof diceResult)/(sizeof *diceResult));
    sort(diceResult, diceResult+len);
    for (int dice:diceResult) {
        cout << dice << ' '; //1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    }
    cout << '\n';

    int* uq = unique(diceResult, diceResult+len); //�ߺ��� �����Ѵ�. ������ �� ���� �������� ������ ���� �д�. ������ ���� �����ϴ� ��ġ�� ��ȯ�Ѵ�.
    cout << uq-diceResult << '\n'; //6 (������ ���� ���۵Ǵ� ��ġ)
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

    vector<int>::iterator uqVector = unique(diceResultVector.begin(), diceResultVector.end()); //�ߺ��� �����Ѵ�. ������ �� ���� �������� ������ ���� �д�. ������ ���� �����ϴ� ��ġ�� ��ȯ�Ѵ�.
    cout << uqVector - diceResultVector.begin() << '\n'; //6 (������ ���� ���۵Ǵ� ��ġ)
    for (int dice:diceResultVector) {
        cout << dice << ' '; //1 2 3 4 5 6 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    }
    cout << '\n';
    diceResultVector.erase(uqVector, diceResultVector.end()); //uqVector���� end������ ���Ҹ� �����Ѵ�.
    for (int dice:diceResultVector) {
        cout << dice << ' '; //1 2 3 4 5 6
    }
    cout << '\n';

    return 0;
}
