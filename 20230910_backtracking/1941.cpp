#include <bits/stdc++.h>

using namespace std;
char studentAt[26];
set<string> possibleCombinationsSet; //가능한 "소문난 칠공주" 조합: 개수를 헤아릴 때 중복을 제거하기 위해 set을 사용한다.
bool isStudentSelected[25];
int startingIndexGlobal = 0;


int toLeft(int index) {
    if (index%5==0)
        return -1;
    return index-1;
}
int toRight(int index) {
    if (index%5==4)
        return -1;
    return index+1;
}
int toTop(int index) {
    int result = index-5;
    return result<0 ? -1 : result;
}
int toBottom(int index) {
    int result = index+5;
    return result>=25 ? -1 : result;
}

/**
 * 선택된 7 명의 여학생 중 4 명 이상이 이다솜파인지 여부를 확인한 후,
 * 그 경우에 possibleCombinationsSet에 넣는다.
 */
void validity() {
    int numSs = 0; //선택된 이다솜파 학생 수
    string elem = "";
    for (int index=0; index<25; index++) {
        if (!isStudentSelected[index])
            continue;
        if (studentAt[index]=='S')
            numSs++;
        elem += to_string(index) + "_";
    }
    if (numSs<4)
        return;
    possibleCombinationsSet.insert(elem);
}

/**
 * depth: 현재 선택된 학생의 수
 */
void backtrack(int depth) {
    if (depth==7) {
        validity();
        return;
    }
    for (int i=startingIndexGlobal+1; i<25; i++) { //새롭게 추가할 학생의 인덱스 (현재 선택된 학생의 주변 학생을 탐색하는 반복문)
        if (isStudentSelected[i])
            continue;
        int leftIndex = toLeft(i);
        int rightIndex = toRight(i);
        int topIndex = toTop(i);
        int bottomIndex = toBottom(i);
        bool leftConnectivity = leftIndex!=-1 && isStudentSelected[leftIndex];
        bool rightConnectivity = rightIndex!=-1 && isStudentSelected[rightIndex];
        bool topConnectivity = topIndex!=-1 && isStudentSelected[topIndex];
        bool bottomConnectivity = bottomIndex!=-1 && isStudentSelected[bottomIndex];
        if (leftConnectivity || rightConnectivity || topConnectivity || bottomConnectivity) {
            isStudentSelected[i] = true;
            backtrack(depth+1);
            isStudentSelected[i] = false;
        }
    } //i loop
}

int main() {
    scanf("%s", &studentAt[0]);
    scanf("%s", &studentAt[5]);
    scanf("%s", &studentAt[10]);
    scanf("%s", &studentAt[15]);
    scanf("%s", &studentAt[20]);

    for (startingIndexGlobal=0; startingIndexGlobal<25; startingIndexGlobal++) {
        isStudentSelected[startingIndexGlobal] = true;
        backtrack(1);
        isStudentSelected[startingIndexGlobal] = false;
    }

    printf("%d\n", possibleCombinationsSet.size());
    return 0;

}
