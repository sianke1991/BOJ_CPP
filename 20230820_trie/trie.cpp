#include <iostream>
#include <string>

using namespace std;

//트라이 (trie): 문자열을 효율적으로 처리하기 위한 자료구조

/*
시간복잡도 상 장점이 있고, 공간복잡도 상 단점이 있다.
장점: 단어 S를 삽입/ 탐색/ 삭제할 때 O(|s|)
단점: 문자열을 그냥 배열에 저장하는 것보다 최대 4*글자의 종류 배 만큼 더 사용 (여기서 4는 자료형 int의 크기)
(예를 들어 각 단어가 알파벳 대문자로만 구성되어 있을 경우 104배)

이론적인 시간복잡도와는 별개로 실제로는 트라이가 해시, 이진 검색 트리에 비해 훨씬 느림.
일반적인 상황에서는 해시나 이진 검색 트리를 사용하는게 좋으나,
트라이의 성질을 사용해야 하는 문제가 여럿 존재

그렇다고 트라이가 마냥 빠르지는 않다...
*/

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
    return ch-'A';
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
    Insert("APPLE");
    Insert("APPLY");
    cout << Find("APPLE") << '\n';
    cout << Find("APPLY") << '\n';
    cout << Find("BANANA") << '\n';
    cout << Find ("BLACK") << '\n';
    Insert("BANANA");
    cout << Find("APPLE") << '\n';
    cout << Find("APPLY") << '\n';
    cout << Find("BANANA") << '\n';
    cout << Find ("BLACK") << '\n';
    Remove("APPLE");
    cout << Find("APPLE") << '\n';
    cout << Find("APPLY") << '\n';
    cout << Find("BANANA") << '\n';
    cout << Find ("BLACK") << '\n';

    return 0;
}

/*
오버헤드: 어떤 처리를 하기 위해 들어가는 간접적인 처리 시간 메모리 등을 말한다.



*/
