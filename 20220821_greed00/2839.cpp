#include <iostream>

using namespace std;


int main() {
    int N;
    cin >> N ;
    int numBags = 0;
    while (N%5 !=0 && N>0){
        N-=3;
        numBags++;
    }
    if (N%5==0 && N>=0){
        numBags += (N/5);
        cout << numBags;
    } else {
        cout << -1;
    }

    return 0;
}
