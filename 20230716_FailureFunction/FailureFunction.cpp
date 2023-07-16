#include <string>
#include <vector>
#include <iostream>

using namespace std;

//function prototype
string toString(vector<int> v);
int rightIndexOf(char ch, string str, int fromIndex);

/**
 * ���ڿ� a�� �����Լ� ������ ��ȯ�Ѵ�.
 * ���� a�� ���� 3 ¥�� ���ڿ��� ��� f(0), f(1), f(2), f(3)���� ������ vector�� ��ȯ�Ѵ�.
 */
vector<int> failure(string a) {
    int lenA = a.size();
    int cache[lenA+1] = {0};
    for (int i=1; i<=lenA; i++) {
        cache[i] = rightIndexOf(a[i], a, cache[i-1])+1; //��ȭ�Ŀ��� ���� �߰��Ǵ� ���ڴ� a[i], Ž���� �����ϴ� ��ġ�� ���� �����Լ���+1 �̴�.
    }
    vector<int> result(cache, cache+lenA); //�迭�� ���� ��ġ�� �� ��ġ�� ���ڷ� �־ ���� ���� �� ����� �� �ִ�.
    return result;
}

vector<int> failure2(string s) {
    vector<int> f(s.size());
    int j=0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j])  j = f[j-1]; //�����Լ��� Ư�� �� ���� Ž���� �ƴ� �ǳʶٱ� Ž���� ������ ������ ���δ�.
        if (s[i]==s[j]) f[i] = ++j; //���ڿ��� ���� �߰��� ���ڰ� ���λ翡 ��ġ�ϴ� �ε����� �ִ�ġ (rightIndex)�� �������� �� ���� +1�� �����Լ� ���� �ȴ�.
    }
    return f;
}



int main() {
    string a = "ABABCABABA";
    cout << toString(failure(a)) << '\n';
    return 0;
}

string toString(vector<int> v) {
    string result = "[";
    for (int num:v) {
        result += to_string(num);
        result += ", ";
    }
    result = result.substr(0, result.size()-2);
    result += "]";
    return result;
}

int rightIndexOf(char ch, string str, int fromIndex) {
    for (int i=fromIndex; i>=0; i--) {
        if (str[i]==ch) return i;
    }
    return -1;
}
