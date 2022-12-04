#include <iostream>
#include <algorithm>

using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;



int main() {
    int N;
    cin >> N;
    int price[N][3];
    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++) {
            cin >> price[i][j];
        } //j loop
    } //i loop


    int dpArray[N][3]; //�ε��� i ��° ������ ĥ�ϴµ� ���� ����� �ּ�ġ (i ��° ���� j ������ ĥ�Ѵ�.)
    /*
    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            dpArray[i][j] = 0;
        }
    }
    */
    //�ʱⰪ ����
    dpArray[0][R] = price[0][R];
    dpArray[0][G] = price[0][G];
    dpArray[0][B] = price[0][B];

    //��ȭ�� ����
    for (int i=1; i<N; i++) {
        dpArray[i][R] = min(dpArray[i-1][G], dpArray[i-1][B]) + price[i][R];
        dpArray[i][G] = min(dpArray[i-1][R], dpArray[i-1][B]) + price[i][G];
        dpArray[i][B] = min(dpArray[i-1][R], dpArray[i-1][G]) + price[i][B];
    } //i loop

    cout << min(min(dpArray[N-1][R],dpArray[N-1][G]),dpArray[N-1][B]);
    return 0;
}
