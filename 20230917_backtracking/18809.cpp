#include <bits/stdc++.h>

using namespace std;


int numRows; //정원의 행의 개수
int numCols; //정원의 열의 개수
int numGreens; //녹색 배양액 수
int numReds; //적색 배양액 수
int optResult = 0; //피울 수 있는 꽃의 개수
int gardenInput[50][50]; //정원 입력값 (배양액을 뿌리지 않은 초기 상태를 저장한다.)
//0: 호수
//1: 배양액을 뿌릴 수 없는 땅
//2: 배양액을 뿌릴 수 있는 땅

int garden[50][50]; //정원 (배양액이 뿌려져서 번져나가는 상태를 저장한다.)
//0: 호수 (배양액이 번질 수 없다.)
//1: 배양액을 뿌릴 수 없는 땅 (배양액이 번지지 않은 상태)
//2: 배양액을 뿌릴 수 있는 땅 (배양액이 뿌려지거나 번지지 않은 상태)
//3: 이제 막 번진 녹색 배양액이 있는 땅 (이 땅에 적색 배양액이 번지면 꽃이 피고, 그렇지 않은 경우 5번으로 상태가 변한다.)
//4: 이제 막 번진 적색 배양액이 있는 땅 (이 땅에 녹색 배양액이 번지면 꽃이 피고, 그렇지 않은 경우 6번으로 상태가 변한다.)
//5: 녹색 배양액이 점령한 땅 (이 땅에는 다른 배양액이 넘어오지 않는다. 상하좌우에 1번, 2번 칸이 있는 경우 해당 칸을 3번으로, 4번 칸이 있는 경우 해당 칸을 7번으로 변화시킨다.)
//6: 적색 배양액이 점령한 땅 (이 땅에는 다른 배양액이 넘어오지 않는다. 상하좌우에 1번, 2번 칸이 있는 경우 해당 칸을 4번으로, 3번 칸이 있는 경우 해당 칸을 7번으로 변화시킨다.)
//7: 꽃이 핀 땅 (이 땅에는 다른 배양액이 넘어오지 않는다.)

int dRow[] = {0, 1, 0, -1};
int dCol[] = {1, 0, -1, 0};
int numSelectedGreens; //정원에 실제로 뿌려진 녹색 배양액 수 (이 값이 numGreens와 다를 경우 BFS를 진행하지 않는다.)
int numSelectedReds; //정원에 실제로 뿌려진 적색 배양액 수 (이 값이 numReds와 다를 경우 BFS를 진행하지 않는다.)
vector<pair<int, int>> possibleSquares; //배양액을 뿌릴 수 있는 땅 목록
char colours[10] = {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}; //배양액을 뿌릴 수 있는 땅에 대해 실제로 뿌려진 배양액 색
//'O': 배양액이 뿌려지지 않음
//'G': 녹색 배양액
//'R': 적색 배양액

//함수 프로토타입
void BFS();


//배양액을 뿌리는 방법에 대해 반복을 수행한다.
//depth: 배양액을 뿌릴 수 있는 땅 목록 내 인덱스
void backtrack(int depth) {
    //베이스 케이스
    if (depth==possibleSquares.size()) {
        if (numSelectedGreens==numGreens && numSelectedReds==numReds) {
            BFS();
        }
        return;
    }

    if (numSelectedGreens<numGreens) { //녹색 배양액이 남은 경우-
        colours[depth] = 'G';
        numSelectedGreens++;
        backtrack(depth+1);
        colours[depth] = 'O';
        numSelectedGreens--;
    }

    if (numSelectedReds<numReds) { //적색 배양액이 남은 경우-
        colours[depth] = 'R';
        numSelectedReds++;
        backtrack(depth+1);
        colours[depth] = 'O';
        numSelectedReds--;
    }

    if (depth-numSelectedGreens-numSelectedReds<possibleSquares.size()-numGreens-numReds) {
        backtrack(depth+1); //설령 배양액이 남았더라도 이후에 등장하는 [배양액을 뿌릴 수 있는 땅]에 배양액을 뿌리는 경우를 고려할 필요가 있다.
    }
}

