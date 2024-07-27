#include <stdio.h>
#include <vector>
#include <set>
#define ROW first
#define COL second

using namespace std;

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

//물고기의 위치 목록
vector<pair<int, int>> fish;
//물고기가 위치하는 행 번호 목록
set<int> rows;
//물고기가 위치하는 열 번호 목록
set<int> cols;

/**
물고기가 위치하는 행과 물고기가 위치하는 열에
그물을 설치하고 그물 안에 들어온 물고기의 개수를 헤아린다.
=> 물고기가 위치하는 점에 그물을 설치하는 것과는 다름에 주의한다.
물고기가 위치하는 점 100 개에 그물을 설치하는 것이 아니라
물고기가 위치하는 행 100 개와 물고기가 위치하는 열 100 개의 교점 10000 개에
그물을 설치하여 물고기 개수를 헤아린다,
*/

/**
 * 행 r0 이상 r1 이하, 열 c0 이상 c1 이하의 영역 안에 있는 물고기의 개수를 헤아린다.
 */
int numFishIn(int r0, int r1, int c0, int c1) {
    int result = 0;
    for (auto f:fish) {
        if (f.ROW>=r0 && f.ROW<=r1 && f.COL>=c0 && f.COL<=c1) result++;
    }
    return result;
}

int main() {
    //모눈 종이의 크기
    int N;
    //그물의 길이
    int L;
    //물고기의 개수
    int M;
    scanf("%d %d %d", &N, &L, &M);

    for (int i=0; i<M; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        fish.push_back({r, c});
        rows.insert(r);
        cols.insert(c);
    } //i loop

    int result = 0;
    //dr: 그물의 세로 길이
    //dc: 그물의 가로 길이
    for (int dr=1; dr<L/2; dr++) {
        int dc = L/2-dr;
        for (int r0:rows) {
            int r1 = r0+dr;
            //if (r1>N) continue;
            for (int c0:cols) {
                int c1 = c0+dc;
                //if (c1>N) continue;
                result = max(result, numFishIn(r0, r1, c0, c1));
            } //c0 loop
        } //r0 loop
    } //dr loop

    printf("%d", result);
    return 0;
}
