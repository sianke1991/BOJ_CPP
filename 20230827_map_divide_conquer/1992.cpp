#include <stdio.h>
#include <iostream>
#include <string>

// 시간 초과

using namespace std;

int N; // 영상의 전체 크기
char picture[64][65]; // 영상 자료. 해당 행, 열 위치에 있는 점의 정보를 갖고 있다.

/**
 * 행 row ~ row+range-1, 열 col ~ col+range-1 내부의 정사각형에 대해<br/>
 * 입력받은 그림이 한 가지 색으로 구성되었는지 여부를 반환한다.
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
 * 입력받는 그림에 대해 행 row ~ row+size-1, 열 col ~ col+size-1<br/>
 * 내부의 정사각형 영역을 압축한 결과를 반환한다.
 */
string QT(int row, int col, int size) {
    //베이스 케이스
    if (isUniformIn(row, col, size)) {
        return to_string(picture[row][col]-48);
    }

    int halfSize = size/2;
    string result = "(";
    result += QT(row, col, halfSize); //왼쪽 위 압축 결과
    result += QT(row, col+halfSize, halfSize); //오른쪽 위 압축 결과
    result += QT(row+halfSize, col, halfSize); //왼쪽 아래 압축 결과
    result += QT(row+halfSize, col+halfSize, halfSize); //오른쪽 아래 압축 결과
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
