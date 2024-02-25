#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

//해당 지점에 도달하는 경우의 수
int dpArray[501][501];
//해당 지점의 높이
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
    dpArray[0][0] = 1; //시작 지점에 도달하는 경우의 수는 1이다.
    int numRows, numCols;
    scanf("%d %d", &numRows, &numCols);

    //각 높이에 따른 지점 목록
    multimap<int, pair<int, int>, greater<int>> mm; //multimap을 사용하되, key를 내림차순으로 저장하기 위해 템플릿에 세 번째 인자를 넣는다.

    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            int h;
            scanf("%d", &h);
            mm.insert({h, {row, col}}); // multimap에 값을 넣으려면 insert 메서드 안에 key, value로 된 pair<> 를 넣는다.
            height[row][col] = h;
        } //col loop
    } //row loop

    /*
     * 각 지점에 대해 도달할 수 있는 경우의 수를 헤아리되,
     * 가장 높은 지점부터 차례대로 헤아린다.
     * (높은 지점에서 낮은 지점으로 내려갈 수는 있지만, 낮은 지점에서 높은 지점으로 올라갈 수는 없다.
     *  따라서 경우의 수를 헤아리기 위해서는 높은 지점의 경우의 수를 먼저 헤아려야 한다.)
     */
    for (auto it:mm) {
        //cout << it.first << ", " << to_string(it.second) << '\n';
        int currentHeight = it.first; //현재 고려하고 있는 칸의 높이
        int currentRow = it.second.first; //현재 고려하고 있는 칸의 행 번호
        int currentCol = it.second.second; //현재 고려하고 있는 칸의 열 번호
        if (currentRow==0 && currentCol==0) //시작 지점은 이미 그 경우의 수를 헤아렸다.
            continue;
        for (int dir=0; dir<4; dir++) {
            int nextRow = currentRow + dRow[dir]; //이웃한 칸의 행 번호
            int nextCol = currentCol + dCol[dir]; //이웃한 칸의 열 번호
            if (nextRow<0 || nextRow>=numRows || nextCol<0 || nextCol>=numCols) //out of bounds
                continue;
            int nextHeight = height[nextRow][nextCol]; //이웃한 칸의 높이
            if (nextHeight <= currentHeight) //이웃한 칸이 현재 칸보다 오히려 더 낮은 경우-
                continue;
            //printf("current square: %d, %d, %d, %d, %d, %d\n", currentHeight, currentRow, currentCol, nextHeight, nextRow, nextCol);
            dpArray[currentRow][currentCol] += dpArray[nextRow][nextCol]; //이웃한 칸에서 현재 고려하고 있는 칸으로 건너가는 경우를 헤아린다.
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
