/*
    ����-���� ���迡 �ִ� �� ������ ����
    ����-->���� ������ ���� ����Ʈ�� ���ϰ�,
    �� ������ ���� ������ ��Ƹ���.
    ���� ������ 0�� ������ ���� ����Ʈ���� �����ϰ�,
    ���Ӱ� ���� ������ 0�� �Ǵ� ������ ��Ƹ���
    ���� ������ �õ��� �� �ִ�. => �׷����� ����Ŭ�� �����ϸ� ���� ���Ŀ� �����Ѵ�.
*/

include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//������ ��
int numSingers;
//���� PD�� ��
int numAssistants;
//�� ���� PD�� ������ ���� ���
vector<int> orders[100];
//���� ����Ʈ. adjList[i] := i�� ���� �ٷ� �ڿ� ����� ���� ���
vector<int> adjList[1001];
//���� ����. indegrees[i] := i�� ���� �ٷ� �տ� ����� ���� ���
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

    //���� ����Ʈ �� ���� ���� �迭 �ʱ�ȭ
    for (int assistant=0; assistant<numAssistants; assistant++) {
        int sz = orders[assistant].size();
        for (int i=0, lim=sz-1; i<lim; i++) {
            //������ ���� --> ������ ���� ������ ���� ����Ʈ�� �ִ´�. (�� �׷����� ���� �׷����̹Ƿ� ���� ���� ����Ʈ�� �ִ´�.)
            adjList[orders[assistant][i]].push_back(orders[assistant][i+1]);
            //������ ������ ���������� 1 ������Ų��.
            indegrees[orders[assistant][i+1]]++;
        }
    }

    queue<int> q;
    vector<int> result;

    //���� ������ 0�� ������ ã�Ƽ� ť�� �ִ´�.
    for (int i=1; i<=numSingers; i++) {
        if (indegrees[i]==0) q.push(i);
    }

    //ť���� ���Ҹ� ���鼭 �ش� ���� �ٷ� �ڿ� �ִ� ������ ���������� 1 ����.
    while (!q.empty()) {
        int currentSinger = q.front();
        q.pop();
        result.push_back(currentSinger);
        for (int nextSinger:adjList[currentSinger]) {
            indegrees[nextSinger]--;
            //���Ӱ� ���� ������ 0�� �� ������ ť�� �ִ´�.
            if (indegrees[nextSinger]==0) q.push(nextSinger);
        } //nextSinger loop
    } //while loop

    //���� ������ �Ұ����� ���-
    if (result.size()!=numSingers) {
        printf("0");
        return 0;
    }
    for (int elem:result)
        printf("%d\n", elem);
    return 0;
}
