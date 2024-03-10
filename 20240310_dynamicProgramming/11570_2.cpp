#include <stdio.h>
#include <bits/stdc++.h>
#define NULL -2147483648

using namespace std;


/*
    a가 마지막 음을 불렀을 때 힘든 정도의 최소치
    dpArray[n][m]:= 인덱스 n에 해당하는 음 까지 불렀을 때 최근 m+1개의 음을 a가 부른 경우 힘든 정도의 최소치
 */
int dpArray[2001][2001];

/*
    노래를 구성하는 음의 높이
 */
int height[2001];
/*
    최소치를 구할 때 사용할 임시 벡터
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

    //초기 조건
    dpArray[0][0] = 0;

    for (int i=1; i<length; i++) {

        int j = 0;
        //j가 0인 경우 바로 전 음은 b가 불렀으므로 b가 전 음을 부른 모든 경우에 대해 최소치를 찾아야 한다.
        //이 경우에 한정하여 recentBCalls(n, m)는 최근에 a가 부른 음이 된다.
        vec.clear();
        for (int k=0; k<=i-1; k++) {
            vec.push_back(dpArray[i-1][k] + diff(height[i], recentBCalls(i-1, k)));
        }
        dpArray[i][j] = min(vec);

        for (j=1; j<=i; j++) {
            dpArray[i][j] = dpArray[i-1][j-1]+diff(height[i], height[i-1]);
        } //j loop (최근에 a가 연속하여 부른 음의 개수에 대한 loop)

    } //i loop (곡의 길이에 대한 loop)

    vec.clear();
    for (int j=0; j<length; j++) {
        vec.push_back(dpArray[length-1][j]);
    }

    printf("%d\n", min(vec));

    return 0;
}
