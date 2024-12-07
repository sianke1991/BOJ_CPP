#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

// 목표로 하는 고객 수
int targetNumCusts;
// 도시 개수
int numCities;
// 각 도시에서 지불해야 하는 비용
int costOf[21];
// 각 도시에서 돈을 지불했을 때 예상되는 고객 수
int custsOf[21];

void input() {
    scanf("%d %d", &targetNumCusts, &numCities);
    for (int i=0; i<numCities; i++) {
        scanf("%d %d", &costOf[i], &custsOf[i]);
    } //i loop
}

// 각 비용으로 늘릴 수 있는 회원 수의 최대치
// eg. costTable[10] := 10원을 사용하여 늘릴 수 있는 회원 수의 최대치
int costTable[1000100] = {0};

int main() {
    input();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{비용, 고객 수}
    pq.push({0, 0});
    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int currentCusts = pq.top().second;
        pq.pop();
        if (costTable[currentCost]>currentCusts)
            continue;
        if (currentCusts>=targetNumCusts) //일단 목표치 회원수를 채웠다면 돈을 더 사용해가면서 회원수를 더 늘릴 필요는 없다.
            continue;
        for (int i=0; i<numCities; i++) {
            int nextCost = currentCost + costOf[i];
            int nextCusts = currentCusts + custsOf[i];
            if (costTable[nextCost]<nextCusts) {
                costTable[nextCost] = nextCusts;
                pq.push({nextCost, nextCusts});
            }
        } //i loop
    } //pq loop
    for (int i=0; ; i++) {
        if (costTable[i]>=targetNumCusts) {
            printf("%d", i);
            return 0;
        }
    }
    return -1;
}
