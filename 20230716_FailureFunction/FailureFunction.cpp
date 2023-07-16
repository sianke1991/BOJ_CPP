#include <string>
#include <vector>
#include <iostream>

using namespace std;

//function prototype
string toString(vector<int> v);
int rightIndexOf(char ch, string str, int fromIndex);

/**
 * 문자열 a의 실패함수 값들을 반환한다.
 * 만약 a가 길이 3 짜리 문자열일 경우 f(0), f(1), f(2), f(3)으로 구성된 vector를 반환한다.
 */
vector<int> failure(string a) {
    int lenA = a.size();
    int cache[lenA+1] = {0};
    for (int i=1; i<=lenA; i++) {
        cache[i] = rightIndexOf(a[i], a, cache[i-1])+1; //점화식에서 새로 추가되는 문자는 a[i], 탐색을 시작하는 위치는 직전 실패함수값+1 이다.
    }
    vector<int> result(cache, cache+lenA); //배열의 시작 위치와 끝 위치을 인자로 넣어서 벡터 생성 시 사용할 수 있다.
    return result;
}

vector<int> failure2(string s) {
    vector<int> f(s.size());
    int j=0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j])  j = f[j-1]; //실패함수의 특성 상 선형 탐색이 아닌 건너뛰기 탐색이 가능한 것으로 보인다.
        if (s[i]==s[j]) f[i] = ++j; //문자열에 새로 추가된 문자가 접두사에 위치하는 인덱스의 최대치 (rightIndex)를 구했으면 그 값의 +1이 실패함수 값이 된다.
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
