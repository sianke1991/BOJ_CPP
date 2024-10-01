#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//���� �ð��� �������� ������ ��-
//�Ҹ� ������ �� �ִ� �� �� ó�� ��Ī�Ǵ� ���� �����Ѵ�.

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
    //���� �ð��� �������� ����-
    sort(chickenTimes.begin(), chickenTimes.end());
    //���� �ð��� ������ �ð��� �������� �������� �����Ѵ�.
    sort(cowTimes.begin(), cowTimes.end(), cmp);
}

int main() {
    input();
    _sort();
    bool isChickenUsed[numChickens] = {false};
    int result = 0;
    for (int cow=0; cow<numCows; cow++) {
        //�̹� �ҿ� ���ؼ� ������ ���� �ε����� ��� ����-
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
