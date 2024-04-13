#include <bits/stdc++.h>
#include <stdio.h>
#define _generationNumber first
#define _cellNumber second

using namespace std;

// ���� ���� ��(��ȣ)
int currentGenerationNumber = 0;

// �����̾� ��Ʈ�� ����
int beltLength;

// �����̾� ��Ʈ �� ĭ�� ������(�ε��� 0���� �κ��� �ø��� ��, �ε��� beltLength-1�� �κ��� ������ ��, �ε��� 2*beltLength-1������ �ε��� 0������ �̵�
int durability[201];

//�����̾� ��Ʈ�� �� ĭ �̵��� �� ������ �̵��� �����ϱ� ���� �ӽ� �迭
int tmpDurability[201];

// �����̾� ��Ʈ �������� 0�� �� ĭ�� ����
int numBrokenCells = 0;

// �����̾� ��Ʈ �������� 0�� �� ĭ�� ���� ����ġ
int numBrokenCellsLimit;

// �����̾� ��Ʈ �� ĭ�� �ö� �κ��� ����
int numRobots[201];

// �ش� �������� �����ϱ� ���� �κ� ����
set<pair<int, int>> robotsBefore;

// �ش� �������� ������ ���� �κ� ����
set<pair<int, int>> robotsAfter;

/**
    ���ο� �κ��� �����̾� ��Ʈ�� �ø���.
    ���� �κ��� �����̾� ��Ʈ�� �ø� �� ���� ��� false�� ��ȯ�Ѵ�.
*/
bool loadNewRobot() {
    if (durability[0]==0)
        return false;
    durability[0]--;
    numRobots[0]++;
    robotsBefore.insert({currentGenerationNumber, 0});
    if (durability[0]==0)
        numBrokenCells++;
    return true;
}


/**
    �ش� �κ��� ���������� �� ĭ �̵���Ų��.
    ���� �κ��� ���������� �� ĭ �̵��� �� ���� ��� false�� ��ȯ�Ѵ�.
*/
bool moveCell(pair<int, int> robot) {
    int newCellNumber = (robot._cellNumber+1)%(2*beltLength);
    if (numRobots[newCellNumber]!=0 || durability[newCellNumber]==0) {
        robotsAfter.insert(robot);
        return false;
    }
    numRobots[robot._cellNumber]--;
    durability[newCellNumber]--;
    if (newCellNumber!=beltLength-1) {
        numRobots[newCellNumber]++;
        robotsAfter.insert({robot._generationNumber, newCellNumber});
    }
    if (durability[newCellNumber]==0)
        numBrokenCells++;
    return true;
}

bool procedure() {
    //step a. ���� ���� ���� 1 ������Ų��.
    currentGenerationNumber++;

    //step b. �����̾� ��Ʈ�� �� ĭ �̵��Ѵ�. (�κ� �̵� �� ������ shift�� �����Ѵ�.)
    robotsAfter.clear();
    for (pair<int, int> robot:robotsBefore) {
        numRobots[robot._cellNumber]--;
        pair<int, int> robotMoved = {robot._generationNumber, robot._cellNumber+1};
        if (robotMoved._cellNumber!=beltLength-1) {
            numRobots[robotMoved._cellNumber]++;
            robotsAfter.insert(robotMoved);
        }
    } //robot loop
    robotsBefore.clear();
    for (pair<int, int> robot:robotsAfter)
        robotsBefore.insert(robot);

    for (int i=0; i<2*beltLength-1; i++)
        tmpDurability[i+1] = durability[i];
    tmpDurability[0] = durability[2*beltLength-1];
    for (int i=0; i<2*beltLength; i++)
        durability[i] = tmpDurability[i];

    //step c. �κ��� �� ĭ �̵��Ѵ�.
    robotsAfter.clear();
    for (pair<int, int> robot:robotsBefore)
        moveCell(robot);
    robotsBefore.clear();
    for (pair<int, int> robot:robotsAfter)
        robotsBefore.insert(robot);

    //step d. �� �κ��� 0�� ĭ�� �ø���.
    loadNewRobot();

    //step e. �� �۾� �� �������� ������ ���� ������ true�� ��ȯ�Ѵ�.
    return numBrokenCells<numBrokenCellsLimit;
}

int main() {
    scanf("%d %d", &beltLength, &numBrokenCellsLimit);
    for (int i=0; i<beltLength*2; i++) {
        scanf("%d", &durability[i]);
    }
    while(procedure());
    printf("%d", currentGenerationNumber);
    return 0;
}
