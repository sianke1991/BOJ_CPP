#include <stdio.h>

// 입력받는 값
int numInnings; //이닝 수
int expectedResult[51][9]; //expectedResult[p][i] := 선수 p가 이닝 i 때 기대되는 결과
// 백트래킹을 사용하여 선수들을 세우는 경우의 수를 고려한다.
// 백트래킹에 사용할 변수들-
bool used[9] = {true}; //0번 선수는 3번 타자로 고정된 상태 (각 선수가 칠 순서가 정해졌는지 여부)
int  order[9] = {-1, -1, -1, 0}; //0번 선수는 3번 타자로 고정된 상태 (인덱스 3번은 0번 선수로 고정)
long long maxPoint = -1LL;
// 각 선수가 칠 순서가 정해졌을 때 얻을 수 있는 점수를 계산하는 함수
// 계산 후 maxPoint를 갱신해야 한다.
void calculatePoint();

void printOrder() {
    for (int elem:order) {
        printf("%d ", elem);
    }
    puts("");
}

void recursive(int depth) {
    if (depth==9) {
        //printOrder();
        calculatePoint();
        //printf("%lld\n", maxPoint);
        return;
    } else if (depth==3) { //3번 타자는 0번 선수로 고정되어 있으므로 이 단계는 특별히 넘어가야 한다.
        return recursive(depth+1);
    } else {
        for (int playerNumber=0; playerNumber<9; playerNumber++) {
            if (used[playerNumber])
                continue;
            used[playerNumber] = true;
            order[depth] = playerNumber;
            recursive(depth+1);
            used[playerNumber] = false;
        } //playerNumber loop
    }
}

void calculatePoint() {
    int currentInning = 0, numOuts = 0;
    bool bases[4] = {false}; // 각 베이스에 선수가 있는지 여부-
    long long numHits = 0LL; //현재 타석에서 나온 선수 인원수-
    long long currentPoint = 0LL; //해당 순서로 얻을 수 있는 점수-
    while (currentInning<numInnings) {
        int currentPlayer = order[(int)(numHits%9)]; // 현재 타석에 들어온 선수 번호-
        //printf("currentInning: %d, currentPlayer: %d, currentPoint: %lld, numOuts: %d\n", currentInning, currentPlayer, currentPoint, numOuts);
        switch (expectedResult[currentInning][currentPlayer]) {
            case 1: {
                if (bases[3]) {
                    currentPoint++;
                    bases[3] = false;
                }
                if (bases[2]) {
                    bases[3] = true;
                    bases[2] = false;
                }
                if (bases[1]) {
                    bases[2] = true;
                    bases[1] = false;
                }
                bases[1] = true;
                break;
            }
            case 2: {
                if (bases[3]) {
                    currentPoint++;
                    bases[3] = false;
                }
                if (bases[2]) {
                    currentPoint++;
                    bases[2] = false;
                }
                if (bases[1]) {
                    bases[3] = true;
                    bases[1] = false;
                }
                bases[2] = true;
                break;
            }
            case 3: {
                if (bases[3]) {
                    currentPoint++;
                    bases[3] = false;
                }
                if (bases[2]) {
                    currentPoint++;
                    bases[2] = false;
                }
                if (bases[1]) {
                    currentPoint++;
                    bases[1] = false;
                }
                bases[3] = true;
                break;
            }
            case 4: {
                if (bases[3]) {
                    currentPoint++;
                    bases[3] = false;
                }
                if (bases[2]) {
                    currentPoint++;
                    bases[2] = false;
                }
                if (bases[1]) {
                    currentPoint++;
                    bases[1] = false;
                }
                currentPoint++;
                break;
            }
            case 0: {
                numOuts++;
                break;
            }
        } //switch expectedResult
        if (numOuts>=3) {
            currentInning++;
            numOuts = 0;
            //새로운 이닝이 들어오면 각 베이스를 정리해야 한다.
            bases[1] = false; bases[2] = false; bases[3] = false;
        }
        numHits++;
    } //while loop
    if (currentPoint>maxPoint)
        maxPoint = currentPoint;
}

int main() {
    scanf("%d", &numInnings);
    for (int inning=0; inning<numInnings; inning++) {
        for (int playerNumber=0; playerNumber<9; playerNumber++) {
            scanf("%d", &expectedResult[inning][playerNumber]);
        }
    }
    recursive(0);
    printf("%lld", maxPoint);
    return 0;
}
