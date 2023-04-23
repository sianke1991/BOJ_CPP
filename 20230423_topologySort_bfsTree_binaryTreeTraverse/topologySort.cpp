#include <bits/stdc++.h>

using namespace std;

vector<char> adjList[72];
queue<char> q; //indegree�� 0�� ��� �����
int indegree[72];
vector<char> topoSort;

void test() {
    //���Ḯ��Ʈ, indegree �迭 ����
    adjList['A'].push_back('B'); indegree['B']++;
    adjList['C'].push_back('B'); indegree['B']++;
    adjList['C'].push_back('D'); indegree['D']++;
    adjList['D'].push_back('B'); indegree['B']++;
    adjList['D'].push_back('E'); indegree['E']++;
    adjList['E'].push_back('F'); indegree['F']++;
    adjList['G'].push_back('E'); indegree['E']++;
    //indegree�� 0�� ��� ����� ����
    for (char ch='A'; ch<='G'; ch++) {
        if (indegree[ch]==0) {
            q.push(ch);
        }
    }
    //indegree�� 0�� ��� ������� �� ������ �ݺ�
    while (!q.empty()) {
        char currentNode = q.front();
        topoSort.push_back(currentNode);
        q.pop();
        for (char nextNode:adjList[currentNode]) {
            indegree[nextNode]--; //�ش� ��忡 ����� ����� indegree�� 1��ŭ ���ҽ�Ű��-
            if (indegree[nextNode]==0) { //�� ������ ����� 0�� ���-
                q.push(nextNode); //indegree�� 0�� ��� ����ٿ� �߰��Ѵ�.
            }
        }
    }
}

/*
��������(Topology Sort): ���� �׷������� �������� �־��� ���� �� ���İ��踦 �������� �ʵ��� �����ϴ� ����
DAG(Directed Acyclic Graph): cycle�� �������� �ʴ� ���� �׷���, ���������� DAG������ ���� �����ϴ�.
�� �ܰ踶�� indegree�� 0�� ��带 �湮�ϵ�, �湮�� ���� �ش� ��忡�� ������� ������ �׷������� ����������. => �� ������ �׷������� indegree�� 0�� ��尡 ������ �� ���� �ݺ�
������ ���Ǹ� ���� ����
1. ������ ������ ������ ���� �ʿ� ���� �̸� indegree�� ���� ������ �ξ��ٰ� �Ź� ������� �������� indegree ���� 1 ���ҽ��ѵ� ������ ������ �� �ִ�.
2. indegree�� 0�� ������ ���ϰ� ���� �Ź� ��� ������ �� Ȯ���ϴ� ��� ����� ���� �����ϰ� �ִٰ� ������ ������ �������� ����� �����鸸 �߰��Ѵ�.
=> indegree�� 1 ���ҽ�Ų �� �ش� ����� indegree�� 0�� �Ǹ� Ư�� queue�� push�Ѵ�.

�������� �˰���
1. �� ó�� ��� ������ ������ indegree ���̺��� ä���.
2. indegree�� 0�� �������� ��� queue �� �ִ´�.
3. queue���� ������ ������ ���� ���� ����� �߰��Ѵ�.
4. �ش� �������κ��� ����� ��� ������ indegree�� ���� 1 ���ҽ�Ų��. �� �� indegree�� 0�� �Ǿ��ٸ� �� ������ ť�� �ִ´�.
5. queue�� �� �� ���� 3, 4 �� ������ �ݺ��Ѵ�.
*. ������ ��� ��� ��带 ���� ��ġ�� ���ϸ� �ش� ���� �׷����� cycle�� �����ϴ� ���̴�.
*. ť���� �� ��尡 �ִ� �� ���� ����, indegree ���Ҵ� �� �������� �ִ� �� ���� �̷������. ���������� �ð����⵵�� O(V+E)�� �ȴ�.
*/
int main() {
    test();
    for (char ch:topoSort) {
        cout << ch;
    }
    return 0;
}
