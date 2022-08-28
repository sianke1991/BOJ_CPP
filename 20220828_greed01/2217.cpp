#include<iostream>
#include<algorithm>


using namespace std;

int main() {
    int N;
    cin >> N;
    int weight[N];
    for (int i=0; i<N; i++) {
        cin >> weight[i];
    }

    sort(weight, weight+N, greater<int>()); //내림차순
    int maxWeight = 0;
    for (int i=0; i<N; i++) {
        int localWeight = (i+1)*weight[i];
        if (maxWeight < localWeight) maxWeight = localWeight;
    }

    cout << maxWeight;
    return 0;
}
