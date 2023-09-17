#include <iostream>

using namespace std;

/*
18809 ���� Ǯ�� ���� ���� ����
10���� �� �߿��� 3���� ��� ������, 2���� ���� ������ �Ѹ� ��
������ �� ��쿡 ���� �ݺ� ����
������ �Ѹ��� �ʴ� ���� ������ ��Ƹ��鼭 ������ ������ �ڵ� ���� �ð� ���࿡ ������ �ȴ�.
*/


char colours[10] = {};
int numGreens;
int numReds;
int numSelectedGreens;
int numSelectedReds;
int numCases = 0;

void backtrack(int depth) {
    if (depth>=10) {
        if (numSelectedGreens==numGreens && numSelectedReds==numReds) {
            numCases++;
            //cout << numCases << ' ';
            //for (char colour:colours) {
                //cout << colour << ' ';
            //}
            //cout << '\n';
        }
        return;
    }

    if (numSelectedGreens<numGreens) {
        colours[depth] = 'G';
        numSelectedGreens++;
        backtrack(depth+1);
        colours[depth] = 'O';
        numSelectedGreens--;
    }

    if (numSelectedReds<numReds) {
        colours[depth] = 'R';
        numSelectedReds++;
        backtrack(depth+1);
        colours[depth] = 'O';
        numSelectedReds--;
    }

    if (depth-numSelectedGreens-numSelectedReds<10-numGreens-numReds)
        backtrack(depth+1);
}


int main() {

    fill (colours, colours+10, 'O');
    cin >> numGreens >> numReds;
    numSelectedGreens = 0;
    numSelectedReds = 0;

    backtrack(0);
    cout << numCases << '\n';
    return 0;


}
