#include <stdio.h>

//2차원 부분합
int boardSize;
int board[301][301];
//partialSum[r][c] := 0행 0열부터 r행 c열까지 영역에 있는 나무에서 얻을 수 있는 이익의 합
int partialSum[301][301];

void input() {
    scanf("%d", &boardSize);
    for (int row=0; row<boardSize; row++) {
        for (int col=0; col<boardSize; col++) {
            int elem;
            scanf("%d", &elem);
            board[row][col] = elem;
        } //col loop
    } //row loop
}

//partialSum 배열을 구성한다.
void buildPartialSum() {
    //part a. 초기값
    partialSum[0][0] = board[0][0];
    //part b. 0행의 값 (바로 왼쪽 열에 기록된 부분합을 사용한다.)
    {
        const int row = 0;
        for (int col=1; col<boardSize; col++) {
            partialSum[row][col] = board[row][col] + partialSum[row][col-1];
        }
    }
    //part c. 0열의 값 (바로 윗쪽 행에 기록된 부분합을 사용한다.)
    {
        const int col = 0;
        for (int row=1; row<boardSize; row++) {
            partialSum[row][col] = board[row][col] + partialSum[row-1][col];
        }
    }
    //part d. 1행 1열부터 계산
    for (int row=1; row<boardSize; row++) {
        for (int col=1; col<boardSize; col++) {
            partialSum[row][col] = board[row][col] + partialSum[row][col-1] + partialSum[row-1][col] - partialSum[row-1][col-1];
        } //col loop
    } //row loop

    /*
    for (int row=0; row<boardSize; row++) {
        for (int col=0; col<boardSize; col++) {
            printf("%d ", partialSum[row][col]);
        }
        puts("");
    }
    */
}

//row행, col열부터 시작하는 sz*sz 크기의 정사각형 영역에서 얻을 수 있는 이익을 계산한다.
int sumIn(int row, int col, int sz) {
    const int row_to = row+sz-1;
    const int col_to = col+sz-1;
    const int row_1 = row-1;
    const int col_1 = col-1;
    int result = partialSum[row_to][col_to];
    //선택한 정사각형의 왼쪽 영역을 빼 준다.
    if (col_1>=0) {
        result -= partialSum[row_to][col_1];
    }
    //선택한 정사각형의 윗쪽 영역을 빼 준다.
    if (row_1>=0) {
        result -= partialSum[row_1][col_to];
    }
    //왼쪽 영역과 윗쪽 영역을 빼 주는 과정에서 두 번 빼 준 영역은 한 번 더해준다.
    //즉, 과하게 빼 준 값은 한 번 더해준다.
    if (row_1>=0 && col_1>=0) {
        result += partialSum[row_1][col_1];
    }
    /*
    printf("row: %d, col: %d, sz: %d, result: %d\n", row, col, sz, result);
    */
    return result;
}

int _max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    input();
    buildPartialSum();
    int result = -90000000;
    for (int sz=1; sz<=boardSize; sz++) {
        for (int row=0; row<=boardSize-sz; row++) {
            for (int col=0; col<=boardSize-sz; col++) {
                result = _max(result, sumIn(row, col, sz));
            } //col loop
        } //row loop
    } //sz loop
    printf("%d", result);
    return 0;
}
