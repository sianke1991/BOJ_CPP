#include <stdio.h>

int enterExit[10][10];

int main() {
    //block (1,1)에서 (3,5)까지 가로4, 세로2짜리 사각형만큼 높이를 1 만큼 높힌다.
    {
        enterExit[1][1]=1;  //사각형의 왼쪽 위 지정
        enterExit[1][6]=-1; //사각형의 오른쪽 끝 지정
        enterExit[4][1]=-1; //사각형의 아래 끝 지정
        enterExit[4][6]=1;  //사각형의 끝이 두 번 적용되는 것을 막기 위해 오른쪽 아래 끝을 별도로 지정해준다.
    }
    //block (2,2) 에서 (5,7)까지 가로5, 세로3짜리 사각형만큼 높이를 1 만큼 높힌다.
    {
        enterExit[2][2]=1;
        enterExit[2][8]=-1;
        enterExit[6][2]=-1;
        enterExit[6][8]=1;
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%2d ", enterExit[i][j]);
        }
        puts("");
    }
    puts("=======================================");

    for (int i=0; i<10; i++) { //모든 행에 대해서-
        for (int j=1; j<10; j++) { //바로 오른쪽 칸의 높이는 바로 왼쪽 칸의 높이에 enterExit를 더한 결과라는 논리를 적용한다.
             enterExit[i][j] = enterExit[i][j-1]+enterExit[i][j];
        }
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%2d ", enterExit[i][j]);
        }
        puts("");
    }
    puts("=======================================");

    for (int j=0; j<10; j++) { //모든 열에 대해서-
        for (int i=1; i<10; i++) { //바로 아래 칸의 높이는 바로 윗 칸의 높이에 enterExit를 더한 결과라는 논리를 적용한다.
            enterExit[i][j] = enterExit[i-1][j]+enterExit[i][j];
        }
    }


    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%2d ", enterExit[i][j]);
        }
        puts("");
    }
    return 0;


}

/*
출력 결과
 0  0  0  0  0  0  0  0  0  0
 0  1  0  0  0  0 -1  0  0  0
 0  0  1  0  0  0  0  0 -1  0
 0  0  0  0  0  0  0  0  0  0
 0 -1  0  0  0  0  1  0  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0 -1  0  0  0  0  0  1  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
=======================================
 0  0  0  0  0  0  0  0  0  0
 0  1  1  1  1  1  0  0  0  0
 0  0  1  1  1  1  1  1  0  0
 0  0  0  0  0  0  0  0  0  0
 0 -1 -1 -1 -1 -1  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0 -1 -1 -1 -1 -1 -1  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
=======================================
 0  0  0  0  0  0  0  0  0  0
 0  1  1  1  1  1  0  0  0  0
 0  1  2  2  2  2  1  1  0  0
 0  1  2  2  2  2  1  1  0  0
 0  0  1  1  1  1  1  1  0  0
 0  0  1  1  1  1  1  1  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0
*/
