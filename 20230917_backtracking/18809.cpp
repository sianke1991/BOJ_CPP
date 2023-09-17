#include <bits/stdc++.h>

using namespace std;


int numRows; //������ ���� ����
int numCols; //������ ���� ����
int numGreens; //��� ���� ��
int numReds; //���� ���� ��
int optResult = 0; //�ǿ� �� �ִ� ���� ����
int gardenInput[50][50]; //���� �Է°� (������ �Ѹ��� ���� �ʱ� ���¸� �����Ѵ�.)
//0: ȣ��
//1: ������ �Ѹ� �� ���� ��
//2: ������ �Ѹ� �� �ִ� ��

int garden[50][50]; //���� (������ �ѷ����� ���������� ���¸� �����Ѵ�.)
//0: ȣ�� (������ ���� �� ����.)
//1: ������ �Ѹ� �� ���� �� (������ ������ ���� ����)
//2: ������ �Ѹ� �� �ִ� �� (������ �ѷ����ų� ������ ���� ����)
//3: ���� �� ���� ��� ������ �ִ� �� (�� ���� ���� ������ ������ ���� �ǰ�, �׷��� ���� ��� 5������ ���°� ���Ѵ�.)
//4: ���� �� ���� ���� ������ �ִ� �� (�� ���� ��� ������ ������ ���� �ǰ�, �׷��� ���� ��� 6������ ���°� ���Ѵ�.)
//5: ��� ������ ������ �� (�� ������ �ٸ� ������ �Ѿ���� �ʴ´�. �����¿쿡 1��, 2�� ĭ�� �ִ� ��� �ش� ĭ�� 3������, 4�� ĭ�� �ִ� ��� �ش� ĭ�� 7������ ��ȭ��Ų��.)
//6: ���� ������ ������ �� (�� ������ �ٸ� ������ �Ѿ���� �ʴ´�. �����¿쿡 1��, 2�� ĭ�� �ִ� ��� �ش� ĭ�� 4������, 3�� ĭ�� �ִ� ��� �ش� ĭ�� 7������ ��ȭ��Ų��.)
//7: ���� �� �� (�� ������ �ٸ� ������ �Ѿ���� �ʴ´�.)

int dRow[] = {0, 1, 0, -1};
int dCol[] = {1, 0, -1, 0};
int numSelectedGreens; //������ ������ �ѷ��� ��� ���� �� (�� ���� numGreens�� �ٸ� ��� BFS�� �������� �ʴ´�.)
int numSelectedReds; //������ ������ �ѷ��� ���� ���� �� (�� ���� numReds�� �ٸ� ��� BFS�� �������� �ʴ´�.)
vector<pair<int, int>> possibleSquares; //������ �Ѹ� �� �ִ� �� ���
char colours[10] = {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}; //������ �Ѹ� �� �ִ� ���� ���� ������ �ѷ��� ���� ��
//'O': ������ �ѷ����� ����
//'G': ��� ����
//'R': ���� ����

//�Լ� ������Ÿ��
void BFS();


//������ �Ѹ��� ����� ���� �ݺ��� �����Ѵ�.
//depth: ������ �Ѹ� �� �ִ� �� ��� �� �ε���
void backtrack(int depth) {
    //���̽� ���̽�
    if (depth==possibleSquares.size()) {
        if (numSelectedGreens==numGreens && numSelectedReds==numReds) {
            BFS();
        }
        return;
    }

    if (numSelectedGreens<numGreens) { //��� ������ ���� ���-
        colours[depth] = 'G';
        numSelectedGreens++;
        backtrack(depth+1);
        colours[depth] = 'O';
        numSelectedGreens--;
    }

    if (numSelectedReds<numReds) { //���� ������ ���� ���-
        colours[depth] = 'R';
        numSelectedReds++;
        backtrack(depth+1);
        colours[depth] = 'O';
        numSelectedReds--;
    }

    if (depth-numSelectedGreens-numSelectedReds<possibleSquares.size()-numGreens-numReds) {
        backtrack(depth+1); //���� ������ ���Ҵ��� ���Ŀ� �����ϴ� [������ �Ѹ� �� �ִ� ��]�� ������ �Ѹ��� ��츦 ����� �ʿ䰡 �ִ�.
    }
}

