#include <bits/stdc++.h>

using namespace std;

/**������ ũ��*/
int Size;
/**ü���� �� �밢���� ���� �밢�� ��ȣ*/
int median;
/**�� ü�� ĭ�� ����� �ö�� �� �ִ��� ����*/
bool bishopAvailableAt[10][10];
/**�� ���� �밢���� ���� ����� ��ġ�ϴ� ���� �밢�� ��ȣ. (�ش� ���� �밢���� ���� ����� ���� ��� -1�� ��ġ��Ų��.)*/
int uDiagArr[19] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
/**�� ���� �밢���� ���� ����� �����ߴ��� ����*/
bool usedUDiag[19];
/**�ش� ü���ǿ� ���� ���� �� �ִ� ����� �ִ� ����*/
int optResult = 0;



/**�Է¹��� ������ ���밪�� ��ȯ�Ѵ�.*/
int abs(int num) {
    return num>=0 ? num : -num;
}
/**�Է¹��� ü������ ���� �밢�� ��ȣ�� ��ȯ�Ѵ�. ���ϱ͸� ������ �밢���� 0, ���͸� ������ �밢���� �ִ�ġ�� �ȴ�.*/
int dDiagNum(int row, int col) {
    return Size-1+col-row;
}
/**�Է¹��� ü������ ���� �밢�� ��ȣ�� ��ȯ�Ѵ�. �»�͸� ������ �밢���� 0, ���ϱ͸� ������ �밢���� �ִ�ġ�� �ȴ�,*/
int uDiagNum(int row, int col) {
    return col+row;
}
/**�� �밢�� ��ȣ�� �Է¹޾� �����Ǵ� ����ȣ�� ��ȯ�Ѵ�. �º��� ������ ���� 0, �캯�� ������ ���� �ִ�ġ�� �ȴ�.*/
int colNum(int dDiag, int uDiag) {
    return (dDiag+uDiag-Size+1)/2;
}
/**�� �밢�� ��ȣ�� �Է¹޾� �����Ǵ� ���ȣ�� ��ȯ�Ѵ�. ���� ������ ���� 0, �Ϻ��� ������ ���� �ִ�ġ�� �ȴ�.*/
int rowNum(int dDiag, int uDiag) {
    return (Size-1-dDiag+uDiag)/2;
}
/**���� �밢�� ��ȣ�� �Է¹޾� ���� �밢�� ��ȣ�� �� �� �ִ� ���� �밢�� ��ȣ�� �ּ�ġ�� ��ȯ�Ѵ�.*/
int minUDiagNum(int dDiag) {
    return abs(dDiag-median);
}
int maxUDiagNum(int dDiag) {
    return 2*median-abs(dDiag-median);
}

//��� �Լ� (dDiag: �̹��� ���� ����� ���� �밢�� ��ȣ)
void backtrack(int dDiag, int cnt) {
    //���̽� ���̽�
    if (dDiag==2*Size-1) {
        if (cnt>optResult) optResult=cnt;
        return;
    }

    //�ش� ���� �밢������ ����� ���� �ʰ� �ѱ�� ������
    uDiagArr[dDiag] = -1;
    backtrack(dDiag+1, cnt);

    //�ش� ���� �밢�� �� ������ ĭ�� ����� �ְ� �ѱ�� ������
    for (int uDiag=minUDiagNum(dDiag); uDiag<=maxUDiagNum(dDiag); uDiag+=2) {
        if (usedUDiag[uDiag]) continue; //�ش� ���� �밢�� ĭ�� �̹� ������ ���-
        int row = rowNum(dDiag, uDiag);
        int col = colNum(dDiag, uDiag);
        if (!bishopAvailableAt[row][col]) continue; //�ش� ĭ�� ����� ���� �� ���� ���-
        uDiagArr[dDiag] = uDiag;
        usedUDiag[uDiag] = true;
        backtrack(dDiag+1, cnt+1);
        usedUDiag[uDiag] = false;
        uDiagArr[dDiag] = -1;
    } //uDiag loop
}




int main() {
    cin >> Size;
    median = Size-1;
    for (int row=0; row<Size; row++) {
        for (int col=0; col<Size; col++) {
            cin >> bishopAvailableAt[row][col];
        } //col loop
    } //row loop
    backtrack(0, 0);
    cout << optResult;
    return 0;
}
