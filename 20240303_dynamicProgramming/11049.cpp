#include <stdio.h>
#include <vector>

using namespace std;

/*
    matrixSizes[i][0]: �Է¹��� �ε��� i ���� ��� ũ�� {���� ����, ���� ����}
    matrixSizes[i][j]: �ε��� i ���� ����� �����Ͽ� j+1���� ����� ���� ũ�� eg. matrixSizes[4][2]�� ��� CDE�� ũ��
 */
pair<int, int> matrixSizes[501][501];
/*
    dpArray[i][0] = 0, for all i
    dpArray[i][j]: �ε��� i ���� ����� �����Ͽ� j+1���� ������ ���� ���� �� �����ؾ� �� ���� Ƚ���� �ּҰ�
 */
int dpArray[501][501];
/*
    dpArray[i][j]�� ���� �� j���� �� �� �ּ�ġ�� ���ؾ� �ϴµ�, �� �� ����� �ӽ� ����
 */
vector<int> dpVector;

pair<int, int> matrixSizeAfterMultiplying(pair<int, int> matrix0Size, pair<int, int> matrix1Size) {
    return {matrix0Size.first, matrix1Size.second};
}

int numMultiplyings(pair<int, int> matrix0Size, pair<int, int> matrix1Size) {
    return matrix0Size.first * matrix0Size.second * matrix1Size.second;
}

int min(vector<int> vec) {
    int result = vec[0];
    for (int elem:vec) {
        if (elem<result)
            result = elem;
    }
    return result;
}


int main() {
    int numMatrices;
    scanf("%d", &numMatrices);
    for (int i=0; i<numMatrices; i++) {
        int numRows, numCols;
        scanf("%d %d", &numRows, &numCols);
        matrixSizes[i][0] = {numRows, numCols};
    } //i loop

    for (int i=1; i<numMatrices; i++) {
        for (int j=1; j<=i; j++) {
            matrixSizes[i][j] = matrixSizeAfterMultiplying(matrixSizes[i-1][j-1], matrixSizes[i][0]);
            dpVector.clear();
            for (int k=0; k<j; k++) {
                dpVector.push_back(dpArray[i-k-1][j-k-1] + dpArray[i][k] + numMultiplyings(matrixSizes[i-k-1][j-k-1], matrixSizes[i][k]));
            } //k loop
            dpArray[i][j] = min(dpVector);
        } //j loop
    } //i loop


    printf("%d", dpArray[numMatrices-1][numMatrices-1]);

    return 0;
}
