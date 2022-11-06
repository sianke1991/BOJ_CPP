#include <bits/stdc++.h>
using namespace std;

/**
    N: ���� �ܰ� ��. ���� �ܰ迡�� ����ϴ� �� �� ���� ������ 2**N ���̴�.
    r: ���� ����ϴ� �׸��� �������� �� ��ȣ (0�̻� 2**N �̸�)
    c: ���� ����ϴ� �׸��� �������� �� ��ȣ (0�̻� 2**N �̸�)
*/
int getNumSteps(int N, int r, int c) {
    //base cases
    if (N==0) {
        return 0;
    } else if (N==1) {
        return 2*r+c;
    }

    int isRowGreaterThanHalf = r>=(1<<(N-1));
    int isColGreaterThanHalf = c>=(1<<(N-1));
    int quadrant             = isRowGreaterThanHalf*2+isColGreaterThanHalf;
    int numQuarterGrids      = 1<<(2*N-2);
    int lengthHalfSide       = 1<<(N-1);
    return quadrant*numQuarterGrids+getNumSteps(N-1, r%lengthHalfSide, c%lengthHalfSide);
}

int getNumSteps2(int N, int r, int c) {
    //base cases
    if (N==0) return 0;
    int isRowGreaterThanHalf = r>=(1<<(N-1));
    int isColGreaterThanHalf = c>=(1<<(N-1));
    int quadrant             = isRowGreaterThanHalf*2+isColGreaterThanHalf; //���� ���� 0��и�, ������ ���� 1��и�, ���� �Ʒ��� 2��и�, ������ �Ʒ��� 3��и�
    int lenHalfSide          = 1<<(N-1);
    switch (quadrant) {
        case 0:
            return getNumSteps2(N-1, r, c);
        case 1:
            return lenHalfSide*lenHalfSide+getNumSteps2(N-1, r, c-lenHalfSide); //r�� ������ ���� �ʱ� ������ lenHalfSide��ŭ ���� �ʾƵ� OK.
        case 2:
            return 2*lenHalfSide*lenHalfSide+getNumSteps2(N-1, r-lenHalfSide, c); //c�� ������ ���� �ʱ� ������ lenHalfSide��ŭ ���� �ʾƵ� OK.
        case 3:
            return 3*lenHalfSide*lenHalfSide+getNumSteps2(N-1, r-lenHalfSide, c-lenHalfSide);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << getNumSteps(N, r, c);
    return 0;
}
