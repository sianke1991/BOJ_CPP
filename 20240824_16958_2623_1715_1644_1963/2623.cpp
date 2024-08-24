/*
    직전-직후 관계에 있는 두 가수에 대해
    직전-->직후 간선은 인접 리스트에 더하고,
    각 가수의 진입 차수를 헤아린다.
    진입 차수가 0인 가수를 인접 리스트에서 제외하고,
    새롭게 진입 차수가 0가 되는 가수를 헤아리면
    위상 정렬을 시도할 수 있다. => 그래프에 사이클이 존재하면 위상 정렬에 실패한다.
*/

include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//가수의 수
int numSingers;
//보조 PD의 수
int numAssistants;
//각 보조 PD가 지명한 순서 목록
vector<int> orders[100];
//인접 리스트. adjList[i] := i번 가수 바로 뒤에 지명된 가수 목록
vector<int> adjList[1001];
//진입 차수. indegrees[i] := i번 가수 바로 앞에 지명된 가수 명수
int indegrees[1001];


int main() {
    scanf("%d %d", &numSingers, &numAssistants);
    for (int assistant=0; assistant<numAssistants; assistant++) {
        int sz, elem;
        scanf("%d", &sz);
        vector<int> order;
        for (int i=0; i<sz; i++) {
            scanf("%d", &elem);
            order.push_back(elem);
        }
        orders[assistant] = order;
    } //assistant loop

    //인접 리스트 및 진입 차수 배열 초기화
    for (int assistant=0; assistant<numAssistants; assistant++) {
        int sz = orders[assistant].size();
        for (int i=0, lim=sz-1; i<lim; i++) {
            //직전의 가수 --> 직후의 가수 간선을 인접 리스트에 넣는다. (이 그래프는 방향 그래프이므로 편도만 인접 리스트에 넣는다.)
            adjList[orders[assistant][i]].push_back(orders[assistant][i+1]);
            //직후의 가수의 진입차수를 1 증가시킨다.
            indegrees[orders[assistant][i+1]]++;
        }
    }

    queue<int> q;
    vector<int> result;

    //진입 차수가 0인 가수를 찾아서 큐에 넣는다.
    for (int i=1; i<=numSingers; i++) {
        if (indegrees[i]==0) q.push(i);
    }

    //큐에서 원소를 빼면서 해당 가수 바로 뒤에 있는 가수의 진입차수를 1 뺀다.
    while (!q.empty()) {
        int currentSinger = q.front();
        q.pop();
        result.push_back(currentSinger);
        for (int nextSinger:adjList[currentSinger]) {
            indegrees[nextSinger]--;
            //새롭게 진입 차수가 0이 된 가수를 큐에 넣는다.
            if (indegrees[nextSinger]==0) q.push(nextSinger);
        } //nextSinger loop
    } //while loop

    //위상 정렬이 불가능한 경우-
    if (result.size()!=numSingers) {
        printf("0");
        return 0;
    }
    for (int elem:result)
        printf("%d\n", elem);
    return 0;
}
