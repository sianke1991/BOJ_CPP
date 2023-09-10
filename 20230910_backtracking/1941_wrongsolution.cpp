#include <bits/stdc++.h>

using namespace std;
int dRow[] = {0, 1, 0, -1};
int dCol[] = {1, 0, -1, 0};
set<string> possibleCombinations; //소문난 칠공주 결성 가능한 조합
char students[5][6];
set<pair<int, int>> selectedStudentsSet;
int initialStudentIndex = 0; //소문난 칠공주를 결성할 때 처음 고려할 학생의 인덱스

int toIndex(int row, int col) {
    return 5*row+col;
}
int toRow(int index) {
    return index/5;
}
int toCol(int index) {
    return index%5;
}


//선택한 7명이 학생 중 이다솜파가 4 명 이상인지 여부를 체크한 뒤
//possibleCombinations에 삽입한다.
void validity() {
    int numSs = 0; //선택된 학생 중 이다솜파 학생 수
    string elem = "";
    for (pair<int, int> p:selectedStudentsSet) {
        if (students[p.first][p.second]=='S') numSs++;
        elem+=to_string(toIndex(p.first, p.second))+"_";
    }
    if (numSs<4) return;
    possibleCombinations.insert(elem);
}

void backtrack(int depth, int recentlySelectedRow, int recentlySelectedCol) {
    if (depth==7) {
        cout << "text log::::::\n";
        for (pair<int, int> p:selectedStudentsSet) {
            cout << toIndex(p.first, p.second) << "_";
        }
        cout << '\n';
        validity();
        return;
    } //base case

    if (depth==0) {
        if (initialStudentIndex>=25)
            return;
        selectedStudentsSet.insert({toRow(initialStudentIndex), toCol(initialStudentIndex)});
        backtrack(toRow(initialStudentIndex), toCol(initialStudentIndex));
        selectedStudentsSet.erase({toRow(initialStudentIndex), toCol(initialStudentIndex)});
        initialStudentIndex++;
    }

    {
        for (int dir=0; dir<4; dir++) {
            int nextRow = recentlySelectedRow+dRow[dir];
            int nextCol = recentlySelectedCol+dCol[dir];
            if (nextRow<0 || nextRow>=5 || nextCol<0 || nextCol>=5) continue; //out of bounds
            if (selectedStudentsSet.find({nextRow, nextCol})!=selectedStudentsSet.end()) continue; //already selected
            selectedStudentsSet.insert({nextRow, nextCol});
            backtrack(nextRow, nextCol);
            selectedStudentsSet.erase({nextRow, nextCol});
        } //direction loop
    }
}


int main() {
    for (int i=0; i<5; i++) {
        scanf("%s", students[i]);
    }
    backtrack(0, 0);
    cout << possibleCombinations.size();

    for (string elem:possibleCombinations) {
        cout << elem << '\n';
    }
    return 0;

}
