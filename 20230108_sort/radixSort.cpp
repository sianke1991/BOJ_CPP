#include<iostream>
#include<vector>

using namespace std;

int n = 15;
int d = 3;  //최대 3 자리 정수까지 정렬한다.
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

        //10의 power거듭제곱의 자리에 따라 분류한다.
        for (int i=0; i<n; i++) {
            l[getDigitAt(power, arr[i])].push_back(arr[i]);
        }

        //분류한 결과를 다시 arr에 넣는다.
        int arrIdx=0;
        for (int digit=0; digit<10; digit++) {
            for (int vecIdx=0; vecIdx<l[digit].size(); vecIdx++) {
                arr[arrIdx]=l[digit][vecIdx];
                arrIdx++;
            } //vecIdx loop
        } //digitLoop

        //vector들을 초기화한다.
        for (int digit=0; digit<10; digit++) {
            l[digit].clear();
        }
    } //power loop (10의 지수 반복)

    for (int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
