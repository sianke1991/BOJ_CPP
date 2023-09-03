#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ROOT = 1; // ��Ʈ ����� ��ȣ (�� ��帶�� 2, 3, 4 ������ ��ȣ�� �ű��.)
int unused = 2; // ���� �߰��� ����� ��ȣ (2�� ��带 ������ ��� unused++; �� �����Ͽ� unused�� 3���� ������ѵд�.)
const int MX = 10000 * 10 + 5; // �ִ� ���� ������ ������ ��
bool chk[MX]; // �ش� ��尡 ���ڿ��� ���� ��Ÿ������ ����
int nxt[MX][26]; // �ش� ����� �ڽ� ��� (�ڽ� ��带 Ž���� �� ������ ������ �� ������ �޸� �� ���� �߻��Ѵ�.)
                // �� ��� �� �ڽ� ��带 �ִ� 26 �� �� �� �ִ�.

/**
 *  Ʈ���̸� �ʱ�ȭ�Ѵ�.
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
 *  char �� �� ch�� int ������ ��ȯ�Ͽ� �ε����� ����� �� �ְ� �����Ѵ�.
 */
int c2i(char ch) {
    return ch-'0';
}

/**
 *  Ʈ���̿� ���ڿ��� �߰��Ѵ�.<br/>
 *  �ϰ����� ��ġ�� ���ڿ��� ������ ��� false�� ��ȯ�Ѵ�.
 */
/*
���� �Էµ� ��ȭ��ȣ�� �ϰ����� ���� ���� �� ������ �ִ�.
  1. ���� �Էµ� ��ȭ��ȣ�� ������ �ִ� ��ȭ��ȣ�� ���λ簡 �Ǵ� ��� (eg. 9119�� �Էµ� ���¿��� 911�� �ԷµǴ� ���)
  2. ���� �Էµ� ��ȭ��ȣ�� ������ �ִ� ��ȭ��ȣ �� �ּ� �ϳ��� ���λ�� ���� ��� (eg. 911�� �Էµ� ���¿��� 9119�� �ԷµǴ� ���)
  1���� ��� �� ��ȭ��ȣ�� Ʈ���̿� ���� �� �� �ѹ��� ���ο� ��带 ��ô���� �ʰ� �ȴ�. ���� �� ��ȭ��ȣ�� ���� �� �� ��带 ��ô�ϴ��� ���θ� üũ�� �ʿ䰡 �ִ�.
  2���� ��� �� ��ȭ��ȣ�� Ʈ���̿� ���� �� ������ �Էµ� �ܾ��� ���� �湮�ϰ� �ȴ�. ���� �� ��ȭ��ȣ�� ���� �� ������ �־��� �ܾ��� ���� �湮�ϴ��� ���θ� üũ�� �ʿ䰡 �ִ�.
*/
bool Insert(string s) {
    int cur = ROOT;
    bool result0 = false; //���ο� ��带 ��ô�� ������ �ִ��� ����
    bool result1 = true; //������ �Էµ� �ܾ��� ���� ���� ���� ������ ����
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) { // ���� ���� �ִ� ��忡�� ���� ���ڿ� �ش��ϴ� �ڽ� ��尡 ���� ���
            nxt[cur][c2i(ch)] = unused++; // ���ο� ��带 �߰��Ͽ� ���� ���� �ִ� ����� �ڽ� ���� ��´�.
            result0 = true; // ���ο� ��带 ��ô�� ������ �ִ� ��� true�� �����Ѵ�. (�̹��� �Էµ� �ܾ�� ������ �Էµ� �ܾ���� ���λ簡 �ƴϴ�.)
        } else if (chk[nxt[cur][c2i(ch)]]) {
            result1 = false; //������ �Էµ� �ܾ��� ���� �湮�ϰ� �Ǹ� false�� ��ȯ�Ѵ�. (�̹��� �Էµ� �ܾ�� ������ �Էµ� �ܾ� �� �ּ� �ϳ��� ���λ�� ���´�.)
        }
        cur = nxt[cur][c2i(ch)]; // ���� ���� �ִ� ��带 �ڽ� ���� �ű��.
    } //ch loop (Ʈ���̿� �������� ���ڿ��� �� ���ڿ� ���� �ݺ���)
    chk[cur] = true; //���� �߰��ϴ� ���ڿ��� ������ ���ڿ� �ش��ϴ� ��忡 ������ ǥ�ø� �� �ش�.
    return result0 && result1;
}

bool Insert2(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur][c2i(ch)]==-1) {
            nxt[cur][c2i(ch)] = unused++;
        }
        cur = nxt[cur][c2i(ch)];
        if (chk[cur]) return 0; //������ ���Ե� �ܾ��� ���� �湮�� ��� �ٷ� false�� ��ȯ�Ѵ�.
    }
    if (cur!=unused-1) return 0; //���ο� �ܾ Ʈ���̿� �����ϸ鼭 �� ��带 ��ô���� ���� ��� false�� ��ȯ�Ѵ�.
    chk[cur] = true;
    return true; //�� �� ��쿡 �ش����� ���� ��� Ʈ���̿� ���� �߰��� ���ڿ��� �ϰ����� ���� ���� ���̴�.
}

int main() {
    vector<bool> results;
    int numTestCases;
    cin >> numTestCases;
    for (int testCase=0; testCase<numTestCases; testCase++) {
        init(); // �� �׽�Ʈ���� Ʈ���̸� �ʱ�ȭ�Ѵ�.
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
