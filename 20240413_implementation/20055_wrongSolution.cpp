#include <bits/stdc++.h>
#include <stdio.h>
#define _generationNumber first
#define _cellNumber second

using namespace std;

// 현재 세대 수(번호)
int currentGenerationNumber = 0;

// 컨베이어 벨트의 길이
int beltLength;

// 컨베이어 벨트 각 칸의 내구도(인덱스 0번이 로봇을 올리는 곳, 인덱스 beltLength-1이 로봇을 내리는 곳, 인덱스 2*beltLength-1에서는 인덱스 0번으로 이동
int durability[201];

//컨베이어 벨트가 한 칸 이동할 때 내구도 이동을 구헌하기 위한 임시 배열
int tmpDurability[201];

// 컨베이어 벨트 내구도가 0이 된 칸의 개수
int numBrokenCells = 0;

// 컨베이어 벨트 내구도가 0이 된 칸의 개수 상한치
int numBrokenCellsLimit;

// 컨베이어 벨트 각 칸에 올라간 로봇의 개수
int numRobots[201];

// 해당 움직임을 적용하기 전의 로봇 집합
set<pair<int, int>> robotsBefore;

// 해당 움직임을 적용한 후의 로봇 집합
set<pair<int, int>> robotsAfter;

/**
    새로운 로봇을 컨베이어 벨트에 올린다.
    만약 로봇을 컨베이어 벨트에 올릴 수 없는 경우 false를 반환한다.
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
    해당 로봇을 오른쪽으로 한 칸 이동시킨다.
    만약 로봇이 오른쪽으로 한 칸 이동할 수 없는 경우 false를 반환한다.
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
    //step a. 현재 세대 수를 1 증가시킨다.
    currentGenerationNumber++;

    //step b. 컨베이어 벨트가 한 칸 이동한다. (로봇 이동 후 내구도 shift를 수행한다.)
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

    //step c. 로봇이 한 칸 이동한다.
    robotsAfter.clear();
    for (pair<int, int> robot:robotsBefore)
        moveCell(robot);
    robotsBefore.clear();
    for (pair<int, int> robot:robotsAfter)
        robotsBefore.insert(robot);

    //step d. 새 로봇을 0번 칸에 올린다.
    loadNewRobot();

    //step e. 이 작업 후 내구도가 상한을 넘지 않으면 true를 반환한다.
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
