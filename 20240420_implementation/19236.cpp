#include <bits/stdc++.h>
#include <stdio.h>
#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_DIRS 8
#define MIN_FISH_NUMBER 1
#define MAX_FISH_NUMBER 16

using namespace std;
/*

    a. 각 칸을 나타내는 방법: 기본적으로 10진법 두 자리 자연수를 사용하되, 경계를 벗어나는 칸은 -1로 나타낸다.
a.a.   10진법 두 자리 자연수 중 십의 자리는 행 번호,
a.b.   10진법 두 자리 자연수 중 일의 자리는 열 번호를 나타낸다.

    b. 물고기를 나타내는 방법: 10진법 네 자리 자연수를 사용한다.
b.a.   10진법 네 자리 자연수 중 천의 자리는 0으로 고정한다.
b.b.   10진법 네 자리 자연수 중 백, 십의 두 자리는 물고기 번호를 나타낸다. (1 이상 16 이하)
b.c.   10진법 네 자리 자연수 중 일의 자리는 물고기 방향을 나타낸다. (1 이상 8 이하)
  e.g. 8번 물고기의 방향이 5일 경우 해당 물고기는 십진법으로 0085로 나타낸다. (=물고기 번호*10+물고기 방향)

    d. 현재 상태를 나타내는 방법: 각 상태는 각 칸에 있는 물고기/빈칸 정보(빈 칸은 0으로 표현)
       지금까지 잡은 물고기 번호 합, 상어의 위치 및 상어의 방향으로 나타낸다.
*/

const int dRow[] = {-1, -1, -1, 0, 1, 1, 1, 0, -1};
const int dCol[] = {1, 0, -1, -1, -1, 0, 1, 1, 1};

struct State {
    map<int, int> grid; //각 칸에 있는 생선 정보. key는 칸의 번호, value는 생선의 정보
    int point;
    int sharkSquare;
    int sharkDirection;
};


int rowNumberOf(int square) {
    return square/10;
}

int colNumberOf(int square) {
    return square%10;
}

int squareOf(int rowNumber, int colNumber) {
    return rowNumber*10+colNumber;
}

int fishNumberOf(int fish) {
    return fish/10;
}

int fishOf(int fishNumber, int direction) {
    return fishNumber*10+direction;
}

int fishDirectionOf(int fish) {
    return fish%10;
}

int resetFishDirection(int fish, int nDirection) {
    return fishOf(fishNumberOf(fish), nDirection);
}

bool checkFish(int number) {
    return number;

}

// 상어가 잡은 물고기 번호 합의 최대치
int optPoint = 0;

/**
 * 입력받은 방향으로 이웃한 칸을 반환한다.
 * 입력받은 방향으로 이웃한 칸이 경계를 벗어나는 경우 -1을 반환한다.
 */
int nextSquareIn(int direction, int currentSquare) {
    int nRow = rowNumberOf(currentSquare)+dRow[direction];
    int nCol = colNumberOf(currentSquare)+dCol[direction];
    if (nRow<0 || nRow>=NUM_ROWS || nCol<0 || nCol>=NUM_COLS)
        return -1;
    else
        return squareOf(nRow, nCol);
}

/**
 * 입력받은 방향에 위치한 칸 목록을 반환한다.
 * 입력받은 방향에 칸이 없는 경우 빈 목록을 반환한다.
 */
vector<int> squaresIn(int direction, int currentSquare) {
    vector<int> result;
    int nextSquare = currentSquare;
    while (1) {
        nextSquare = nextSquareIn(direction, nextSquare);
        if (nextSquare<0)
            return result;
        result.push_back(nextSquare);
    }
}

/**
 * 입력받은 상태에서 상어가 갈 수 있는 칸 목록을 반환한다.
 * 상어가 갈 수 있는 칸이 없는 경우 빈 목록을 반환한다.
 */
vector<int> possibleSharkDestinations(State state) {
    vector<int> result;
    for (int square:squaresIn(state.sharkDirection, state.sharkSquare)) {
        if (checkFish(state.grid[square])) {
            result.push_back(square);
        }
    }
    return result;
}

