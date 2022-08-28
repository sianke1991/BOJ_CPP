#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int height[N];
    for (int i=0; i<N; i++) {
        cin >> height[i];
    }

    int localHighest = 0;
    int localMaxHit=0;


    for (int i=0; i<N; i++) {
        if (height[i]>localHighest) {
            localHighest = height[i];
            int localNumHits= 0 ;
            for (int j=i+1; j<N; j++) {
                if (height[j]<localHighest){
                    localNumHits++;
                } else if (height[j]>localHighest) {
                    break;
                }
            } //j loop
            if (localMaxHit < localNumHits)
                localMaxHit = localNumHits;
        }
    }
    cout << localMaxHit;
    return 0;

}
