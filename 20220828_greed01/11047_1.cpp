#include<iostream>
#include<vector>    //
#include<algorithm> //sort �޼���

using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    vector<int> vec;
    int numCoins = 0;
    for (int i=0; i<N; i++)
    {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    //���� ���
    sort(vec.begin(), vec.end(), greater<int>()); //��������
    for (int i=0; i<vec.size(); i++) {
        numCoins += K/vec[i];
        K %= vec[i];
    }

    cout << numCoins;

    return 0;
}
