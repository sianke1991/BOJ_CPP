#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

vector<pair<int, int>> possibleSquares[19];
bool usedUDiag[19];
int optResult = 0;
int Size;


void backtrack(int dDiag, int cnt) {
    if (dDiag==2*Size-1) {
        optResult = max(optResult, cnt);
        return;
    }


    for (pair<int, int> p:possibleSquares[dDiag]) {
        int uDiag = p.first+p.second;
        if (usedUDiag[uDiag]) continue;
        usedUDiag[uDiag] = true;
        backtrack(dDiag+1, cnt+1);
        usedUDiag[uDiag] = false;
    }

    backtrack(dDiag+1, cnt);
}

int main() {
    scanf("%d", &Size);
    int b;
    for (int row=0; row<Size; row++) {
        for (int col=0; col<Size; col++) {
            scanf("%d", &b);
            if (b) {
                possibleSquares[Size-1+col-row].push_back({row, col});
            }
        }
    }
    backtrack(0, 0);
    cout << optResult;

    return 0;
}
