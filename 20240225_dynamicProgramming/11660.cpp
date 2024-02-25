#include <stdio.h>

//table[a][b] := a�� b���� �ִ� ��
int table[1025][1025];
//dpArray[a][b] := 1�� 1������ a�� b�� ���� ���簢���� ���Ե� ���� ��
int dpArray[1025][1025];
//�� �� ������ �䱸 ���� (queries[i][0]�� queries[i][1]�� ���� queries[i][2]�� queries[i][3]�� ���� ���簢�� ������ ���� ���� ���� ���)
int queries[100001][4];


void executeQuery(int x1, int y1, int x2, int y2) {
    //x2�� y2�� ���� ���� ����ϵ�, x1-1 ������� ��, y1-1 �������� ���� ����. x1-1 �� y1-1 �� ������ ���� �� �� ���ŵǹǷ� �� �� ���Ͽ� �̸� ����Ѵ�.
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
            //1�� 1������ row�� col�������� ���� ���ϱ� ���� �ٷ� ���� ������ �հ� �ٷ� ���� ������ ���� ����ϵ�, �ٷ� ���� �ٷ� ���� ������ ���� �� �� �������Ƿ� �ߺ��� �����Ѵ�.
            //�����͸� ���� �� �ε����� 1���� ��������Ƿ� [�ٷ� �� ��], [�ٷ� �� ��]�� ����� �� ���� ó�� ���� row-1, col-1�� ����� �� �ִ�.
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
