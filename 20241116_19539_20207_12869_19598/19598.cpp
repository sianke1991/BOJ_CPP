#include <stdio.h>
#include <bits/stdc++.h>

/*
    3
    0 40
    15 30
    5 10
    �̷��� �Էµ� ���, �� ȸ���� ���� �ð�, ���� �ð��� ���� �� ������������ �����Ѵ�.

    0, +    (ȸ�� ���� �ð����� + ��ũ�� �ܴ�.)
    5, +
    10, -   (ȸ�� ���� �ð����� - ��ũ�� �ܴ�.)
    15, +
    30, -
    40, -

    �̷��� ������ ��, ���ĵ� ���� "�۾���" �� �ð��� �������� ȸ���� ������ ���� �� �ִ�.
    ȸ�ǰ� ����ǰ� �ٷ� �� ���� ȸ�ǰ� ���۵Ǵ� ���, �� ȸ�ǽ��� ����� �� �ִ�.
    ȸ�� ����, ���� �ð��� ������ �� ���� �ð��� ���� �ð��� ��ġ�� ���,
    ���� �ð��� ���� �ð����� ���� ���;� �Ѵ�.
*/

using namespace std;
// �迭�� �ƴ�, ���ĵ� ���Ϳ� ���� �۾��� ���!!
// �� ��ġ�� ������ �� �ִ� ������ ���� ��� ��ġ�� ������ ���� ����. => ���ĵ� ���� ���
int N;
vector<pair<int, char>> v; // ȸ���� ������ {���� �ð�, 'p'}��, ȸ���� ���� {���� �ð�, 'm'}�� �����Ѵ�.
                            //���� �ð��� ��ġ�� ȸ���� ���۰� ȸ���� ���� �ִٸ�, ȸ���� ���� ���� ���;� �Ѵ�.

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
    sort(v.begin(), v.end()); //ȸ���� ���۰� ���� �� �ð� �������� �������� �����Ѵ�.
    int result = 0;
    int currentNumMeetings = 0;
    for (auto meeting:v) {
        //���� ���� ���� ȸ���� ������ �����Ѵ�.
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