/**
 * 입력받은 상태에서 물고기가 규칙에 맞게 움직인다.
 */
void fishMove(State& state) {
    for (int fishNumber=MIN_FISH_NUMBER; fishNumber<=MAX_FISH_NUMBER; fishNumber++) {
        for (pair<int, int> entry:state.grid) {
            int fish = entry.second;
            if (fishNumberOf(fish)!=fishNumber) //현재 보고 있는 칸의 물고기의 번호가 현재 찾고 있는 번호가 아닌 경우
                continue;
            int currentSquare = entry.first;
            for (int dDir=0; dDir<NUM_DIRS; dDir++) {
                int nDir = (fishDirectionOf(fish)+dDir)%NUM_DIRS;
                int nextSquare = nextSquareIn(nDir, currentSquare);
                if (nextSquare<0) //해당 방향으로 한 칸 이동할 때 경계를 벗어나는 경우
                    continue;
                if (nextSquare==state.sharkSquare) //해당 방향으로 한 칸 이동할 때 상어를 만나게 되는 경우
                    continue;

                //해당 방향으로 한 칸 이동이 가능한 경우
                //그 방향으로 몸을 회전한 다음
                //해당 칸과 이웃한 칸의 값을 서로 바꾼다.
                state.grid[currentSquare] = resetFishDirection(fish, nDir);
                int tmp = state.grid[nextSquare];
                state.grid[nextSquare] = state.grid[currentSquare];
                state.grid[currentSquare] = tmp;
                break; //해당 방향으로 이동을 했다면 다른 방향으로 이동할 필요가 없다.
            } //dDir loop (물고기의 현재 방향으로 움직일 수 없는 경우 45도 회전하는 것을 구현하기 위한 loop)
            break; //해당 물고기가 자리를 변경했으므로, 다른 칸에서 해당 물고기를 다시 찾아서 다시 자리를 변경하는 우를 범하지 않도록 entry loop를 빠져나간다.
        } //entry loop
    } //fishNumber loop
}

/**
 * 입력받은 상태에서 상어가 입력받은 칸으로 이동한다.
 */
void sharkMove(State& state, int sharkDestination) {
    //printf("log::::: state.point: %d, sharkDestination: %d\n", state.point, sharkDestination);
    int fishAtDestination = state.grid[sharkDestination];
    //printf("log:::::: fishAtDestination: %d\n", fishAtDestination);
    state.sharkSquare = sharkDestination;
    state.sharkDirection = fishDirectionOf(fishAtDestination);
    state.point += fishNumberOf(fishAtDestination);
    if (optPoint<state.point) {
        optPoint = state.point;
        //printf("log::::: optPoint: %d\n", optPoint);
    }
    state.grid.erase(sharkDestination);
    //printf("log::::::=======\n");
}


int main() {
    State stateInput;
    for (int row=0; row<NUM_ROWS; row++) {
        for (int col=0; col<NUM_COLS; col++) {
            int fishNumber;
            int fishDirection;
            scanf("%d %d", &fishNumber, &fishDirection);
            stateInput.grid[squareOf(row, col)] = fishOf(fishNumber, fishDirection);
        } //col loop
    } //row loop
    stateInput.point = 0;

    //맨 처음에 상어는 0행 0열 칸에 들어간다.
    sharkMove(stateInput, squareOf(0, 0));
    //규칙에 따라 물고기가 움직인다.
    fishMove(stateInput);

    queue<State> q;
    q.push(stateInput);

    while (!q.empty()) {
        State currentState = q.front();
        q.pop();
        vector<int> sharkDestinations = possibleSharkDestinations(currentState);
        for (int sharkDestination:sharkDestinations) {
            State nextState = currentState;
            sharkMove(nextState, sharkDestination);
            fishMove(nextState);
            q.push(nextState);
        } //sharkDestination loop
    } //while loop
    printf("%d", optPoint);
    return 0;
}
