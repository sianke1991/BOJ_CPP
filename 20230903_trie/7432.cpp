#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
int unused = ROOT;
const int MX = 500 * 41 + 5;
bool chk[MX];
string strArr[MX]; //�ش� ��� ��ȣ�� �� ���ڿ��� �������ش�. (Ʈ���̸� ����� �� ��������)
map<string, int> nxt[MX];

/**
 * ���ڿ��� �Է¹޾� �����ڸ� �������� �ڸ� ����� ��ȯ�Ѵ�.
 */
vector<string> split(string str, char delim) {
    vector<string> result;
    stringstream sstream(str);
    string word;
    while (getline(sstream, word, delim))
        result.push_back(word);
    return result;
}

/**
 * �Է¹��� ���̿� �ش��ϴ� ���� ���ڿ��� ��ȯ�Ѵ�.
 */
string whiteSpaces(int length) {
    string result = "";
    for (int i=0; i<length; i++)
        result += " ";
    return result;
}

void insert(string dir) {
    vector<string> words = split(dir, '\\');
    int cur = ROOT;
    int depth = 0; //�ش� ����, ���͸��� ����
    for (string word:words) {
        string newWord = whiteSpaces(depth)+word; //���� �Ǵ� ���͸��� �̸� �տ� ���̿� �ش��ϴ� ������ �־ ���ڿ� newWord�� �����Ѵ�.
        if (nxt[cur].find(newWord)==nxt[cur].end()) {
            unused++;
            nxt[cur][newWord] = unused;
            strArr[unused] = newWord;
        }
        cur = nxt[cur][newWord];
        depth++;
    } //word loop
    chk[cur] = true;
}

void dfs(int cur) {
    cout << strArr[cur] << '\n';
    for (pair<string, int> entry:nxt[cur]) {
        dfs(entry.second);
    }
}

int main() {
    int N;
    cin >> N;
    string strInput;
    for (int i=0; i<N; i++) {
        cin >> strInput;
        insert(strInput);
    }
    for (pair<string, int> entry:nxt[ROOT]) {
        dfs(entry.second);
    }
    return 0;
}
