#include <iostream>

using namespace std;


int main() {
    int N;
    int numBags=0;
    cin >> N;
    while (N>=0) {
        if (N%5==0) {
            numBags += N/5;
            cout << numBags;
            return 0;
        }
        N -= 3;
        numBags++;
    }
    cout << -1;

    return 0;
}