//주어진 곳에 배양액을 뿌려서 피어나는 꽃의 개수를 헤아린다.
//필요에 따라 optResult를 갱신한다.
void BFS() {
    //a. garden <- gardenInput (정원 데이터를 입력받는다.)
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            garden[row][col] = gardenInput[row][col];
        } //col loop
    } //row loop

    //b. 주어진 곳에 배양액을 뿌린다.
    queue<pair<int, int>> qGreens; //녹색 배양액이 퍼져나가는 현상을 구현하기 위한 큐
    queue<pair<int, int>> qReds; //적색 배양액이 퍼져나가는 현상을 구현하지 위한 큐
    for (int i=0; i<possibleSquares.size(); i++) {
        switch (colours[i]) {
            case 'G':
                garden[possibleSquares[i].first][possibleSquares[i].second] = 5;
                qGreens.push(possibleSquares[i]);
                break;
            case 'R':
                garden[possibleSquares[i].first][possibleSquares[i].second] = 6;
                qReds.push(possibleSquares[i]);
                break;
        }
    } //i loop

    int currentResult = 0; //피어난 꽃의 개수
    set<pair<int, int>> code3Squares; //이제 막 번진 녹색 배양액이 있는 영역 집합
    set<pair<int, int>> code4Squares; //이제 막 번진 적색 배양액이 있는 영역 집합

    while (!qGreens.empty() && !qReds.empty()) {

        //c. 녹색 큐에서 원소를 하나 꺼내어 상하좌우 가능한 칸에 퍼져 나가는 처리를 한다.
        //녹색 배양액이 점령한 땅 전부에 대해 퍼져 나가는 처리를 해야 하므로 여기도 반복이 필요하다.
        while (!qGreens.empty()) {
            pair<int, int> currentSquare = qGreens.front();
            qGreens.pop();
            for (int dir=0; dir<4; dir++) {
                int nRow = currentSquare.first+dRow[dir];
                int nCol = currentSquare.second+dCol[dir];
                if (nRow<0 || nRow>=numRows || nCol<0 || nCol>=numCols) //out of bounds
                    continue;
                switch (garden[nRow][nCol]) {
                    case 0: //호수
                    case 5: //녹색 배양액이 점령한 땅
                    case 6: //적색 배양액이 점령한 땅
                    case 7: //꽃이 핀 땅
                        continue;
                    case 4: //이제 막 번진 적색 배양액이 있는 땅 (녹색 큐에서 원소를 먼저 뽑았으므로 사실 이 경우는 존재하면 안된다.)
                        code4Squares.erase({nRow, nCol});
                        garden[nRow][nCol] = 7;
                        currentResult++;
                        break;
                    default:
                        code3Squares.insert({nRow, nCol});
                        garden[nRow][nCol] = 3;
                        break;
                } //switch-case
            } //direction loop
        } //while loop (until qGreens become empty)


        //d. 적색 큐에서 원소를 하나 꺼내어 상하좌우 가능한 칸에 퍼져나가는 처리를 한다.
        //적색 배양액이 점령한 땅 전부에 대해 퍼져나가는 처리를 해야 하므로 여기도 반복이 필요하다.
        while (!qReds.empty()) {
            pair<int, int> currentSquare = qReds.front();
            qReds.pop();
            for (int dir=0; dir<4; dir++) {
                int nRow = currentSquare.first+dRow[dir];
                int nCol = currentSquare.second+dCol[dir];
                if (nRow<0 || nRow>=numRows || nCol<0 || nCol>=numCols) //out of bounds
                    continue;
                switch (garden[nRow][nCol]) {
                    case 0: //호수
                    case 5: //녹색 배양액이 점령한 땅
                    case 6: //적색 배양액이 점령한 땅
                    case 7: //꽃이 핀 땅
                        continue;
                    case 3: //이제 막 번진 녹색 배양액이 있는 땅
                        code3Squares.erase({nRow, nCol});
                        garden[nRow][nCol] = 7;
                        currentResult++;
                        break;
                    default:
                        code4Squares.insert({nRow, nCol});
                        garden[nRow][nCol] = 4;
                        break;
                }
            } //direction loop
        } //while loop (until qReds become empty)

        //e. 배양액이 이제 막 퍼졌는데 꽃을 피우지 못한 영역이 있는지 조사한다.
        //녹색 배양액의 경우 3->5로 상태를 변화시키고 qGreens에 해당 칸을 넣는다.
        //적색 배양액의 경우 4->6으로 상태를 변화시키고 qReds에 해당 칸을 넣는다.
        //3과 4 상태에서는 아직 꽃을 피울 수 있는 가능성이 있기 때문에 5와 6 상태로 변경한 다음에 큐에 넣어야 한다.
        /*
        for (int row=0; row<numRows; row++) {
            for (int col=0; col<numCols; col++) {
                switch (garden[row][col]) {
                    case 3: //이제 막 번진 녹색 배양액의 경우-
                        garden[row][col] = 5;
                        qGreens.push({row, col});
                        break;
                    case 4: //이제 막 번진 적색 배양액의 경우-
                        garden[row][col] = 6;
                        qReds.push({row, col});
                        break;
                }
            } //col loop
        } //row loop
        */
        for (pair<int, int> square:code3Squares) {
            garden[square.first][square.second] = 5;
            qGreens.push(square);
        }
        code3Squares.clear();
        for (pair<int, int> square:code4Squares) {
            garden[square.first][square.second] = 6;
            qReds.push(square);
        }
        code4Squares.clear();
    } //while loop (녹색 큐, 적색 큐 중 하나라도 비게 되면 반복을 종료한다.)

    //f. 새롭게 배양액을 뿌린 결과 기존의 방법보다 꽃이 더 많이 핀 경우, optResult를 갱신한다.
    if (currentResult>optResult) {
        //cout << "LOG:::::::\n";
        //for (char colour:colours) {
        //    cout << colour << ' ';
        //}
        //cout << '\n' << currentResult << '\n';
        //cout << "LOG:::::::\n";
        optResult = currentResult;
    }
}





int main() {
    cin >> numRows >> numCols >> numGreens >> numReds;
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            cin >> gardenInput[row][col];
            if (gardenInput[row][col]==2) { //배양액을 뿌릴 수 있는 땅의 경우-
                possibleSquares.push_back({row, col}); //배양액을 뿌릴 수 있는 땅 목록에 추가한다.
            }
        } //col loop
    } //row loop

    //배양액을 뿌리는 방법에 대해 반복을 수행한다.
    backtrack(0);

    cout << optResult;
    return 0;
}
