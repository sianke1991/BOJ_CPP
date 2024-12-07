#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// 구멍 개수
int numHoles;
// 다리 길이
long long bridgeLength;
long long initPoint = 1000000001LL;
// 각 구멍의 {끝점, 시작점} 정보를 보관하는 map
map<long long, long long> holeMap;

void input() {
    scanf("%d %lld", &numHoles, &bridgeLength);
    for (int i=0; i<numHoles; i++) {
        long long b, f;
        scanf("%lld %lld", &b, &f);
        if (b<initPoint)
            initPoint = b;
        holeMap[f] = b;
    } //i loop
}

int main() {
    input();
    // 다리 개수
    int numBridges = 0;
    // 현재 위치
    long long currentPosition = initPoint;
    while (true) {
        map<long long, long long>::iterator it = holeMap.upper_bound(currentPosition);
        if (it==holeMap.end()) {
            break;
        }
        long long holeBegin = (*it).second;
        long long holeEnd   = (*it).first;
        if (currentPosition<holeBegin)       // 바로 직전에 놓은 다리의 끝 보다 다음 웅덩이가 오른쪽에 있다면, 새로운 다리의 시작은 간격을 벌릴 수 있다.
            currentPosition = holeBegin;
        //printf("currentPosition: %lld\n", currentPosition);
        int addedBridges = ((holeEnd-currentPosition)+bridgeLength-1)/bridgeLength;
        numBridges += addedBridges;
        currentPosition += addedBridges*bridgeLength;
    } //while loop
    printf("%d", numBridges);
    return 0;
}
