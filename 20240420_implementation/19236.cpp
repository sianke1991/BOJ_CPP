#include <bits/stdc++.h>
#include <stdio.h>
#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_DIRS 8
#define MIN_FISH_NUMBER 1
#define MAX_FISH_NUMBER 16

using namespace std;
/*

    a. �� ĭ�� ��Ÿ���� ���: �⺻������ 10���� �� �ڸ� �ڿ����� ����ϵ�, ��踦 ����� ĭ�� -1�� ��Ÿ����.
a.a.   10���� �� �ڸ� �ڿ��� �� ���� �ڸ��� �� ��ȣ,
a.b.   10���� �� �ڸ� �ڿ��� �� ���� �ڸ��� �� ��ȣ�� ��Ÿ����.

    b. ����⸦ ��Ÿ���� ���: 10���� �� �ڸ� �ڿ����� ����Ѵ�.
b.a.   10���� �� �ڸ� �ڿ��� �� õ�� �ڸ��� 0���� �����Ѵ�.
b.b.   10���� �� �ڸ� �ڿ��� �� ��, ���� �� �ڸ��� ����� ��ȣ�� ��Ÿ����. (1 �̻� 16 ����)
b.c.   10���� �� �ڸ� �ڿ��� �� ���� �ڸ��� ����� ������ ��Ÿ����. (1 �̻� 8 ����)
  e.g. 8�� ������� ������ 5�� ��� �ش� ������ ���������� 0085�� ��Ÿ����. (=����� ��ȣ*10+����� ����)

    d. ���� ���¸� ��Ÿ���� ���: �� ���´� �� ĭ�� �ִ� �����/��ĭ ����(�� ĭ�� 0���� ǥ��)
       ���ݱ��� ���� ����� ��ȣ ��, ����� ��ġ �� ����� �������� ��Ÿ����.
*/

const int dRow[] = {-1, -1, -1, 0, 1, 1, 1, 0, -1};
const int dCol[] = {1, 0, -1, -1, -1, 0, 1, 1, 1};

struct State {
    map<int, int> grid; //�� ĭ�� �ִ� ���� ����. key�� ĭ�� ��ȣ, value�� ������ ����
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

// �� ���� ����� ��ȣ ���� �ִ�ġ
int optPoint = 0;

/**
 * �Է¹��� �������� �̿��� ĭ�� ��ȯ�Ѵ�.
 * �Է¹��� �������� �̿��� ĭ�� ��踦 ����� ��� -1�� ��ȯ�Ѵ�.
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
 * �Է¹��� ���⿡ ��ġ�� ĭ ����� ��ȯ�Ѵ�.
 * �Է¹��� ���⿡ ĭ�� ���� ��� �� ����� ��ȯ�Ѵ�.
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
 * �Է¹��� ���¿��� �� �� �� �ִ� ĭ ����� ��ȯ�Ѵ�.
 * �� �� �� �ִ� ĭ�� ���� ��� �� ����� ��ȯ�Ѵ�.
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
 * �Է¹��� ���¿��� ����Ⱑ ��Ģ�� �°� �����δ�.
 */
void fishMove(State& state) {
    for (int fishNumber=MIN_FISH_NUMBER; fishNumber<=MAX_FISH_NUMBER; fishNumber++) {
        for (pair<int, int> entry:state.grid) {
            int fish = entry.second;
            if (fishNumberOf(fish)!=fishNumber) //���� ���� �ִ� ĭ�� ������� ��ȣ�� ���� ã�� �ִ� ��ȣ�� �ƴ� ���
                continue;
            int currentSquare = entry.first;
            for (int dDir=0; dDir<NUM_DIRS; dDir++) {
                int nDir = (fishDirectionOf(fish)+dDir)%NUM_DIRS;
                int nextSquare = nextSquareIn(nDir, currentSquare);
                if (nextSquare<0) //�ش� �������� �� ĭ �̵��� �� ��踦 ����� ���
                    continue;
                if (nextSquare==state.sharkSquare) //�ش� �������� �� ĭ �̵��� �� �� ������ �Ǵ� ���
                    continue;

                //�ش� �������� �� ĭ �̵��� ������ ���
                //�� �������� ���� ȸ���� ����
                //�ش� ĭ�� �̿��� ĭ�� ���� ���� �ٲ۴�.
                state.grid[currentSquare] = resetFishDirection(fish, nDir);
                int tmp = state.grid[nextSquare];
                state.grid[nextSquare] = state.grid[currentSquare];
                state.grid[currentSquare] = tmp;
                break; //�ش� �������� �̵��� �ߴٸ� �ٸ� �������� �̵��� �ʿ䰡 ����.
            } //dDir loop (������� ���� �������� ������ �� ���� ��� 45�� ȸ���ϴ� ���� �����ϱ� ���� loop)
            break; //�ش� ����Ⱑ �ڸ��� ���������Ƿ�, �ٸ� ĭ���� �ش� ����⸦ �ٽ� ã�Ƽ� �ٽ� �ڸ��� �����ϴ� �츦 ������ �ʵ��� entry loop�� ����������.
        } //entry loop
    } //fishNumber loop
}

/**
 * �Է¹��� ���¿��� �� �Է¹��� ĭ���� �̵��Ѵ�.
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

    //�� ó���� ���� 0�� 0�� ĭ�� ����.
    sharkMove(stateInput, squareOf(0, 0));
    //��Ģ�� ���� ����Ⱑ �����δ�.
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
