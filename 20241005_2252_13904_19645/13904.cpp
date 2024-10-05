#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


int numHomeWorks;
vector<int> homeWorks[1001]; //마감일에 따른 과제의 점수를 기록한다. (e.g. homeWorks[3]:= 기한이 3일 짜리인 과제의 점수 목록)
priority_queue<int> pq; //현재 시점에 유효한 과제 모음

int main() {
    //과제 입력 받기-
    scanf("%d", &numHomeWorks);
    for (int i=0; i<numHomeWorks; i++) {
        int due, value;
        scanf("%d %d", &due, &value);
        homeWorks[due].push_back(value);
    } //i loop

    int result = 0;
    //시간을 역행하면서, 현재 유효한 과제 중에서 가치가 높은 과제를 해결한다.
    //시간을 역행해야 [유효한 과제]가 점점 추가된다.
    //시간을 순행하면 [유효한 과제가 더 이상 유효하지 않게 되는 것]을 고려해야 한다.
    for (int currentDate=1000; currentDate>=1; currentDate--) {
        //step a. 해당 날짜에 유효한 과제를 pq에 넣는다.
        for (auto hw:homeWorks[currentDate]) pq.push(hw);
        //step b. pq가 비어있지 않은 경우 pq에서 가장 가치가 높은 것을 꺼내서 해결한다.
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    } //currentDate loop
    printf("%d", result);
    return 0;
}
