#include <stdio.h>

//table[a][b] := a행 b열에 있는 수
int table[1025][1025];
//dpArray[a][b] := 1행 1열에서 a행 b열 까지 직사각형에 포함된 수의 합
int dpArray[1025][1025];
//각 합 연산의 요구 사항 (queries[i][0]행 queries[i][1]열 부터 queries[i][2]행 queries[i][3]열 까지 직사각형 영역에 들어온 수의 합을 계산)
int queries[100001][4];


void executeQuery(int x1, int y1, int x2, int y2) {
    //x2행 y2열 까지 합을 계산하되, x1-1 행까지의 합, y1-1 열까지의 합을 뺀다. x1-1 행 y1-1 열 까지의 합은 두 번 제거되므로 한 번 더하여 이를 상쇄한다.
    int result = dpArray[x2][y2]-dpArray[x1-1][y2]-dpArray[x2][y1-1]+dpArray[x1-1][y1-1];
    printf("%d\n", result);
}

int main() {
    int tableSize, numQueries;
    scanf("%d %d", &tableSize, &numQueries);
    for (int row=1; row<=tableSize; row++) {
        for (int col=1; col<=tableSize; col++) {
            int num;
            scanf("%d", &num);
            table[row][col] = num;
            //1행 1열부터 row행 col열까지의 합을 구하기 위해 바로 전행 까지의 합과 바로 전열 까지의 합을 사용하되, 바로 전행 바로 전열 까지의 합은 두 번 더해지므로 중복은 제거한다.
            //데이터를 넣을 때 인덱스를 1부터 사용했으므로 [바로 전 행], [바로 전 열]을 계산할 때 예외 처리 없이 row-1, col-1을 사용할 수 있다.
            dpArray[row][col] = dpArray[row-1][col] + dpArray[row][col-1] - dpArray[row-1][col-1] + num;
        } //col loop
    } //row loop

    /*
    for (int row=1; row<=tableSize; row++) {
        for (int col=1; col<=tableSize; col++) {
            printf("%5d ", dpArray[row][col]);
        }
        puts("");
    }
    */

    for (int i=0; i<numQueries; i++) {
        scanf("%d %d %d %d", &queries[i][0], &queries[i][1], &queries[i][2], &queries[i][3]);
    }

    for (int i=0; i<numQueries; i++) {
        executeQuery(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
    }

    return 0;
}
