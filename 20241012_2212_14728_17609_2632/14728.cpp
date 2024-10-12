#include <stdio.h>
#include <algorithm>
#define timeRequired 0
#define expectedScore 1

//�ܿ� ����
int numChapters;
//������� ������ �� �ִ� �� �ð�
int timeAvailable;
//�� �ܿ��� �����ϴ� �� �ʿ��� �ð� �� �ܿ��� ����
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
