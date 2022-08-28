#include <iostream>

using namespace std;


int main() {
    int N;
    cin >> N;

    int distance[N-1];
    int price[N];
    for (int i=0; i<N-1; i++)
        cin >> distance[i];
    for (int i=0; i<N; i++)
        cin >> price[i];

    long long totalPrice = 0;
    long long localMin = 1000000001;

    for (int i=0; i<N-1; i++) {
        if (price[i] < localMin)
            localMin = price[i];
        totalPrice += localMin*distance[i];
    }

    cout << totalPrice;
    return 0;

}
