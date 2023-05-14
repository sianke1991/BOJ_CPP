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
 * 색이 칠해진 [색의 섬]을 칠하는데 필요한 붓질의 최소 횟수를 반환한다.
 * 1로 시작하는 색의 섬은 색의 섬을 1로 전부 칠하고 부분적으로 2로 칠한다.
 * 2로 시작하는 색의 섬은 색의 섬을 2로 전부 칠하고 부분적으로 1로 칠한다.
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
 * 한 행을 칠하는데 필요한 붓질의 최소 횟수를 반환한다.
 * 한 행에 있는 색의 섬을 구해서 각 색의 섬을 칠하는데 필요한 붓질의 최소 횟수를 전부 합한다.
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


