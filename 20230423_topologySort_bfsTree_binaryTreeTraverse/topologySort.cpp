#include <bits/stdc++.h>

using namespace std;

vector<char> adjList[72];
queue<char> q; //indegree가 0인 노드 대기줄
int indegree[72];
vector<char> topoSort;

void test() {
    //연결리스트, indegree 배열 구성
    adjList['A'].push_back('B'); indegree['B']++;
    adjList['C'].push_back('B'); indegree['B']++;
    adjList['C'].push_back('D'); indegree['D']++;
    adjList['D'].push_back('B'); indegree['B']++;
    adjList['D'].push_back('E'); indegree['E']++;
    adjList['E'].push_back('F'); indegree['F']++;
    adjList['G'].push_back('E'); indegree['E']++;
    //indegree가 0인 노드 대기줄 구성
    for (char ch='A'; ch<='G'; ch++) {
        if (indegree[ch]==0) {
            q.push(ch);
        }
    }
    //indegree가 0인 노드 대기줄이 빌 때까지 반복
    while (!q.empty()) {
        char currentNode = q.front();
        topoSort.push_back(currentNode);
        q.pop();
        for (char nextNode:adjList[currentNode]) {
            indegree[nextNode]--; //해당 노드에 연결된 노드의 indegree를 1만큼 감소시키고-
            if (indegree[nextNode]==0) { //그 감소의 결과가 0인 경우-
                q.push(nextNode); //indegree가 0인 노드 대기줄에 추가한다.
            }
        }
    }
}

/*
위상정렬(Topology Sort): 방향 그래프에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열하는 정렬
DAG(Directed Acyclic Graph): cycle이 존재하지 않는 방향 그래프, 위상정렬은 DAG에서만 수행 가능하다.
매 단계마다 indegree가 0인 노드를 방문하되, 방문한 노드와 해당 노드에서 뻗어나가는 간선을 그래프에서 지워나간다. => 이 과정을 그래프에서 indegree가 0인 노드가 없어질 때 까지 반복
구현의 편의를 위한 성질
1. 정점과 간선을 실제로 지울 필요 없이 미리 indegree의 값을 저장해 두었다가 매번 뻗어나가는 정점들의 indegree 값만 1 감소시켜도 과정을 수행할 수 있다.
2. indegree가 0인 정점을 구하개 위해 매번 모든 정점을 다 확인하는 대신 목록을 따로 저장하고 있다가 직전에 제거한 정점에서 연결된 정점들만 추가한다.
=> indegree를 1 감소시킨 후 해당 노드의 indegree가 0이 되면 특정 queue에 push한다.

위상정렬 알고리즘
1. 맨 처음 모든 간선을 읽으며 indegree 테이블을 채운다.
2. indegree가 0인 정점들을 모두 queue 에 넣는다.
3. queue에서 정점을 꺼내어 위상 정렬 결과에 추가한다.
4. 해당 정점으로부터 연결된 모든 정점의 indegree의 값을 1 감소시킨다. 이 때 indegree가 0가 되었다면 그 정점을 큐에 넣는다.
5. queue가 빌 때 까지 3, 4 번 과정을 반복한다.
*. 정렬의 결과 모든 노드를 전부 거치지 못하면 해당 방향 그래프는 cycle이 존재하는 것이다.
*. 큐에는 각 노드가 최대 한 번씩 들어가고, indegree 감소는 각 간선마다 최대 한 번씩 이루어진다. 위상정렬의 시간복잡도는 O(V+E)가 된다.
*/
int main() {
    test();
    for (char ch:topoSort) {
        cout << ch;
    }
    return 0;
}
