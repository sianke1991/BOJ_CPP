#include <stdio.h>
#include <vector>
#define CLOCKWISE 1
#define COUNTER_CLOCKWISE -1
#define NONE 0
#define SOUTH 49
#define NORTH 48

using namespace std;

// 각 회전에 대해 회전 시킬 기어의 인덱스
int gearIndices[101];
// 각 회전에 대해
int directionCodes[101];

/**
 * 톱니 바퀴에 있는 자석 극
 * gears[i][j]:= i 번째 톱니 바퀴의 j 번째 톱니에 있는 자석 극
 */
char gears[4][9];

/**
 * 입력받은 회전 방향의 반대 방향을 반환한다.<br/>
 * 입력받은 회전 방향이 NONE일 경우 NONE을 반환한다.
 */
int reverseDirectionOf(int directionCode) {
    switch (directionCode) {
        case CLOCKWISE:
            return COUNTER_CLOCKWISE;
        case COUNTER_CLOCKWISE:
            return CLOCKWISE;
        case NONE: default:
            return NONE;
    }
}

/**
 * 특정 위치의 톱니 바퀴 하나를 회전시킨다.
 */
void rotateGearAt(int gearIndex, int directionCode) {
    switch (directionCode) {
        case CLOCKWISE: {
            int tmp = gears[gearIndex][7];
            for (int i=6; i>=0; i--)
                gears[gearIndex][i+1] = gears[gearIndex][i];
            gears[gearIndex][0] = tmp;
            break;
        }
        case COUNTER_CLOCKWISE: {
            int tmp = gears[gearIndex][0];
            for (int i=0; i<7; i++)
                gears[gearIndex][i] = gears[gearIndex][i+1];
            gears[gearIndex][7] = tmp;
            break;
        }
        case NONE: {
            break;
        }
    }
}

/**
 * 각 톱니바퀴의 12시 방향이 S극인지 여부를 판별하여 이를 정수로 나타낸다.
 */
int point() {
    int result = 0;
    if (gears[0][0]==SOUTH) result+=1;
    if (gears[1][0]==SOUTH) result+=2;
    if (gears[2][0]==SOUTH) result+=4;
    if (gears[3][0]==SOUTH) result+=8;
    return result;
}

/**
 * 톱니바퀴 사이 인덱스에 따른 두 톱니바퀴의 극이 서로 다른지 여부를 반환한다.<br/>
 * 인덱스 0: 인덱스 0의 톱니바퀴와 인덱스 1의 톱니바퀴의 극이 서로 다른지 여부를 담는다.<br/>
 * 인덱스 1: 인덱스 1의 톱니바퀴와 인덱스 2의 톱니바퀴의 극이 서로 다른지 여부를 담는다.<br/>
 * 인덱스 2: 인덱스 2의 톱니바퀴와 인덱스 3의 톱니바퀴의 극이 서로 다른지 여부를 담는다.
 */
vector<bool> _checkOppositePoles() {
    vector<bool> result;
    for (int i=0; i<3; i++) {
        result.push_back(gears[i][2]!=gears[i+1][6]);
    }
    return result;
}

/**
 * 4 개의 톱니 바퀴로 구성된 체인에서 톱니 바퀴 하나를 회전시킨다.
 */
void rotateGearChainAt(int gearIndex, int directionCode) {
    gearIndex--;
    vector<int> directions = {0, 0, 0, 0};
    directions[gearIndex] = directionCode;
    vector<bool> checkOppositePoles = _checkOppositePoles();
    switch (gearIndex) {
        case 0: {
            directions[1] = checkOppositePoles[0] ? reverseDirectionOf(directions[0]) : NONE;
            directions[2] = checkOppositePoles[1] ? reverseDirectionOf(directions[1]) : NONE;
            directions[3] = checkOppositePoles[2] ? reverseDirectionOf(directions[2]) : NONE;
            break;
        }
        case 1: {
            directions[0] = checkOppositePoles[0] ? reverseDirectionOf(directions[1]) : NONE;
            directions[2] = checkOppositePoles[1] ? reverseDirectionOf(directions[1]) : NONE;
            directions[3] = checkOppositePoles[2] ? reverseDirectionOf(directions[2]) : NONE;
            break;
        }
        case 2: {
            directions[1] = checkOppositePoles[1] ? reverseDirectionOf(directions[2]) : NONE;
            directions[0] = checkOppositePoles[0] ? reverseDirectionOf(directions[1]) : NONE;
            directions[3] = checkOppositePoles[2] ? reverseDirectionOf(directions[2]) : NONE;
            break;
        }
        case 3: {
            directions[2] = checkOppositePoles[2] ? reverseDirectionOf(directions[3]) : NONE;
            directions[1] = checkOppositePoles[1] ? reverseDirectionOf(directions[2]) : NONE;
            directions[0] = checkOppositePoles[0] ? reverseDirectionOf(directions[1]) : NONE;
            break;
        }
    } //switch gearIndex

    for (int i=0; i<4; i++)
        rotateGearAt(i, directions[i]);
}

int main() {
    scanf("%s", gears[0]);
    scanf("%s", gears[1]);
    scanf("%s", gears[2]);
    scanf("%s", gears[3]);
    int numRotates;
    scanf("%d", &numRotates);
    for (int i=0; i<numRotates; i++) {
        scanf("%d %d", &gearIndices[i], &directionCodes[i]);
    }
    for (int i=0; i<numRotates; i++) {
        rotateGearChainAt(gearIndices[i], directionCodes[i]);
    }
    printf("%d", point());
    return 0;
}
