#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//닭의 시간을 오름차순 정렬할 때-
//소를 도와줄 수 있는 닭 중 처음 매칭되는 닭을 선택한다.

int numChickens;
int numCows;
vector<int> chickenTimes;
vector<pair<int, int>> cowTimes;

void input() {
    scanf("%d %d", &numChickens, &numCows);
    for (int i=0; i<numChickens; i++) {
        int chickenTime;
        scanf("%d", &chickenTime);
        chickenTimes.push_back(chickenTime);
    }
    for (int i=0; i<numCows; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        cowTimes.push_back({from, to});
    }
}

bool cmp(pair<int, int> p0, pair<int, int> p1) {
    return p0.second < p1.second;
}

void _sort() {
    //닭의 시간을 오름차순 정렬-
    sort(chickenTimes.begin(), chickenTimes.end());
    //소의 시간은 끝나는 시간을 기준으로 오름차순 정렬한다.
    sort(cowTimes.begin(), cowTimes.end(), cmp);
}

int main() {
    input();
    _sort();
    bool isChickenUsed[numChickens] = {false};
    int result = 0;
    for (int cow=0; cow<numCows; cow++) {
        //이번 소에 대해서 도와줄 닭의 인덱스를 담는 변수-
        int idx = -1;
        for (int chicken=0; chicken<numChickens; chicken++) {
            if (isChickenUsed[chicken]) continue;
            if (chickenTimes[chicken]>=cowTimes[cow].first && chickenTimes[chicken]<=cowTimes[cow].second) {
                idx = chicken;
                break;
            }
        } //chicken loop
        if (idx!=-1) {
            result++;
            isChickenUsed[idx] = true;
        }
    } //cow loop
    printf("%d", result);
    return 0;
}
