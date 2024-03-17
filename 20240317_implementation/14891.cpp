#include <stdio.h>
#include <vector>
#define CLOCKWISE 1
#define COUNTER_CLOCKWISE -1
#define NONE 0
#define SOUTH 49
#define NORTH 48

using namespace std;

// �� ȸ���� ���� ȸ�� ��ų ����� �ε���
int gearIndices[101];
// �� ȸ���� ����
int directionCodes[101];

/**
 * ��� ������ �ִ� �ڼ� ��
 * gears[i][j]:= i ��° ��� ������ j ��° ��Ͽ� �ִ� �ڼ� ��
 */
char gears[4][9];

/**
 * �Է¹��� ȸ�� ������ �ݴ� ������ ��ȯ�Ѵ�.<br/>
 * �Է¹��� ȸ�� ������ NONE�� ��� NONE�� ��ȯ�Ѵ�.
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
 * Ư�� ��ġ�� ��� ���� �ϳ��� ȸ����Ų��.
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
 * �� ��Ϲ����� 12�� ������ S������ ���θ� �Ǻ��Ͽ� �̸� ������ ��Ÿ����.
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
 * ��Ϲ��� ���� �ε����� ���� �� ��Ϲ����� ���� ���� �ٸ��� ���θ� ��ȯ�Ѵ�.<br/>
 * �ε��� 0: �ε��� 0�� ��Ϲ����� �ε��� 1�� ��Ϲ����� ���� ���� �ٸ��� ���θ� ��´�.<br/>
 * �ε��� 1: �ε��� 1�� ��Ϲ����� �ε��� 2�� ��Ϲ����� ���� ���� �ٸ��� ���θ� ��´�.<br/>
 * �ε��� 2: �ε��� 2�� ��Ϲ����� �ε��� 3�� ��Ϲ����� ���� ���� �ٸ��� ���θ� ��´�.
 */
vector<bool> _checkOppositePoles() {
    vector<bool> result;
    for (int i=0; i<3; i++) {
        result.push_back(gears[i][2]!=gears[i+1][6]);
    }
    return result;
}

/**
 * 4 ���� ��� ������ ������ ü�ο��� ��� ���� �ϳ��� ȸ����Ų��.
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
