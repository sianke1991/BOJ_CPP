#include <stdio.h>
#include <string.h>


//문자열의 뒤에 A를 추가하는 연산을 연산 A,
//문자열을 뒤집고 B를 추가하는 연산을 연산 B라고 할 때
//특정 문자열을 보고 맨 마지막에 적용된 연산의 종류를 알 수 있다.
//특정 문자열이 A로 끝났다면 해당 문자열에는 마지막에 연산 A가,
//특정 문자열이 B로 끝났다면 해당 문자열에는 마지막에 연산 B가 적용된 것이다.
//연산 후 문자열에서 연산을 하나 씩 undo 하면서 연산 전 문자열이 나올 수 있는지 여부를 조사한다.

/**
 * 입력받은 문자열을 뒤집는다.
 */
void rev(char* str, int len) {
    for (int i=0, lim=len/2; i<lim; i++) {
        int j=len-1-i;
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

int main() {
    char S[1001];
    char T[1001];
    scanf("%s", S);
    scanf("%s", T);
    const int lenS = strlen(S);
    const int lenT = strlen(T);

    //문자열 T에 적용된 연산을 역순으로 undo 한다,
    //연산 A의 undo는 마지막 문자 하나를 제거하는 것이다.
    //연산 B의 undo는 마지막 문자 하나를 제거하고 남은 문자열을 뒤집는 것이다.
    for (int i=1, lim=lenT-lenS; i<=lim; i++) {
        if (T[lenT-i]=='B') {
            rev(T, lenT-i);
        }
    }

    //문자열 S와 T가 서로 동일한지 비교-
    for (int i=0; i<lenS; i++) {
        if (S[i]!=T[i]) {
            printf("0");
            return 0;
        }
    }

    printf("1");
    return 0;
}
