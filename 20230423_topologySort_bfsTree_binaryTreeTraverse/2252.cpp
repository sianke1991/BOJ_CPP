#include <bits/stdc++.h>

using namespace std;

/*
�л����� Ű�� ���� �� ���İ���� �� ���ǵǹǷ� ����Ŭ�� �����ϴ� ���� ������� �ʴ´�.
���� ��� A�� B���� ū��, B�� A���� ū ���� ������� �ʴ´�.
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
