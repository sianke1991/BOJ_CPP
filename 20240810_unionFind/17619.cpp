#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/*
union-find ����� ����, �����Ͽ� ������ �� �ִ� �볪�� ��ȣ�� �ϳ��� �������� ���´�.
���� �볪�� a���� �볪�� b�� ������ �������� ���θ� ��ȸ�ϴ� ����
a�� b�� �ϳ��� ���տ� ���ϴ��� ���θ� ��ȸ�ϴ� ������ ��ü�� �� �ִ�.

�Է¹��� �볪���� �����ϵ�, �� ���� ��ġ�� �������� �������� �����Ѵ�.
���� ���ʿ� �ִ� �볪������ �����Ͽ� ���������� �����ϸ鼭
�̹� �볪���� [�ٷ� ���� �볪���� ���� �׷�]�� ���ϴ��� ���θ� �����Ѵ�.
��, �ٷ� ���� �볪������ �̹� �볪���� ������ �������� ���θ� �����ϴ� ���� �ƴ�,
[�ٷ� ���� �볪���� ���� �׷� �� ���� ���������� ������� �볪��]���� �̹� �볪���� ������ �������� ���θ� �����ؾ� �Ѵ�.
=> ���� ���� ����
*/

struct Log {
    //������ ���� ��ġ
    int _begin;
    //������ �� ��ġ
    int _end;
    //���� ��ġ
    int _vertical;
    //��ȣ
    int _index;
};

bool cmp(Log log0, Log log1) {
    return log0._begin<log1._begin;
}

int parentOf[100001];

int rootOf(int index) {
    if (parentOf[index]!=index) {
        //printf("parentOf: %d %d %d %d\n", parentOf[1], parentOf[2], parentOf[3], parentOf[4]);
        //printf("index: %d, parentOfIndex: %d\n", index, parentOf[index]);
        parentOf[index] = rootOf(parentOf[index]);
    }
    return parentOf[index];
}

int checkSameGroup(int index0, int index1) {
    int rootOfIndex0 = rootOf(index0);
    int rootOfIndex1 = rootOf(index1);
    return rootOfIndex0==rootOfIndex1;
}

void unionize(int index0, int index1) {
    int rootOfIndex0 = rootOf(index0);
    int rootOfIndex1 = rootOf(index1);
    if (rootOfIndex0<rootOfIndex1) {
        parentOf[rootOfIndex1] = rootOfIndex0;
    } else {
        parentOf[rootOfIndex0] = rootOfIndex1;
    }
}

int main() {
    int numLogs, numQueries;
    scanf("%d %d", &numLogs, &numQueries);
    vector<Log> logs;
    for (int i=1; i<=numLogs; i++) {
        int _begin, _end, _vertical;
        scanf("%d %d %d", &_begin, &_end, &_vertical);
        logs.push_back({_begin, _end, _vertical, i});
    }
    vector<pair<int, int>> queries;
    for (int i=0; i<numQueries; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        queries.push_back({from, to});
    }
    sort(logs.begin(), logs.end(), cmp);
    for (int i=1; i<=numLogs; i++) {
        parentOf[i] = i;
    }
    Log log = logs[0];
    for (int i=0, lim=numLogs-1; i<lim; i++) {
        if (log._end>=logs[i+1]._begin) {
            unionize(log._index, logs[i+1]._index);
            if (log._end<logs[i+1]._end) log = logs[i+1];
        } else {
            log = logs[i+1];
        }
    } //i loop
    vector<int> results;
    for (pair<int, int> query:queries) {
        results.push_back(checkSameGroup(query.first, query.second));
    }
    for (int result:results) {
        printf("%d\n", result);
    }
    return 0;
}
