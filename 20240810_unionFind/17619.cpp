#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/*
union-find 방법을 응용, 점프하여 도달할 수 있는 통나무 번호를 하나의 집합으로 묶는다.
이후 통나무 a에서 통나무 b로 점프가 가능한지 여부를 조회하는 것은
a와 b가 하나의 집합에 속하는지 여부를 조회하는 것으로 대체될 수 있다.

입력받은 통나무를 정렬하되, 그 시작 위치를 기준으로 오름차순 정렬한다.
가장 왼쪽에 있는 통나무에서 시작하여 오른쪽으로 진행하면서
이번 통나무가 [바로 직전 통나무가 속한 그룹]에 속하는지 여부를 조사한다.
단, 바로 직전 통나무에서 이번 통나무로 점프가 가능한지 여부를 조사하는 것이 아닌,
[바로 직전 통나무가 속한 그룹 내 가장 오른쪽으로 뻗어나오는 통나무]에서 이번 통나무로 점프가 가능한지 여부를 조사해야 한다.
=> 별도 파일 참조
*/

struct Log {
    //수평의 시작 위치
    int _begin;
    //수평의 끝 위치
    int _end;
    //수직 위치
    int _vertical;
    //번호
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
