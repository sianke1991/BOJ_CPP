#include <iostream>

using namespace std;

int numEggs; //��� ����
int optResult; //���� ��� ���� �ִ�ġ
struct Egg {
    int hitPoint;
    int weight;
};
Egg eggs[8];


//currentEggIndex: �ٸ� ����� ġ�� ���� ������ ����� �ε���
void backtrack(int currentEggIndex) {
    //���̽� ���̽�
    if (currentEggIndex>=numEggs) {
        int currentResult = 0; //���� ���� ��� ���� (�� ���� optResult���� Ŭ ��� optResult�� �����Ѵ�.)
        for (int i=0; i<numEggs; i++) {
            if (eggs[i].hitPoint<=0)
                currentResult++;
        } //i loop
        //cout << "LOG:::::: currentResult: " << currentResult << '\n';
        if (currentResult>optResult)
            optResult = currentResult;
        return;
    }


    //���õ� ����� �̹� ���� ��� �ٸ� ����� �ε�ġ�� �ʰ� �ٷ� ���� ����� �����Ѵ�.
    if (eggs[currentEggIndex].hitPoint<=0) {
        backtrack(currentEggIndex+1);
        return;
    }

    //targetEggIndex: currentEgg�� �ε�ĥ ����� �ε���
    bool isTargetSelected = false;
    for (int targetEggIndex=0; targetEggIndex<numEggs; targetEggIndex++) {
        if (targetEggIndex==currentEggIndex) //���õ� ����� �� �ڽ��� �ε�ġ�� ���� ������� �ʴ´�.
            continue;
        if (eggs[targetEggIndex].hitPoint<=0) //�̹� ���� ����� �ε�ġ�� ���� ������� �ʴ´�.
            continue;
        isTargetSelected = true;
        //���õ� �� ����� �������� ���ҽ�Ų �� ���� ����� �����Ѵ�.
        eggs[currentEggIndex].hitPoint -= eggs[targetEggIndex].weight;
        eggs[targetEggIndex].hitPoint -= eggs[currentEggIndex].weight;
        backtrack(currentEggIndex+1);
        eggs[currentEggIndex].hitPoint += eggs[targetEggIndex].weight;
        eggs[targetEggIndex].hitPoint += eggs[currentEggIndex].weight;

        //�ϳ��� currentEgg�� ���ؼ� �� �̻��� targetEgg�� ���� �� �����Ƿ� for loop �ȿ�
        //return;�� ���� �ȵȴ�. (return;�� ���� targetEgg �ϳ� �߰��ϰ� ������ �����ϰ� �Ǽ�
        //������ ��츦 Ž������ ���� �� �ִ�.)
    } //targetEggIndex loop

    //targetEgg�� �������� ���� ��� �ٷ� ���� ����� �����Ѵ�.
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
