#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    int height[N];
    for (int i=0; i<N; i++) {
        cin >> height[i];
    }
    int highest = 0;
    int numBlocks = 0;
    for (int i=N-1; i>=0; i--){
        if (height[i]>highest){
            highest = height[i];
            numBlocks++;
        }
    }
    cout << numBlocks;

    return 0;
}
