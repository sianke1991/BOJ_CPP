#include <bits/stdc++.h>

using namespace std;
int dRow[] = {0, 1, 0, -1};
int dCol[] = {1, 0, -1, 0};
set<string> possibleCombinations; //�ҹ��� ĥ���� �Ἲ ������ ����
char students[5][6];
set<pair<int, int>> selectedStudentsSet;
int initialStudentIndex = 0; //�ҹ��� ĥ���ָ� �Ἲ�� �� ó�� ����� �л��� �ε���

int toIndex(int row, int col) {
    return 5*row+col;
}
int toRow(int index) {
    return index/5;
}
int toCol(int index) {
    return index%5;
}


//������ 7���� �л� �� �̴ټ��İ� 4 �� �̻����� ���θ� üũ�� ��
//possibleCombinations�� �����Ѵ�.
void validity() {
    int numSs = 0; //���õ� �л� �� �̴ټ��� �л� ��
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
