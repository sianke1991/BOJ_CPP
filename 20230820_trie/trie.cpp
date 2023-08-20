#include <iostream>
#include <string>

using namespace std;

//Ʈ���� (trie): ���ڿ��� ȿ�������� ó���ϱ� ���� �ڷᱸ��

/*
�ð����⵵ �� ������ �ְ�, �������⵵ �� ������ �ִ�.
����: �ܾ� S�� ����/ Ž��/ ������ �� O(|s|)
����: ���ڿ��� �׳� �迭�� �����ϴ� �ͺ��� �ִ� 4*������ ���� �� ��ŭ �� ��� (���⼭ 4�� �ڷ��� int�� ũ��)
(���� ��� �� �ܾ ���ĺ� �빮�ڷθ� �����Ǿ� ���� ��� 104��)

�̷����� �ð����⵵�ʹ� ������ �����δ� Ʈ���̰� �ؽ�, ���� �˻� Ʈ���� ���� �ξ� ����.
�Ϲ����� ��Ȳ������ �ؽó� ���� �˻� Ʈ���� ����ϴ°� ������,
Ʈ������ ������ ����ؾ� �ϴ� ������ ���� ����

�׷��ٰ� Ʈ���̰� ���� �������� �ʴ�...
*/

const int ROOT = 1; // ��Ʈ ����� ��ȣ (�� ��帶�� 2, 3, 4 ������ ��ȣ�� �ű��.)
int unused = 2; // ���� �߰��� ����� ��ȣ (2�� ��带 ������ ��� unused++; �� �����Ͽ� unused�� 3���� ������ѵд�.)
const int MX = 10000 * 500 + 5; // �ִ� ���� ������ ������ ��
bool chk[MX]; // �ش� ��尡 ���ڿ��� ���� ��Ÿ������ ����
int nxt[MX][26]; // �ش� ����� �ڽ� ��� (�ڽ� ��带 Ž���� �� ������ ������ �� ������ �޸� �� ���� �߻��Ѵ�.)
                // �� ��� �� �ڽ� ��带 �ִ� 26 �� �� �� �ִ�.

/**
 *  ��� ��忡 �ڽ� ��尡 ���� ���·� �����.
 */
void init() {
    for (int i=0; i<MX; i++) {
        for (int j=0; j<26; j++) {
            nxt[i][j] = -1;
        }
    }
}

/**
 *  char �� �� ch�� int ������ ��ȯ�Ͽ� �ε����� ����� �� �ְ� �����Ѵ�.
 */
int c2i(char ch) {
    return ch-'A';
}

/**
 *  Ʈ���̿� ���ڿ��� �߰��Ѵ�.
 */
void Insert(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) { // ���� ���� �ִ� ��忡�� ���� ���ڿ� �ش��ϴ� �ڽ� ��尡 ���� ���
            nxt[cur][c2i(ch)] = unused++; // ���ο� ��带 �߰��Ͽ� ���� ���� �ִ� ����� �ڽ� ���� ��´�.
        }
        cur = nxt[cur][c2i(ch)]; // ���� ���� �ִ� ��带 �ڽ� ���� �ű��.
    } //ch loop (Ʈ���̿� �������� ���ڿ��� �� ���ڿ� ���� �ݺ���)
    chk[cur] = true; //���� �߰��ϴ� ���ڿ��� ������ ���ڿ� �ش��ϴ� ��忡 ������ ǥ�ø� �� �ش�.
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
�������: � ó���� �ϱ� ���� ���� �������� ó�� �ð� �޸� ���� ���Ѵ�.



*/
