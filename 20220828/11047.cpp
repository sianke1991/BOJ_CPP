#include<iostream>

using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    int coinTypes[N];
    int numCoins = 0;
    for (int i=0; i<N; i++)
    {
        cin >> coinTypes[i];
    }
    for (int i=N-1; i>=0; i--){
        numCoins += K/coinTypes[i];
        K %= coinTypes[i];
    }

    cout << numCoins;

    return 0;
}
