#include <iostream>
#include <algorithm>
#include <cstdlib> //for the function abs

using namespace std;

int main() {
    int N; //������ ����
    cin >> N;
    int solution[N];
    for (int i=0; i<N; i++) {
        cin >> solution[i];
    }
    sort(solution, solution+N);
    int idxLeft = 0;
    int idxRight = N-1;
    int currentVal, optVal=2147483647;
    while (idxRight>idxLeft) {
        currentVal = solution[idxLeft]+solution[idxRight];
        if (abs(currentVal)<abs(optVal)) optVal = currentVal;

        if (currentVal<0) { //��� �հ谡 ������ ��� idxLeft�� ������Ų��.
            idxLeft++;
        } else if (currentVal>0) { //��� �հ谡 ����� ��� idxRight�� ���ҽ�Ų��.
            idxRight--;
        } else { //��� �հ谡 0�� ��� ������ ã�� ���̴�.
            break;
        }
    } //while loop

    cout << optVal;
    return 0;
}
