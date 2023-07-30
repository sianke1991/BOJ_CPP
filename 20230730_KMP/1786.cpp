#include <iostream>
#include <string>
#include <vector>


using namespace std;

//����pat�� �����Լ�
vector<int> failure(string& s) {
    vector<int> f(s.size());

    int j = 0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j]) j = f[j-1];
        if (s[i]==s[j]) f[i] = ++j;
    } //i loop

    return f;
}


int main() {
    string str, pat;
    getline(cin, str); //���⸦ ������ ���ڿ� �Է�
    getline(cin, pat); //���⸦ ������ ���ڿ� �Է�

    vector<int> f = failure(pat);
    vector<int> positions; //str ���� pat�� �����ϴ� ��ġ���� ���� ���� (�ε����� �޸� �� ���� ������ ��ġ�� 1�� ��´�.)

    int j = 0;
    for (int i=0; i<str.size(); i++) { //i: str���� ���ڸ� ����Ű�� �ε���, j: pat���� ���ڸ� ����Ű�� �ε���
        while (j>0 && str[i] != pat[j]) j = f[j-1];
        if (str[i] == pat[j]) j++;
        if (j == pat.size()) { //str�� pat�� ����ִٰ� ������ ���-
            positions.push_back(i-j+2); //pat�� �ε����� i-j+1��� �� �� ������ ��ġ�� 1���� �����ϹǷ� i-j+2 ���� ����Ѵ�.
            //pat�� ���̰� 3�� �� j�� 3�� ������ �� str�� pat�� ���ԵǾ��ٰ� �Ǵ��Ѵ�.
            //str�� pat�� ���� �� ������ �� �����Ƿ� pat�� �� �� ã�Ҵٰ� �ݺ��� �ߴ����� �ʴ´�.
        }
    } //i loop
    cout << positions.size() << '\n';
    for (int position:positions) {
        cout << position << '\n';
    }

    return 0;
}
