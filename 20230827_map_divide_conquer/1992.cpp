#include <stdio.h>
#include <iostream>
#include <string>

// �ð� �ʰ�

using namespace std;

int N; // ������ ��ü ũ��
char picture[64][65]; // ���� �ڷ�. �ش� ��, �� ��ġ�� �ִ� ���� ������ ���� �ִ�.

/**
 * �� row ~ row+range-1, �� col ~ col+range-1 ������ ���簢���� ����<br/>
 * �Է¹��� �׸��� �� ���� ������ �����Ǿ����� ���θ� ��ȯ�Ѵ�.
 */
bool isUniformIn(int row, int col, int range) {
    char initialPixel = picture[row][col];
    for (int i=row; i<row+range; i++) {
        for (int j=col; j<col+range; j++) {
            if (picture[i][j]!=initialPixel)
                return false;
        } //j loop
    } //i loop
    return true;
}

/**
 * �Է¹޴� �׸��� ���� �� row ~ row+size-1, �� col ~ col+size-1<br/>
 * ������ ���簢�� ������ ������ ����� ��ȯ�Ѵ�.
 */
string QT(int row, int col, int size) {
    //���̽� ���̽�
    if (isUniformIn(row, col, size)) {
        return to_string(picture[row][col]-48);
    }

    int halfSize = size/2;
    string result = "(";
    result += QT(row, col, halfSize); //���� �� ���� ���
    result += QT(row, col+halfSize, halfSize); //������ �� ���� ���
    result += QT(row+halfSize, col, halfSize); //���� �Ʒ� ���� ���
    result += QT(row+halfSize, col+halfSize, halfSize); //������ �Ʒ� ���� ���
    result += ")";
    return result;
}


int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%s", picture[i]);
    }

    cout << QT(0, 0, N);



    return 0;
}
