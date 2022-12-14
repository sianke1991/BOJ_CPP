#include <bits/stdc++.h> //여러 헤더 파일을 한 번에 인클루드 한다.
#define HEIGHT first
#define WIDTH second

using namespace std;

int dHeight[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dWidth[8]  = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    vector<int> answer;
    while (1) {
        int width, height;
        cin >> width >> height;
        if (width==0 && height==0)
            break;
        bool isLand[51][51] = {false};
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                int terrain;
                cin >> terrain;
                isLand[i][j] = (terrain==0) ? false : true;
            } //j loop
        } //i loop

        int numConnectedComponents = 0;
        for (int oHeight=0; oHeight<height; oHeight++) {
            for (int oWidth=0; oWidth<width; oWidth++) {
                //BFS 시작 조건
                if (isLand[oHeight][oWidth]) {
                    numConnectedComponents++;
                    queue<pair<int, int>> q;
                    isLand[oHeight][oWidth] = false;
                    q.push({oHeight, oWidth});
                    while (!q.empty()) {
                        pair<int, int> curNode = q.front();
                        q.pop();
                        for (int dir=0; dir<8; dir++) {
                            int nHeight = curNode.HEIGHT+dHeight[dir];
                            int nWidth = curNode.WIDTH+dWidth[dir];
                            if (nHeight<0 || nHeight>=height || nWidth<0 || nWidth>=width) continue; //out of bounds
                            if (!isLand[nHeight][nWidth]) continue; //invalid position or position that has visited already
                            isLand[nHeight][nWidth] = false;
                            q.push({nHeight, nWidth});
                        } //directional loop
                    } //BFS loop
                } //BFS 시작 조건
            } //oWidth loop
        } //oHeight loop
        answer.push_back(numConnectedComponents);
    } //전체 반복문
    for (int numConnectedComponents:answer) {
        cout << numConnectedComponents << '\n';
    }
}
