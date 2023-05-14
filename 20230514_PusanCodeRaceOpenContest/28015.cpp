#include <bits/stdc++.h>

using namespace std;

int numRows, numCols;
vector<int> targetBoard[100];

//void printVector(vector<int> intVector) {
//    for (int integer:intVector) {
//        cout << integer << ' ';
//    }
//    cout << '\n';
//}

/**
 * ���� ĥ���� [���� ��]�� ĥ�ϴµ� �ʿ��� ������ �ּ� Ƚ���� ��ȯ�Ѵ�.
 * 1�� �����ϴ� ���� ���� ���� ���� 1�� ���� ĥ�ϰ� �κ������� 2�� ĥ�Ѵ�.
 * 2�� �����ϴ� ���� ���� ���� ���� 2�� ���� ĥ�ϰ� �κ������� 1�� ĥ�Ѵ�.
 */
int getNumStrokesForLocalRow(vector<int> localRow) {
    if (localRow.empty()) {
        return 0;
    }
    int beginColor = localRow[0];
    if (beginColor==1) {
        int result = 1;
        for (int targetColor:localRow) {
            if (targetColor==2) result++;
        }
        return result;
    } else {
        int result = 1;
        for (int targetColor:localRow) {
            if (targetColor==1) result++;
        }
        return result;
    }
}
/**
 * �� ���� ĥ�ϴµ� �ʿ��� ������ �ּ� Ƚ���� ��ȯ�Ѵ�.
 * �� �࿡ �ִ� ���� ���� ���ؼ� �� ���� ���� ĥ�ϴµ� �ʿ��� ������ �ּ� Ƚ���� ���� ���Ѵ�.
 */
int getNumStrokesForRow(int rowNum) {
    int result = 0;
    vector<int> localRow;
    for (int targetColor:targetBoard[rowNum]) {
        if (targetColor==0) {
            result += getNumStrokesForLocalRow(localRow);
            localRow.clear();
        } else {
            localRow.push_back(targetColor);
        }
    }
    result += getNumStrokesForLocalRow(localRow);
    return result;
}

int main() {
    cin >> numRows >> numCols;
    for (int i=0; i<numRows; i++) {
        {
            int targetColor;
            cin >> targetColor;
            targetBoard[i].push_back(targetColor);
        }
        for (int j=1; j<numCols; j++) {
            int targetColor;
            cin >> targetColor;
            int recentColor = targetBoard[i][targetBoard[i].size()-1];
            if (targetColor==recentColor) continue;
            targetBoard[i].push_back(targetColor);
        }
    }
    int result = 0;
    for (int i=0; i<numRows; i++) {
        result += getNumStrokesForRow(i);
    }
    cout << result;
    return 0;
}