//�־��� ���� ������ �ѷ��� �Ǿ�� ���� ������ ��Ƹ���.
//�ʿ信 ���� optResult�� �����Ѵ�.
void BFS() {
    //a. garden <- gardenInput (���� �����͸� �Է¹޴´�.)
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            garden[row][col] = gardenInput[row][col];
        } //col loop
    } //row loop

    //b. �־��� ���� ������ �Ѹ���.
    queue<pair<int, int>> qGreens; //��� ������ ���������� ������ �����ϱ� ���� ť
    queue<pair<int, int>> qReds; //���� ������ ���������� ������ �������� ���� ť
    for (int i=0; i<possibleSquares.size(); i++) {
        switch (colours[i]) {
            case 'G':
                garden[possibleSquares[i].first][possibleSquares[i].second] = 5;
                qGreens.push(possibleSquares[i]);
                break;
            case 'R':
                garden[possibleSquares[i].first][possibleSquares[i].second] = 6;
                qReds.push(possibleSquares[i]);
                break;
        }
    } //i loop

    int currentResult = 0; //�Ǿ ���� ����
    set<pair<int, int>> code3Squares; //���� �� ���� ��� ������ �ִ� ���� ����
    set<pair<int, int>> code4Squares; //���� �� ���� ���� ������ �ִ� ���� ����

    while (!qGreens.empty() && !qReds.empty()) {

        //c. ��� ť���� ���Ҹ� �ϳ� ������ �����¿� ������ ĭ�� ���� ������ ó���� �Ѵ�.
        //��� ������ ������ �� ���ο� ���� ���� ������ ó���� �ؾ� �ϹǷ� ���⵵ �ݺ��� �ʿ��ϴ�.
        while (!qGreens.empty()) {
            pair<int, int> currentSquare = qGreens.front();
            qGreens.pop();
            for (int dir=0; dir<4; dir++) {
                int nRow = currentSquare.first+dRow[dir];
                int nCol = currentSquare.second+dCol[dir];
                if (nRow<0 || nRow>=numRows || nCol<0 || nCol>=numCols) //out of bounds
                    continue;
                switch (garden[nRow][nCol]) {
                    case 0: //ȣ��
                    case 5: //��� ������ ������ ��
                    case 6: //���� ������ ������ ��
                    case 7: //���� �� ��
                        continue;
                    case 4: //���� �� ���� ���� ������ �ִ� �� (��� ť���� ���Ҹ� ���� �̾����Ƿ� ��� �� ���� �����ϸ� �ȵȴ�.)
                        code4Squares.erase({nRow, nCol});
                        garden[nRow][nCol] = 7;
                        currentResult++;
                        break;
                    default:
                        code3Squares.insert({nRow, nCol});
                        garden[nRow][nCol] = 3;
                        break;
                } //switch-case
            } //direction loop
        } //while loop (until qGreens become empty)


        //d. ���� ť���� ���Ҹ� �ϳ� ������ �����¿� ������ ĭ�� ���������� ó���� �Ѵ�.
        //���� ������ ������ �� ���ο� ���� ���������� ó���� �ؾ� �ϹǷ� ���⵵ �ݺ��� �ʿ��ϴ�.
        while (!qReds.empty()) {
            pair<int, int> currentSquare = qReds.front();
            qReds.pop();
            for (int dir=0; dir<4; dir++) {
                int nRow = currentSquare.first+dRow[dir];
                int nCol = currentSquare.second+dCol[dir];
                if (nRow<0 || nRow>=numRows || nCol<0 || nCol>=numCols) //out of bounds
                    continue;
                switch (garden[nRow][nCol]) {
                    case 0: //ȣ��
                    case 5: //��� ������ ������ ��
                    case 6: //���� ������ ������ ��
                    case 7: //���� �� ��
                        continue;
                    case 3: //���� �� ���� ��� ������ �ִ� ��
                        code3Squares.erase({nRow, nCol});
                        garden[nRow][nCol] = 7;
                        currentResult++;
                        break;
                    default:
                        code4Squares.insert({nRow, nCol});
                        garden[nRow][nCol] = 4;
                        break;
                }
            } //direction loop
        } //while loop (until qReds become empty)

        //e. ������ ���� �� �����µ� ���� �ǿ��� ���� ������ �ִ��� �����Ѵ�.
        //��� ������ ��� 3->5�� ���¸� ��ȭ��Ű�� qGreens�� �ش� ĭ�� �ִ´�.
        //���� ������ ��� 4->6���� ���¸� ��ȭ��Ű�� qReds�� �ش� ĭ�� �ִ´�.
        //3�� 4 ���¿����� ���� ���� �ǿ� �� �ִ� ���ɼ��� �ֱ� ������ 5�� 6 ���·� ������ ������ ť�� �־�� �Ѵ�.
        /*
        for (int row=0; row<numRows; row++) {
            for (int col=0; col<numCols; col++) {
                switch (garden[row][col]) {
                    case 3: //���� �� ���� ��� ������ ���-
                        garden[row][col] = 5;
                        qGreens.push({row, col});
                        break;
                    case 4: //���� �� ���� ���� ������ ���-
                        garden[row][col] = 6;
                        qReds.push({row, col});
                        break;
                }
            } //col loop
        } //row loop
        */
        for (pair<int, int> square:code3Squares) {
            garden[square.first][square.second] = 5;
            qGreens.push(square);
        }
        code3Squares.clear();
        for (pair<int, int> square:code4Squares) {
            garden[square.first][square.second] = 6;
            qReds.push(square);
        }
        code4Squares.clear();
    } //while loop (��� ť, ���� ť �� �ϳ��� ��� �Ǹ� �ݺ��� �����Ѵ�.)

    //f. ���Ӱ� ������ �Ѹ� ��� ������ ������� ���� �� ���� �� ���, optResult�� �����Ѵ�.
    if (currentResult>optResult) {
        //cout << "LOG:::::::\n";
        //for (char colour:colours) {
        //    cout << colour << ' ';
        //}
        //cout << '\n' << currentResult << '\n';
        //cout << "LOG:::::::\n";
        optResult = currentResult;
    }
}





int main() {
    cin >> numRows >> numCols >> numGreens >> numReds;
    for (int row=0; row<numRows; row++) {
        for (int col=0; col<numCols; col++) {
            cin >> gardenInput[row][col];
            if (gardenInput[row][col]==2) { //������ �Ѹ� �� �ִ� ���� ���-
                possibleSquares.push_back({row, col}); //������ �Ѹ� �� �ִ� �� ��Ͽ� �߰��Ѵ�.
            }
        } //col loop
    } //row loop

    //������ �Ѹ��� ����� ���� �ݺ��� �����Ѵ�.
    backtrack(0);

    cout << optResult;
    return 0;
}
