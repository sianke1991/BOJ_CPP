#include <iostream>

using namespace std;

long long numCases = 0;
int numInputs;
int inputNumbers[20];
int targetSum = 0;


/**inputNumbers�� �� ���� ���� �Ǵ� �������� �������� �������� Ʈ���� �׸���.*/
void recursion(int depth, int partialSum) {
    //base case
    if (depth == numInputs) {
        if (partialSum == targetSum) numCases++;
        return;
    }

    recursion(depth+1, partialSum); //depth�� �ش��ϴ� ���Ҹ� �������� �ʴ� ���
    recursion(depth+1, partialSum+inputNumbers[depth]); //depth�� �ش��ϴ� ���Ҹ� �����ϴ� ���
}

int main() {
    cin >> numInputs >> targetSum;
    for (int i=0; i<numInputs; i++)
        cin >> inputNumbers[i];
    recursion(0, 0);
    if (targetSum==0) { //��ǥ ������ 0�� ��� inputNumbers�� ���� �������� �ʴ� ��쵵 ī��Ʈ�� �Ǵµ�, �� ������ �׷� ��츦 �����ؾ� �ϴ� �� �ϴ�.
        cout << (numCases-1);
    } else {
        cout << numCases;
    }
    return 0;
}
