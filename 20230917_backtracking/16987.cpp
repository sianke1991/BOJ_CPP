#include <iostream>

using namespace std;

int numEggs; //계란 개수
int optResult; //깨진 계란 개수 최대치
struct Egg {
    int hitPoint;
    int weight;
};
Egg eggs[8];


//currentEggIndex: 다른 계란을 치기 위해 선택한 계란의 인덱스
void backtrack(int currentEggIndex) {
    //베이스 케이스
    if (currentEggIndex>=numEggs) {
        int currentResult = 0; //현재 깨진 계란 개수 (이 값이 optResult보다 클 경우 optResult를 갱신한다.)
        for (int i=0; i<numEggs; i++) {
            if (eggs[i].hitPoint<=0)
                currentResult++;
        } //i loop
        //cout << "LOG:::::: currentResult: " << currentResult << '\n';
        if (currentResult>optResult)
            optResult = currentResult;
        return;
    }


    //선택된 계란이 이미 깨진 경우 다른 계란과 부딪치지 않고 바로 다음 계란을 선택한다.
    if (eggs[currentEggIndex].hitPoint<=0) {
        backtrack(currentEggIndex+1);
        return;
    }

    //targetEggIndex: currentEgg와 부딪칠 계란의 인덱스
    bool isTargetSelected = false;
    for (int targetEggIndex=0; targetEggIndex<numEggs; targetEggIndex++) {
        if (targetEggIndex==currentEggIndex) //선택된 계란과 그 자신이 부딪치는 경우는 고려하지 않는다.
            continue;
        if (eggs[targetEggIndex].hitPoint<=0) //이미 깨진 계란과 부딪치는 경우는 고려하지 않는다.
            continue;
        isTargetSelected = true;
        //선택된 두 계란의 내구도를 감소시킨 뒤 다음 계란을 선택한다.
        eggs[currentEggIndex].hitPoint -= eggs[targetEggIndex].weight;
        eggs[targetEggIndex].hitPoint -= eggs[currentEggIndex].weight;
        backtrack(currentEggIndex+1);
        eggs[currentEggIndex].hitPoint += eggs[targetEggIndex].weight;
        eggs[targetEggIndex].hitPoint += eggs[currentEggIndex].weight;

        //하나의 currentEgg에 대해서 둘 이상의 targetEgg가 있을 수 있으므로 for loop 안에
        //return;이 들어가면 안된다. (return;이 들어가면 targetEgg 하나 발견하고 루프를 종료하게 되서
        //최적의 경우를 탐색하지 못할 수 있다.)
    } //targetEggIndex loop

    //targetEgg를 선택하지 못한 경우 바로 다음 계란을 선택한다.
    if (!isTargetSelected)
        backtrack(currentEggIndex+1);
}

int main() {
    cin >> numEggs;
    for (int i=0; i<numEggs; i++) {
        cin >> eggs[i].hitPoint;
        cin >> eggs[i].weight;
    }
    backtrack(0);
    cout << optResult;


    return 0;
}
