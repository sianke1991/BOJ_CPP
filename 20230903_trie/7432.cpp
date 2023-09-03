#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
int unused = ROOT;
const int MX = 500 * 41 + 5;
bool chk[MX];
string strArr[MX]; //해당 노드 번호에 들어간 문자열을 저장해준다. (트라이를 출력할 때 용이해짐)
map<string, int> nxt[MX];

/**
 * 문자열을 입력받아 구분자를 기준으로 자른 결과를 반환한다.
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
 * 입력받은 길이에 해당하는 공백 문자열을 반환한다.
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
    int depth = 0; //해당 파일, 디렉터리의 깊이
    for (string word:words) {
        string newWord = whiteSpaces(depth)+word; //파일 또는 디렉터리의 이름 앞에 깊이에 해당하는 공백을 넣어서 문자열 newWord를 구성한다.
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
