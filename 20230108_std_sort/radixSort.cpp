#include<iostream>
#include<vector>

using namespace std;

int n = 15;
int d = 3;  //�ִ� 3 �ڸ� �������� �����Ѵ�.
int p10[3]; //p10[i] = 10^i
int arr[10000001] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240};
vector<int> l[10];

int getDigitAt(int idx, int decimal) {
    return decimal/p10[idx]%10;
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    p10[0] = 1;
    for (int i=1; i<d; i++) {
        p10[i]=10*p10[i-1];
    }
    //cout << "constructing p10 done.\n";
    for (int power=0; power<d; power++) {

        //10�� power�ŵ������� �ڸ��� ���� �з��Ѵ�.
        for (int i=0; i<n; i++) {
            l[getDigitAt(power, arr[i])].push_back(arr[i]);
        }

        //�з��� ����� �ٽ� arr�� �ִ´�.
        int arrIdx=0;
        for (int digit=0; digit<10; digit++) {
            for (int vecIdx=0; vecIdx<l[digit].size(); vecIdx++) {
                arr[arrIdx]=l[digit][vecIdx];
                arrIdx++;
            } //vecIdx loop
        } //digitLoop

        //vector���� �ʱ�ȭ�Ѵ�.
        for (int digit=0; digit<10; digit++) {
            l[digit].clear();
        }
    } //power loop (10�� ���� �ݺ�)

    for (int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
