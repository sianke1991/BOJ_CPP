#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

struct Team {
    int numRequiredBalls;
    int distToA;
    int distToB;
};

Team teams[1001];

int abs(int num) {
    return num >= 0 ? num : -num;
}

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

vector<long long> results;

bool testCase() {
    int numTeams, numABalls, numBBalls;
    scanf("%d %d %d", &numTeams, &numABalls, &numBBalls);
    if (numTeams==0)
        return true;
    priority_queue<pair<int, int>> pq; //�� A������ �Ÿ��� �� B������ �Ÿ��� ���̸� first��, ���� �ε����� second�� �ϴ� pair�� pq�� �ִ´�.
                                            //�Ÿ��� ���̰� ū ������ ������ �ϹǷ� �ִ����� ����Ѵ�.
    for (int i=0; i<numTeams; i++) {
        scanf("%d %d %d", &teams[i].numRequiredBalls, &teams[i].distToA, &teams[i].distToB);
        pq.push({abs(teams[i].distToA-teams[i].distToB), i});
    }
    long long result = 0LL; //�� ���� ǳ���� �������� ���� �̵��ؾ� �ϴ� �Ÿ��� ��
    while (!pq.empty()) {
        int currentTeamIndex = pq.top().second;
        pq.pop();
        if (teams[currentTeamIndex].distToA < teams[currentTeamIndex].distToB) { //�� A���� �켱������ ǳ���� �����´�.
            //�� A���� ������ �� �ִ� ǳ���� ����-
            int tmp = min(teams[currentTeamIndex].numRequiredBalls, numABalls);
            result += tmp * teams[currentTeamIndex].distToA;
            numABalls -= tmp;
            //�� B���� �����;� �ϴ� ǳ���� ����-
            int rem = teams[currentTeamIndex].numRequiredBalls-tmp;
            result += rem * teams[currentTeamIndex].distToB;
            numBBalls -= rem;
        } else { //�� B���� �켱������ ǳ���� �����´�.
            //�� B���� ������ �� �ִ� ǳ���� ����-
            int tmp = min(teams[currentTeamIndex].numRequiredBalls, numBBalls);
            result += tmp * teams[currentTeamIndex].distToB;
            numBBalls -= tmp;
            //�� A���� �����;� �ϴ� ǳ���� ����-
            int rem = teams[currentTeamIndex].numRequiredBalls-tmp;
            result += rem * teams[currentTeamIndex].distToA;
            numABalls -= rem;
        }
    } //while loop
    results.push_back(result);
    return false;
}

int main() {
    while (true) {
        if (testCase()) break;
    }
    for (auto result:results)
        printf("%lld\n", result);
    return 0;
}
