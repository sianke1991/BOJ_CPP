#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

//�ش� ������ �����ϴ� ����� ��
int dpArray[501][501];
//�ش� ������ ����
int height[501][501];

int dRow[4] = {-1, 0, 1, 0};
int dCol[4] = {0, 1, 0, -1};

/*
string to_string(pair<int, int> p) {
    string result = "{";
    result += to_string(p.first);
    result += ", ";
    result += to_string(p.second);
    result += "}";
    return result;
}
*/

int main() {
    dpArray[0][0] = 1; //���� ������ �����ϴ� ����� ���� 1�̴�.
    int numRows, numCols;
    scanf("%d %d", &numRows, &numCols);

    //�� ���̿� ���� ���� ���
    multimap<int, pair<int, int>, greater<int>> mm; //multimap�� ����ϵ�, key�� ������������ �����ϱ� ���� ���ø��� �� ��° ���ڸ� �ִ´�.

    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            int h;
            scanf("%d", &h);
            mm.insert({h, {row, col}}); // multimap�� ���� �������� insert �޼��� �ȿ� key, value�� �� pair<> �� �ִ´�.
            height[row][col] = h;
        } //col loop
    } //row loop

    /*
     * �� ������ ���� ������ �� �ִ� ����� ���� ��Ƹ���,
     * ���� ���� �������� ���ʴ�� ��Ƹ���.
     * (���� �������� ���� �������� ������ ���� ������, ���� �������� ���� �������� �ö� ���� ����.
     *  ���� ����� ���� ��Ƹ��� ���ؼ��� ���� ������ ����� ���� ���� ��Ʒ��� �Ѵ�.)
     */
    for (auto it:mm) {
        //cout << it.first << ", " << to_string(it.second) << '\n';
        int currentHeight = it.first; //���� ����ϰ� �ִ� ĭ�� ����
        int currentRow = it.second.first; //���� ����ϰ� �ִ� ĭ�� �� ��ȣ
        int currentCol = it.second.second; //���� ����ϰ� �ִ� ĭ�� �� ��ȣ
        if (currentRow==0 && currentCol==0) //���� ������ �̹� �� ����� ���� ��Ʒȴ�.
            continue;
        for (int dir=0; dir<4; dir++) {
            int nextRow = currentRow + dRow[dir]; //�̿��� ĭ�� �� ��ȣ
            int nextCol = currentCol + dCol[dir]; //�̿��� ĭ�� �� ��ȣ
            if (nextRow<0 || nextRow>=numRows || nextCol<0 || nextCol>=numCols) //out of bounds
                continue;
            int nextHeight = height[nextRow][nextCol]; //�̿��� ĭ�� ����
            if (nextHeight <= currentHeight) //�̿��� ĭ�� ���� ĭ���� ������ �� ���� ���-
                continue;
            //printf("current square: %d, %d, %d, %d, %d, %d\n", currentHeight, currentRow, currentCol, nextHeight, nextRow, nextCol);
            dpArray[currentRow][currentCol] += dpArray[nextRow][nextCol]; //�̿��� ĭ���� ���� ����ϰ� �ִ� ĭ���� �ǳʰ��� ��츦 ��Ƹ���.
        } //direction loop
    } //range-based loop


    /*
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            printf("%3d", dpArray[row][col]);
        }
        printf("\n");
    }
    */
    printf("%d", dpArray[numRows-1][numCols-1]);


    return 0;
}
