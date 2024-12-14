#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int numLines;
vector<pair<int, char>> lineEnds;

int main() {
    scanf("%d", &numLines);
    for (int i=0; i<numLines; i++) {
        int _start, _end;
        scanf("%d %d", &_start, &_end);
        lineEnds.push_back({_start, 's'}); //시작 위치 정보
        lineEnds.push_back({_end, 'e'}); //종료 위치 정보
    } //i loop
    sort(lineEnds.begin(), lineEnds.end());
    int dupLevel = 0; //겹쳐진 선분 개수
    int maxDupLevel = 0; //겹쳐진 선분 개수 최대치
    for (auto lineEnd:lineEnds) {
        if (lineEnd.second=='s') dupLevel++;       // 해당 지점에서 하나의 선분이 시작되었다면 겹쳐진 선분 개수가 1 증가한다.
        else                     dupLevel--;       // 반대로 하나의 선분이 종료되었다면 겹쳐진 선분 개수가 1 감소한다.
        if (dupLevel>maxDupLevel) maxDupLevel = dupLevel;
    }
    printf("%d", maxDupLevel);
    return 0;
}
