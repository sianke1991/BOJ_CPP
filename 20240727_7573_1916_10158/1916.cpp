#include <bits/stdc++.h>
#define INF 268435455

using namespace std;

//adjList[i]:= i번 도시에서 뻗어나가는 간선 목록 {비용, 도착 도시}
vector<pair<int, int>> adjList[1001];
//costTable[i]:= 출발 도시에서 i번 도시에 도착하는데 필요한 최소 비용
int costTable[1001];

int main() {
    //도시의 개수
    int N;
    //버스의 개수
    int M;

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        adjList[from].push_back({cost, to});
    }

    //출발 도시, 도착 도시
    int start, finish;
    scanf("%d %d", &start, &finish);

    for (int i=0; i<1001; i++) costTable[i] = INF;
    costTable[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();
        //우선순위 큐에서 나온 값 보다 더 효율적인 경우를 구한 경우-
        if (costTable[currentNode]<currentCost)
            continue;
        for (pair<int, int> p:adjList[currentNode]) {
            int nextNode = p.second;
            int nextCost = currentCost+p.first;
            //이번에 구한 경로보다 더 효율적인 경로를 이미 구한 경우-
            if (costTable[nextNode]<=nextCost)
                continue;
            pq.push({nextCost, nextNode});
            costTable[nextNode] = nextCost;
        } //p loop
    } //while loop

    printf("%d", costTable[finish]);
    return 0;
}
