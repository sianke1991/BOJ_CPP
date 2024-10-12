#include <stdio.h>
#include <algorithm>
#define timeRequired 0
#define expectedScore 1

//단원 개수
int numChapters;
//시험까지 공부할 수 있는 총 시간
int timeAvailable;
//각 단원을 공부하는 데 필요한 시간 및 단원의 배점
int chapter[101][2];

int dp[10001] = {0};

void input() {
    scanf("%d %d", &numChapters, &timeAvailable);
    for (int i=0; i<numChapters; i++) {
        scanf("%d %d", &chapter[i][timeRequired], &chapter[i][expectedScore]);
    }
}

int main() {
    input();
    for (int chapterIndex=0; chapterIndex<numChapters; chapterIndex++) {
        for (int t=timeAvailable; t>=chapter[chapterIndex][timeRequired]; t--) {
            dp[t] = std::max(dp[t], dp[t-chapter[chapterIndex][timeRequired]]+chapter[chapterIndex][expectedScore]);
        } //t loop
    } //chapterIndex loop
    printf("%d", dp[timeAvailable]);
    return 0;
}
