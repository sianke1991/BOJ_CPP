#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
string toString(vector<int> v) {
    string result = "[";
    for (int i=0; i<v.size()-1; i++)
        result += to_string(v[i])+", ";
    result += to_string(v[v.size()-1]);
    result += "]";
    return result;
}
*/

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
    int len;
    string str;
    cin >> len;
    cin >> str;

    vector<int> f = failure(str);
    int headerLength = f[len-1];
    cout << len - headerLength;
    return 0;
}

/*

전광판에 출력되는 문자열 s에 대해 실패함수 값을 통해 접두사 h와 접미사 t의 최장길이를 구할 수 있다.
전광판 문자열 s에 접두사 h와 접미사 t를 표시하면 두 가지 경우가 있는데
접두사 h와 접미사 t가 겹쳐지는 경우 (접두사 h의 길이가 전광판 문자열 s 길이의 절반을 초과하면 그렇게 된다.)
접두사 h와 접미사 t가 겹쳐지지 않는 경우 (접두사 h의 길이가 전광판 문자열 s 길이의 절반 이하가 되면 그렇게 된다.)
이다. 각각의 경우에 대해 생각해 본다.

case a. 접두사 h와 접미사 t가 겹쳐지는 경우.
겹쳐지는 영역을 교집합 n이라고 하자. 전광판 문자열 s에 대해 반복 마디는 접두사 h에서 꼬리 부분인 교집합 n을 뺀 부분이라고 볼 수 있다.
첫 번재 반복 마디가 지나간 다음에는 교집합 n 영역에 들어가는데 이 영역의 시작은 위치 상 접미사 t의 시작이고, 접미사 t의 시작은 접두사 h의 시작과 문자가 같다.
따라서 첫 번째 반복 마디가 지나간 다음 마디가 이전 마디를 반복한다고 볼 수 있다.
교집합 n의 길이는 다음 식으로 구할 수 있다.
n.length = 2*h.length - s.length;
반복 마디는 접두사 h에서 교집합 n을 뺀 부분이므로 반복 마디의 길이는 다음과 같다.
반복 마디.length = h.length - n.length = s.length - h.length

case b. 접두사 h와 접미사 t가 겹쳐지지 않는 경우.
접두사 h와 접미사 t 사이의, 접두사와 접미사에 속하지 않는 전광판 문자열 s의 영역을 중립 n 영역이라고 부르자.
(만약 접두사 h의 길이가 전광판 문자열 s의 길이의 정확한 절반인 경우 중립 n은 빈 문자열이 된다.)
전광판 문자열 s에 대해 반복 마디는 접두사 h와 중립 n을 합한 영역이라고 볼 수 있다.
첫 번째 반복 마디가 지나간 다음에는 접미사 부분에 들어가는데 이 접미사 부분의 시작은 접두사 부분의 시작과 같다.
따라서 첫 번째 반복 마디가 지나간 다음 마디가 이전 마디를 반복한다고 볼 수 있다. (또한 두 번째 마디는 중립 n영역이 잘려서 부분만 출력 됨을 알 수 있다.)
중립 n의 길이는 다음 식으로 구할 수 있다.
n.length = s.length - 2*h.length;
반복 마디는 접두사 h와 중립 n을 합한 영역이므로 반복 마디의 길이는 다음과 같다.
반복 마디.length = h.length + n.length = s.length - h.length

두 경우에 대해 전부
    반복 마디.length = s.length - h.length
가 성립하므로 케이스 분기를 사용하지 않고 해당 식으로 반복 마디의 길이를 구할 수 있다.

*/
