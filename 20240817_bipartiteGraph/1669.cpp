/*
    최고 속도를 3으로 할 경우 키 차이의 최소치는
    1+2+3+2+1 = 9
    최고 속도를 4로 할 경우 키 차이의 최소치는
    1+2+3+4+3+2+1 = 16

    따라서 키 차이가 d일 경우 최고 속도는 sqrt(d) 이어야 한다.

    최고 속도를 v 만큼 낼 경우 기본적으로 (2*v-1 일 만큼의 날짜를 소모하여) v*v 만큼의 키 차이를 따라잡는다.
    남은 키 r(=d-v*v)가 있는 경우 이 키를 따라잡기 위해서 추가로 ceil(r/v) 일 만큼이 필요하다.
*/
#include <stdio.h>
#include <math.h>

int main() {
    int h0, h1;
    scanf("%d %d", &h0, &h1);
    int diff = h1-h0;
    //최고 속도
    int maxSpeed = (int) sqrt(diff);
    if (maxSpeed==0) {
        printf("0");
        return 0;
    }
    //최고 속도에 도달하고 다시 감속하기 위해 필요한 기본 날짜
    int baseDays = 2*maxSpeed-1;
    //최고 속도에 도달하고 다시 감속하는 과정에서 키를 따라잡는데 아직 따라잡지 못한 분
    int remainingDiff = diff-maxSpeed*maxSpeed;
    //remainingDiff의 키를 따라잡기 위해 추가로 필요한 날짜
    int extraDays = (remainingDiff+maxSpeed-1)/maxSpeed;
    printf("%d", baseDays+extraDays);
    return 0;
}
