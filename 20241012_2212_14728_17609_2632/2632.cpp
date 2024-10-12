#include <stdio.h>
#include <vector>

using namespace std;

int targetSize;
int numASlices;
int numBSlices;
vector<int> sliceASizes;
vector<int> sliceBSizes;
long long result = 0LL;
//피자 A의 조각을 사용하여 만들 수 있는 경우의 수
//sliceAMap[10] := 피자 A의 조각을 사용하여 크기 10을 만들 수 있는 경우의 수
long long sliceAMap[2000001] = {1LL};
//sliceBMap[10] := 피자 B의 조각을 사용하여 크기 10을 만들 수 있는 경우의 수
long long sliceBMap[2000001] = {1LL};

void input() {
    scanf("%d", &targetSize);
    scanf("%d %d", &numASlices, &numBSlices);
    for (int i=0; i<numASlices; i++) {
        int sz;
        scanf("%d", &sz);
        sliceASizes.push_back(sz);
    }
    for (int i=0; i<numBSlices; i++) {
        int sz;
        scanf("%d", &sz);
        sliceBSizes.push_back(sz);
    }
}

void constructMaps() {
    int sumA = 0, sumB = 0;
    for (auto sz:sliceASizes) sumA += sz;
    for (auto sz:sliceBSizes) sumB += sz;
    sliceAMap[sumA] = 1LL;
    sliceBMap[sumB] = 1LL;

    for (int left=0, lim=numASlices-1; left<lim; left++) {
        int localASum = 0;
        for (int right=left; right<lim; right++) {
            localASum += sliceASizes[right];
            sliceAMap[localASum]++;
            sliceAMap[sumA-localASum]++;
        } //right loop
    } //left loop

    for (int left=0, lim=numBSlices-1; left<lim; left++) {
        int localBSum = 0;
        for (int right=left; right<lim; right++) {
            localBSum += sliceBSizes[right];
            sliceBMap[localBSum]++;
            sliceBMap[sumB-localBSum]++;
        } //right loop
    } //left loop
}

int main() {
    input();
    constructMaps();
    for (int a=0; a<=targetSize; a++) {
        int b=targetSize-a;
        result += sliceAMap[a]*sliceBMap[b];
    }
    printf("%lld", result);
    return 0;
}
