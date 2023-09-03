#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ROOT = 1; // 루트 노드의 번호 (각 노드마다 2, 3, 4 등으로 번호를 매긴다.)
int unused = 2; // 새로 추가될 노드의 번호 (2번 노드를 생성한 경우 unused++; 를 수행하여 unused를 3으로 변경시켜둔다.)
const int MX = 10000 * 10 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX]; // 해당 노드가 문자열의 끝을 나타내는지 여부
int nxt[MX][26]; // 해당 노드의 자식 노드 (자식 노드를 탐색할 때 빠르게 수행할 수 있으나 메모리 상 낭비가 발생한다.)
                // 한 노드 당 자식 노드를 최대 26 개 둘 수 있다.

/**
 *  트라이를 초기화한다.
 */
void init() {
    for (int i=0; i<MX; i++) {
        for (int j=0; j<26; j++) {
            nxt[i][j] = -1;
        }
        chk[i] = false;
    }
    unused = 2;
}

/**
 *  char 형 값 ch를 int 형으로 변환하여 인덱스로 사용할 수 있게 변경한다.
 */
int c2i(char ch) {
    return ch-'0';
}

/**
 *  트라이에 문자열을 추가한다.<br/>
 *  일관성을 해치는 문자열이 들어오는 경우 false를 반환한다.
 */
/*
새로 입력된 전화번호가 일관성을 깨는 경우는 두 가지가 있다.
  1. 새로 입력된 전화번호가 기존에 있는 전화번호의 접두사가 되는 경우 (eg. 9119가 입력된 상태에서 911이 입력되는 경우)
  2. 새로 입력된 전화번호가 기존에 있는 전화번호 중 최소 하나를 접두사로 갖는 경우 (eg. 911이 입력된 상태에서 9119가 입력되는 경우)
  1번의 경우 새 전화번호를 트라이에 넣을 때 단 한번도 새로운 노드를 개척하지 않게 된다. 따라서 새 전화번호를 넣을 때 새 노드를 개척하는지 여부를 체크할 필요가 있다.
  2번의 경우 새 전화번호를 트라이에 넣을 때 기존에 입력된 단어의 끝을 방문하게 된다. 따라서 새 전화번호를 넣을 때 기존에 넣어진 단어의 끝을 방문하는지 여부를 체크할 필요가 있다.
*/
bool Insert(string s) {
    int cur = ROOT;
    bool result0 = false; //새로운 노드를 개척한 전적이 있는지 여부
    bool result1 = true; //기존에 입력된 단어의 끝을 만난 적이 없는지 여부
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) { // 현재 보고 있는 노드에서 다음 문자에 해당하는 자식 노드가 없는 경우
            nxt[cur][c2i(ch)] = unused++; // 새로운 노드를 추가하여 현재 보고 있는 노드의 자식 노드로 삼는다.
            result0 = true; // 새로운 노드를 개척한 전적이 있는 경우 true로 설정한다. (이번에 입력된 단어는 기존에 입력된 단어들의 접두사가 아니다.)
        } else if (chk[nxt[cur][c2i(ch)]]) {
            result1 = false; //기존에 입력된 단어의 끝을 방문하게 되면 false로 반환한다. (이번에 입력된 단어는 기존에 입력된 단어 중 최소 하나를 접두사로 갖는다.)
        }
        cur = nxt[cur][c2i(ch)]; // 현재 보고 있는 노드를 자식 노드로 옮긴다.
    } //ch loop (트라이에 넣으려는 문자열의 각 문자에 대한 반복문)
    chk[cur] = true; //새로 추가하는 문자열의 마지막 문자에 해당하는 노드에 별도의 표시를 해 준다.
    return result0 && result1;
}

bool Insert2(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) {
            nxt[cur][c2i(ch)] = unused++;
        }
        cur = nxt[cur][c2i(ch)];
        if (chk[cur]) return 0; //기존에 삽입된 단어의 끝을 방문한 경우 바로 false를 반환한다.
    }
    if (cur!=unused-1) return 0; //새로운 단어를 트라이에 삽입하면서 새 노드를 개척하지 않은 경우 false를 반환한다.
    chk[cur] = true;
    return true; //위 두 경우에 해당하지 않은 경우 트라이에 새로 추가된 문자열은 일관성을 깨지 않은 것이다.
}

int main() {
    vector<bool> results;
    int numTestCases;
    cin >> numTestCases;
    for (int testCase=0; testCase<numTestCases; testCase++) {
        init(); // 매 테스트마다 트라이를 초기화한다.
        bool result = true;
        int numPhoneNumbers;
        cin >> numPhoneNumbers;
        for (int phoneNumberIndex=0; phoneNumberIndex<numPhoneNumbers; phoneNumberIndex++) {
            string phoneNumber;
            cin >> phoneNumber;
            result = result && Insert(phoneNumber);
        } //phoneNumberIndex loop
        results.push_back(result);
    } //testCase loop

    for (bool result:results) {
        cout << (result ? "YES\n" : "NO\n");
    }

    return 0;
}
