#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    return ch-'a';
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

/**
 * Ʈ���̿� �Է¹��� ���ڿ��� ���λ�� ���� ���ڿ��� �ִ��� ���θ� ��ȯ�Ѵ�.
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
