#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ROOT = 1; // 루트 노드의 번호 (각 노드마다 2, 3, 4 등으로 번호를 매긴다.)
int unused = 2; // 새로 추가될 노드의 번호 (2번 노드를 생성한 경우 unused++; 를 수행하여 unused를 3으로 변경시켜둔다.)
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX]; // 해당 노드가 문자열의 끝을 나타내는지 여부
int nxt[MX][26]; // 해당 노드의 자식 노드 (자식 노드를 탐색할 때 빠르게 수행할 수 있으나 메모리 상 낭비가 발생한다.)
                // 한 노드 당 자식 노드를 최대 26 개 둘 수 있다.

/**
 *  모든 노드에 자식 노드가 없는 상태로 만든다.
 */
void init() {
    for (int i=0; i<MX; i++) {
        for (int j=0; j<26; j++) {
            nxt[i][j] = -1;
        }
    }
}

/**
 *  char 형 값 ch를 int 형으로 변환하여 인덱스로 사용할 수 있게 변경한다.
 */
int c2i(char ch) {
    return ch-'a';
}

/**
 *  트라이에 문자열을 추가한다.
 */
void Insert(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) { // 현재 보고 있는 노드에서 다음 문자에 해당하는 자식 노드가 없는 경우
            nxt[cur][c2i(ch)] = unused++; // 새로운 노드를 추가하여 현재 보고 있는 노드의 자식 노드로 삼는다.
        }
        cur = nxt[cur][c2i(ch)]; // 현재 보고 있는 노드를 자식 노드로 옮긴다.
    } //ch loop (트라이에 넣으려는 문자열의 각 문자에 대한 반복문)
    chk[cur] = true; //새로 추가하는 문자열의 마지막 문자에 해당하는 노드에 별도의 표시를 해 준다.
}

bool Find(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) return false;
        cur = nxt[cur][c2i(ch)];
    }
    return chk[cur];
}

/**
 * 트라이에 입력받은 문자열을 접두사로 갖는 문자열이 있는지 여부를 반환한다.
 */
bool FindPrefix(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) return false;
        cur = nxt[cur][c2i(ch)];
    }
    return true;
}

void Remove(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) return;
        cur = nxt[cur][c2i(ch)];
    }
    chk[cur] = false;
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    string strInput;
    for (int i=0; i<N; i++) {
        cin >> strInput;
        Insert(strInput);
    }
    int cnt = 0;
    for (int i=0; i<M; i++) {
        cin >> strInput;
        if (FindPrefix(strInput)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
