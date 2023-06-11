#include <bits/stdc++.h>

using namespace std;

const int INFINITE_DIST = 100000000;
const int numNodes = 5;
int adjMatrix[numNodes+1][numNodes+1];
int nxtMatrix[numNodes+1][numNodes+1];
string pathMatrix[numNodes+1][numNodes+1]; //pathMatrix[s][t]: s에서 t를 가기 위해 거쳐야 할 경로
int pathLengthMatrix[numNodes+1][numNodes+1]; //pathLengthMatrix[s][t]: s에서 t를 가기 위해 거쳐할 노드 개수

/**
 * from에서 to로 가기 위해 거쳐야 할 경로를 반환한다.<br/>
 * 계산 중 pathMatrix의 내용을 참조하고 갱신한다.<br/>
 * 이 함수 호출 전 priceMatrix, nxtMatrix는 전부 완성되어있어야 한다.
 */
string path(int from, int to) {
    if (from==to || pathMatrix[from][to] >= INFINITE_DIST) { //from에서 to로 가는 것이 불가능한 경우 아무리 재귀 호출을 하더라도 재귀 호출이 종료되지 않는다.
                                                            //즉, from에서 to로 가는 것이 불가능한 경우 재귀 호출을 막아야 한다. from에서 to로 가는 것이 불가능한지
                                                            //여부 판단은 adjMatrix[from][to]을 사용하여 할 수 있다. 즉, adjMatrix[from][to]가 INFINITE_DIST 이상인 경우
                                                            //from에서 to로 가는 것이 불가능하다고 판단할 수 있다.
        pathMatrix[from][to] = "";
        return "";
    }
    if (pathMatrix[from][to]!="") { //from에서 to로 가는 경로를 이미 구한 경우 pathMatrix에 저장된 값을 그대로 반환한다. (메모이제이션)
        return pathMatrix[from][to];
    } else {
        int mid = nxtMatrix[from][to]; //경유 노드
        if (mid==to) { //경유 노드가 도착 노드와 같은 경우 from에서 to로 직접 가는 것이 가장 빠른 것이다. (재귀 호출 종료 조건)
            pathMatrix[from][to] = to_string(from) + " " + to_string(to);
            pathLengthMatrix[from][to] = 2;
            return pathMatrix[from][to];
        } else { //경유 노드가 도착 노드와 다른 경우 from에서 mid를 거쳐서 to로 가야 한다. mid에서 to로 가는 경로는 재귀 호출을 통해서 구한다.
            pathMatrix[from][to] = to_string(from) + " "  + path(mid, to); //mid는 path(mid, to)의 일부이므로 to_string(mid)는 더하면 안된다.
            pathLengthMatrix[from][to] = 1 + pathLengthMatrix[mid][to]; //pathMatrix[from][to]는 pathMatrix[mid][to]의 앞에 from이 붙은 것이다. 즉, 경로 길이는
                                                                        //pathLengthMatrix[from][to]는 pathLengthMatrix[mid][to] 보다 1 큰 값이다.
            return pathMatrix[from][to];
        }
    }
}


int main() {

    for (int i=1; i<=numNodes; i++) {
        for (int j=1; j<=numNodes; j++) {
            adjMatrix[i][j] = INFINITE_DIST;
            nxtMatrix[i][j] = -1;
        }
        adjMatrix[i][i] = 0;
    }

    adjMatrix[1][2] = 4; adjMatrix[2][1] = 4;
    nxtMatrix[1][2] = 2; nxtMatrix[2][1] = 1; //s와 t가 직접 연결된 경우 nxtMatrix[s][t] = t로 설정한다.

    adjMatrix[1][3] = 1; adjMatrix[3][1] = 1;
    nxtMatrix[1][3] = 3; nxtMatrix[3][1] = 1;

    adjMatrix[1][4] = 1; adjMatrix[4][1] = 1;
    nxtMatrix[1][4] = 4; nxtMatrix[4][1] = 1;

    adjMatrix[2][5] = 8; adjMatrix[5][2] = 8;
    nxtMatrix[2][5] = 5; nxtMatrix[5][2] = 2;

    adjMatrix[3][4] = 3; adjMatrix[4][3] = 3;
    nxtMatrix[3][4] = 4; nxtMatrix[4][3] = 3;

    adjMatrix[3][5] = 15; adjMatrix[5][3] = 15;
    nxtMatrix[3][5] = 5; nxtMatrix[5][3] = 3;

    adjMatrix[4][5] = 6; adjMatrix[5][4] = 6;
    nxtMatrix[4][5] = 5; nxtMatrix[5][4] = 4;

    for (int k=1; k<=numNodes; k++) { //경유해야 할 노드 루프
        for (int s=1; s<=numNodes; s++) { //시작 노드
            for (int t=1; t<=numNodes; t++) { //도착 노드
                if (adjMatrix[s][t]>adjMatrix[s][k]+adjMatrix[k][t]) { //s에서 t로 갈 때 k 노드를 경유하는 것이 더 효율적일 때
                    adjMatrix[s][t] = adjMatrix[s][k]+adjMatrix[k][t]; //s에서 t로 갈 때 k 노드를 경유하도록 변경한다.
                    nxtMatrix[s][t] = nxtMatrix[s][k]; //s에서 t로 갈 때 k 노드를 경유하도록 변경한다.
                }
            } //t loop (도착 노드 루프)
        } //s loop (시작 노드 루프)
    } //k loop (경유 노드 루프)

    cout << "=====nxtMatrix=======\n";
    for (int i=1; i<=numNodes; i++) {
        for (int j=1; j<=numNodes; j++) {
            cout << nxtMatrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=====nxtMatrix=======\n";

    for (int s=1; s<=numNodes; s++) {
        for (int t=1; t<=numNodes; t++) {
            path(s, t);
        } //t loop (도착 노드 루프)
    } //s loop (시작 노드 루프)
    for (int s=1; s<=numNodes; s++) {
        for (int t=1; t<=numNodes; t++) {
            cout << "from " << s << " to " << t << ": ";
            cout << pathLengthMatrix[s][t] << ' ' << pathMatrix[s][t] << '\n';
        }
    }

    return 0;
}
