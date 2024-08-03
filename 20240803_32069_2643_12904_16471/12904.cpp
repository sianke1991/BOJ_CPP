#include <stdio.h>
#include <string.h>


//���ڿ��� �ڿ� A�� �߰��ϴ� ������ ���� A,
//���ڿ��� ������ B�� �߰��ϴ� ������ ���� B��� �� ��
//Ư�� ���ڿ��� ���� �� �������� ����� ������ ������ �� �� �ִ�.
//Ư�� ���ڿ��� A�� �����ٸ� �ش� ���ڿ����� �������� ���� A��,
//Ư�� ���ڿ��� B�� �����ٸ� �ش� ���ڿ����� �������� ���� B�� ����� ���̴�.
//���� �� ���ڿ����� ������ �ϳ� �� undo �ϸ鼭 ���� �� ���ڿ��� ���� �� �ִ��� ���θ� �����Ѵ�.

/**
 * �Է¹��� ���ڿ��� �����´�.
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

    //���ڿ� T�� ����� ������ �������� undo �Ѵ�,
    //���� A�� undo�� ������ ���� �ϳ��� �����ϴ� ���̴�.
    //���� B�� undo�� ������ ���� �ϳ��� �����ϰ� ���� ���ڿ��� ������ ���̴�.
    for (int i=1, lim=lenT-lenS; i<=lim; i++) {
        if (T[lenT-i]=='B') {
            rev(T, lenT-i);
        }
    }

    //���ڿ� S�� T�� ���� �������� ��-
    for (int i=0; i<lenS; i++) {
        if (S[i]!=T[i]) {
            printf("0");
            return 0;
        }
    }

    printf("1");
    return 0;
}
