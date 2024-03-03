#include <stdio.h>
#include <vector>

// 풀이 과정은 11049번 참조

using namespace std;

int numChapters;
int fileSizes[501][501];
long long dpArray[501][501];
vector<long long> dpVector;

long long min(vector<long long> vec) {
    long long result = vec[0];
    for (long long elem:vec) {
        if (elem<result)
            result = elem;
    }
    return result;
}

void testCases() {
    for (int i=1; i<numChapters; i++) {
        for (int j=1; j<=i; j++) {
            fileSizes[i][j] = fileSizes[i-1][j-1] + fileSizes[i][0];
            dpVector.clear();
            for (int k=0; k<j; k++) {
                dpVector.push_back(dpArray[i-k-1][j-k-1]+dpArray[i][k]);
            } //k loop
            dpArray[i][j] = min(dpVector) + fileSizes[i][j];
        } //j loop
    } //i loop

    printf("%lld\n", dpArray[numChapters-1][numChapters-1]);
}



int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i=0; i<numTestCases; i++) {
        scanf("%d", &numChapters);
        for (int j=0; j<numChapters; j++) {
            scanf("%d", &fileSizes[j][0]);
        } //j loop
        testCases();
    } //i loop

    return 0;
}
