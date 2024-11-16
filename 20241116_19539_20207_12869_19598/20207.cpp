#include <stdio.h>

/*
    하나의 계획이 시작되는 날과 끝나는 날을 표기한다.
    이 표기를 "휩쓸어서" 특정 날의 스케줄 개수를 파악할 수 있다.
    => 배열을 사용한 휩쓸기
*/

int N;
int beginDates[1001];
int endDates[1001];
int dNumSchedules[367]; //스케줄 개수 변화 배열 dNumSchedules[i]가 양수인 경우 i 번째 날에 스케줄 개수가 증가한다.

void input() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &beginDates[i], &endDates[i]);
        dNumSchedules[beginDates[i]]++;
        dNumSchedules[endDates[i]+1]--;
    } //i loop
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    input();
    int result = 0; //코팅지 면적
    int currentNumSchedules = 0; //현재 스케줄 개수
    int localMaxNumSchedules = 0; //현재 스케줄이 존재하는 구간에서 스케줄 개수의 최대치
    int currentDuration = 0; //현재 스케줄이 존재하는 기간

    //달력을 "휩쓸면서" 스케줄 개수를 갱신해 나갈 수 있다.
    for (int day=0; day<=366; day++) {
        //현재 스케줄 개수 갱신
        currentNumSchedules += dNumSchedules[day];
        //현재 스케줄이 있는 경우
        if (currentNumSchedules) {
            currentDuration++;
            localMaxNumSchedules = max(localMaxNumSchedules, currentNumSchedules);
        }
        //현재 스케줄이 막 끊겼을 경우- (이제 막 여유러워졌을 때-)
        else if (localMaxNumSchedules) {
            //코팅지 넓이 계산
            result += currentDuration * localMaxNumSchedules;
            currentDuration = 0;
            localMaxNumSchedules = 0;
        }
    } //day loop
    printf("%d", result);
    return 0;
}
