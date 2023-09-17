#include <iostream>

using namespace std;

/*
18809 번을 풀기 위한 서브 로직
10개의 땅 중에서 3개에 녹색 배양액을, 2개에 적색 배양액을 뿌릴 때
가능한 총 경우에 대해 반복 수행
배양액을 뿌리지 않는 땅의 개수도 헤아리면서 간선을 내리면 코드 수행 시간 단축에 도움이 된다.
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
