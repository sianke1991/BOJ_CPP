#include <string>
#include <iostream>

using namespace std;


/**
 * 문자열 A 안에 문자열 B가 포함이 되는지 여부를 판단한다.
 */
bool find (string& A, string& B) {
    int lenA = A.size(), lenB = B.size();
    if (lenB>lenA) return false;

    for (int i=0; i<=lenA-lenB; i++) {
        if (A.substr(i, lenB)==B) return true; //substr 함수는 (시작 인덱스, 잘라낼 문자열의 길이)를 인자로 받는다.
    }
    return false;
}


int main() {

    string A = "ORONDONTISS";
    string B = "NTI";
    cout << find(A, B);
    return 0;

}


