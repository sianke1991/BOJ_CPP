#include <stdio.h>

//2���� �κ���
int boardSize;
int board[301][301];
//partialSum[r][c] := 0�� 0������ r�� c������ ������ �ִ� �������� ���� �� �ִ� ������ ��
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

//partialSum �迭�� �����Ѵ�.
void buildPartialSum() {
    //part a. �ʱⰪ
    partialSum[0][0] = board[0][0];
    //part b. 0���� �� (�ٷ� ���� ���� ��ϵ� �κ����� ����Ѵ�.)
    {
        const int row = 0;
        for (int col=1; col<boardSize; col++) {
            partialSum[row][col] = board[row][col] + partialSum[row][col-1];
        }
    }
    //part c. 0���� �� (�ٷ� ���� �࿡ ��ϵ� �κ����� ����Ѵ�.)
    {
        const int col = 0;
        for (int row=1; row<boardSize; row++) {
            partialSum[row][col] = board[row][col] + partialSum[row-1][col];
        }
    }
    //part d. 1�� 1������ ���
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

//row��, col������ �����ϴ� sz*sz ũ���� ���簢�� �������� ���� �� �ִ� ������ ����Ѵ�.
int sumIn(int row, int col, int sz) {
    const int row_to = row+sz-1;
    const int col_to = col+sz-1;
    const int row_1 = row-1;
    const int col_1 = col-1;
    int result = partialSum[row_to][col_to];
    //������ ���簢���� ���� ������ �� �ش�.
    if (col_1>=0) {
        result -= partialSum[row_to][col_1];
    }
    //������ ���簢���� ���� ������ �� �ش�.
    if (row_1>=0) {
        result -= partialSum[row_1][col_to];
    }
    //���� ������ ���� ������ �� �ִ� �������� �� �� �� �� ������ �� �� �����ش�.
    //��, ���ϰ� �� �� ���� �� �� �����ش�.
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
