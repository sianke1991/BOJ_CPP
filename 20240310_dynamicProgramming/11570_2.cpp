#include <stdio.h>
#include <bits/stdc++.h>
#define NULL -2147483648

using namespace std;


/*
    a�� ������ ���� �ҷ��� �� ���� ������ �ּ�ġ
    dpArray[n][m]:= �ε��� n�� �ش��ϴ� �� ���� �ҷ��� �� �ֱ� m+1���� ���� a�� �θ� ��� ���� ������ �ּ�ġ
 */
int dpArray[2001][2001];

/*
    �뷡�� �����ϴ� ���� ����
 */
int height[2001];
/*
    �ּ�ġ�� ���� �� ����� �ӽ� ����
 */
vector<int> vec;

int min(vector<int> v) {
    int result = v[0];
    for (int elem:v) {
        if (elem<result) result = elem;
    }
    return result;
}

int abs(int num) {
    return num<0 ? -num : num;
}

int diff(int num0, int num1) {
    if (num0==NULL || num1==NULL)
        return 0;
    else
        return abs(num0-num1);
}

int recentBCalls(int i, int j) {
    if (j>=i) return NULL;
    else      return height[i-j-1];
}


int main() {
    int length;
    scanf("%d", &length);
    for (int i=0; i<length; i++) {
        scanf("%d", &height[i]);
    }

    //�ʱ� ����
    dpArray[0][0] = 0;

    for (int i=1; i<length; i++) {

        int j = 0;
        //j�� 0�� ��� �ٷ� �� ���� b�� �ҷ����Ƿ� b�� �� ���� �θ� ��� ��쿡 ���� �ּ�ġ�� ã�ƾ� �Ѵ�.
        //�� ��쿡 �����Ͽ� recentBCalls(n, m)�� �ֱٿ� a�� �θ� ���� �ȴ�.
        vec.clear();
        for (int k=0; k<=i-1; k++) {
            vec.push_back(dpArray[i-1][k] + diff(height[i], recentBCalls(i-1, k)));
        }
        dpArray[i][j] = min(vec);

        for (j=1; j<=i; j++) {
            dpArray[i][j] = dpArray[i-1][j-1]+diff(height[i], height[i-1]);
        } //j loop (�ֱٿ� a�� �����Ͽ� �θ� ���� ������ ���� loop)

    } //i loop (���� ���̿� ���� loop)

    vec.clear();
    for (int j=0; j<length; j++) {
        vec.push_back(dpArray[length-1][j]);
    }

    printf("%d\n", min(vec));

    return 0;
}
