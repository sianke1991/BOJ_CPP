#include <stdio.h>
using namespace std;

int main() {
    int numTowers;
    scanf("%d", &numTowers);

    int towerHeights[numTowers];
    for (int i=0; i<numTowers; i++) {
        scanf("%d", &towerHeights[i]);
    }

    int numThrowings = 1;
    for (int i=0; i<numTowers-1; i++) {
        if (towerHeights[i+1]>=towerHeights[i])
            numThrowings++;
    }

    printf("%d", numThrowings);
    return 0;
}
