#include <bits/stdc++.h>

using namespace std;

/*
학생들의 키를 비교할 때 전후관계는 잘 정의되므로 사이클이 존재하는 경우는 고려하지 않는다.
예를 들어 A가 B보다 큰데, B가 A보다 큰 경우는 고려하지 않는다.
*/
vector<int> adjList[32001];
int indegree[32001];
queue<int> q;
vector<int> topoSort;


int main() {
    int numStudents, numEdges;
    cin >> numStudents >> numEdges;
    for (int i=0; i<numEdges; i++) {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        indegree[to]++;
    }

    for (int i=1; i<=numStudents; i++) {
        if (indegree[i]==0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int currentStudent = q.front();
        topoSort.push_back(currentStudent);
        q.pop();
        for (int nextStudent:adjList[currentStudent]) {
            indegree[nextStudent]--;
            if (indegree[nextStudent]==0) {
                q.push(nextStudent);
            }
        }
    }

    for (int student:topoSort) {
        cout << student << ' ';
    }
    return 0;
}
