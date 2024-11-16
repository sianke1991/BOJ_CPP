#include <stdio.h>
#include <bits/stdc++.h>

/*
    3
    0 40
    15 30
    5 10
    이렇게 입력된 경우, 각 회의의 시작 시각, 종료 시각을 모은 뒤 오름차순으로 정렬한다.

    0, +    (회의 시작 시각에는 + 마크를 단다.)
    5, +
    10, -   (회의 종료 시각에는 - 마크를 단다.)
    15, +
    30, -
    40, -

    이렇게 정렬한 후, 정렬된 값을 "휩쓸면" 각 시각에 진행중인 회의의 개수를 구할 수 있다.
    회의가 종료되고 바로 그 때에 회의가 시작되는 경우, 한 회의실을 사용할 수 있다.
    회의 시작, 종료 시각을 정렬할 때 시작 시각과 종료 시각이 겹치는 경우,
    종료 시각이 시작 시각보다 먼저 나와야 한다.
*/

using namespace std;
// 배열이 아닌, 정렬된 벡터에 대해 휩쓸기 사용!!
// 각 수치가 차지할 수 있는 범위가 넓은 대신 수치의 개수는 비교적 적다. => 정렬된 벡터 사용
int N;
vector<pair<int, char>> v; // 회의의 시작은 {시작 시각, 'p'}로, 회의의 끝은 {종료 시각, 'm'}로 보관한다.
                            //같은 시각에 위치한 회의의 시작과 회의의 끝이 있다면, 회의의 끝이 먼저 나와야 한다.

void input() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int _begin, _end;
        scanf("%d %d", &_begin, &_end);
        v.push_back({_begin, 'p'});
        v.push_back({_end, 'm'});
    } //i loop
}

int main() {
    input();
    sort(v.begin(), v.end()); //회의의 시작과 끝을 그 시각 기준으로 오름차순 정렬한다.
    int result = 0;
    int currentNumMeetings = 0;
    for (auto meeting:v) {
        //현재 진행 중인 회의의 개수를 갱신한다.
        switch (meeting.second) {
            case 'm': currentNumMeetings--; break;
            case 'p': currentNumMeetings++; break;
        }
        if (result<currentNumMeetings)
            result = currentNumMeetings;
    } //meeting loop
    printf("%d", result);
    return 0;
}
