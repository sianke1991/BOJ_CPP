#include <stdio.h>

/**
개미 위치 x 좌표의 주기는 전체 격자의 가로 길이의 두 배이다.
전체 격자의 가로 길이가 6일 경우 개미 위치 x 좌표는
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
으로 변하고 이 사이클이 반복된다.
따라서 개미 위치 x 좌표를 구하기 위해 전체 격자 가로 길이의 두 배에 대해 modular 연산이 사용된다.
*/


int main() {
    //전체 격자의 가로 길이
    long long w;
    //전체 격자의 세로 길이
    long long h;
    scanf("%lld %lld", &w, &h);
    //개미 초기 위치의 x 좌표
    long long p;
    //개미 초기 위치의 y 좌표
    long long q;
    scanf("%lld %lld", &p, &q);
    //지나간 시간
    long long t;
    scanf("%lld", &t);

    long long resultX = (p+t)%(2*w);
    if (resultX>w) resultX = 2*w-resultX;
    long long resultY = (q+t)%(2*h);
    if (resultY>h) resultY = 2*h-resultY;

    printf("%lld %lld", resultX, resultY);


    return 0;
}
