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
    priority_queue<pair<int, int>> pq; //방 A까지의 거리와 방 B까지의 거리의 차이를 first로, 팀의 인덱스를 second로 하는 pair를 pq에 넣는다.
                                            //거리의 차이가 큰 팀부터 꺼내야 하므로 최대힙을 사용한다.
    for (int i=0; i<numTeams; i++) {
        scanf("%d %d %d", &teams[i].numRequiredBalls, &teams[i].distToA, &teams[i].distToB);
        pq.push({abs(teams[i].distToA-teams[i].distToB), i});
    }
    long long result = 0LL; //각 팀이 풍선을 가져오기 위해 이동해야 하는 거리의 합
    while (!pq.empty()) {
        int currentTeamIndex = pq.top().second;
        pq.pop();
        if (teams[currentTeamIndex].distToA < teams[currentTeamIndex].distToB) { //방 A에서 우선적으로 풍선을 가져온다.
            //방 A에서 가져올 수 있는 풍선의 개수-
            int tmp = min(teams[currentTeamIndex].numRequiredBalls, numABalls);
            result += tmp * teams[currentTeamIndex].distToA;
            numABalls -= tmp;
            //방 B에서 가져와야 하는 풍선의 개수-
            int rem = teams[currentTeamIndex].numRequiredBalls-tmp;
            result += rem * teams[currentTeamIndex].distToB;
            numBBalls -= rem;
        } else { //방 B에서 우선적으로 풍선을 가져온다.
            //방 B에서 가져올 수 있는 풍선의 개수-
            int tmp = min(teams[currentTeamIndex].numRequiredBalls, numBBalls);
            result += tmp * teams[currentTeamIndex].distToB;
            numBBalls -= tmp;
            //방 A에서 가져와야 하는 풍선의 개수-
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
