#include <stdio.h>
#include <vector>
using namespace std;

int arr[10001];

int main() {
    int arrLength, targetSum;
    scanf("%d %d", &arrLength, &targetSum);
    for (int i=0; i<arrLength; i++)
        scanf("%d", &arr[i]);

    int st = 0, ed = 0;
    int partialSum = arr[0];
    int numCases = 0;

    for (st=0; st<arrLength; st++) {
        while (partialSum<targetSum && ed<arrLength-1) {
            ed++;
            partialSum += arr[ed];
        }
        if (partialSum==targetSum)
            numCases++;
        partialSum -= arr[st];
    }

    printf("%d", numCases);
    return 0;
}
