#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

  1893 문제 재풀이
  이번 풀이에서는 암호문 encrypted에 대해 전체를 복호화 하지 않고,
  평문 plain의 문자와 비교를 해야 하는 문자들만 복호화 하는 방법을 사용한다.

*/

string characters; //평문 및 암호문을 구성하는 문자를 순서대로 나열한 문자열
string plain; //평문
string encrypted; //암호문 (암호문을 복호화 한 결과에 평문이 정확하게 하나 등장해야 한다.)
char decrypt[128]; //문자 복호 (시프트 값에 따라 암호문의 문자를 복호화 한 문자를 나타낸다.) (decrypt[암호문 내 문자] = 복호화 된 문자)
vector<int> fVector; //패턴pat의 실패함수 결과

//패턴의 실패함수
vector<int> failure(string& s) {
    vector<int> f(s.size());

    int j = 0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j]) j = f[j-1];
        if (s[i]==s[j]) f[i] = ++j;
    } //i loop

    return f;
}

/**plain이 decrypted에 한 번 나타나는지 여부를 반환한다. 이 함수 호출 전 decrypt, fVector는 알맞게 갱신되어야 한다.*/
bool checkUniqueness() {
    int j = 0;
    int numAppearance = 0; //plain이 decrypted에 등장한 횟수
    for (int i=0; i<encrypted.size(); i++) {
        while (j>0 && decrypt[encrypted[i]] != plain[j]) j = fVector[j-1]; //[평문 내 문자]와 비교해야 하는 것은 [암호문 내 문자]가 아니라 [암호문 내 문자를 복호화 한 결과 문자]다.
        if (decrypt[encrypted[i]] == plain[j]) j++;
        if (j == plain.size()) { //str에 pat이 들어있다고 인정된 경우-
            numAppearance++;
            if (numAppearance>1) return false; //plain이 decrypted에 두 번 이상 등장한 경우 KMP 알고리즘을 계속할 이유가 없다.
        }
    } //i loop
    return numAppearance == 1;
}

/**입력받은 shift 인자값에 따라 decrypt 배열을 갱신한다.*/
void setDecrypt(int shift) {
    int j = shift;
    for (int i=0; i<characters.size(); i++) {
        decrypt[characters[j]] = characters[i]; //j번째 문자를 unshift 하면 i번째 문자가 나온다.
        j = (j+1)%characters.size();
    } //i loop
}

/**각 테스트 케이스. 필요한 문자열 세 개를 입력받아 그 결과를 한 줄로 출력한다.*/
void test() {
    //필요한 문자열 세 개를 입력받는다.
    cin >> characters >> plain >> encrypted;


    //입력받은 plain에 따라 fVector를 갱신한다.
    fVector = failure(plain);


    vector<int> possibleShifts; //카이사르 암호를 만들 때 사용 가능한 시프트 값의 목록
    for (int shift=0; shift<characters.size(); shift++) {
        //각 shift값에 따라 복호 규칙을 설정한 후 (decrypt 배열 갱신) KMP 알고리즘을 적용한다.
        setDecrypt(shift);
        if (checkUniqueness())
            possibleShifts.push_back(shift);
    } //shift loop

    //사용 가능한 시프트 값의 개수에 따라 그 결과를 달리 출력한다.
    switch (possibleShifts.size()) {
        case 0:
            cout << "no solution\n";
            break;
        case 1:
            cout << "unique: " << possibleShifts[0] << '\n';
            break;
        default:
            cout << "ambiguous:";
            for (int possibleShift:possibleShifts) {
                cout << ' ' << possibleShift;
            }
            cout << '\n';
            break;
    }
}


int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++) {
        test();
    }
    return 0;
}
