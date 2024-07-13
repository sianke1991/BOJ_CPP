#include <stdio.h>
#include <string.h>

//user input
char input[41];
//�� ���� ��ġ�� ���ؼ�, �ش� ���ڸ� ������ ���� �κ� ���ڿ��� ������ �� �ִ� ����� ��
//char* input = "123"�� ��
//dpArray[0] := "123"�� ������ �� �ִ� ����� ��
//dpArray[1] := "23"�� ������ �� �ִ� ����� ��
//dpArray[2] := "3"�� ������ �� �ִ� ����� ��
//���� 0���� �����ϴ� ���� ������ �� ������ �����Ѵ�.
//�ش� ���� �ϳ��� ī�� �ϳ��� ǥ���ϴ� ��찡 �ְ�, Ȥ��
//�ش� ���� �ϳ��� ���� ���� �ϳ��� ī�� �ϳ��� ǥ���ϴ� ��찡 �ִ�.
long long dpArray[41];

//�Է� ���� ��ġ�� �ִ� ���ڿ� ���� ��ġ�� �ִ� ���ڸ� �̾� �ٿ���
//������ ������ ��ȯ�Ѵ�.
int twoDigitInt(int idx) {
	return (input[idx]-'0')*10 + (input[idx+1]-'0');
}

int main() {
	scanf("%s", input);
	const int LEN = strlen(input);
	dpArray[LEN] = 1;
	//initial condition
	//if the last digit is not zero, there exists one way to represent it.
	if (input[LEN-1]!='0')
		dpArray[LEN-1] = 1;
    //��ȭ��
    //�ش� ��ġ�� �ִ� ���ڰ� '0'�� ��� 0���� �����ϴ� ���̰�, �� ���� ǥ���� �� ����.
    //�ش� ��ġ�� �ִ� ���� �ϳ��� ī�� �ϳ��� ǥ���ϴ� ��츦 �ϴ� ����ϰ�,
    //�ش� ��ġ�� �ִ� ���� �ϳ��� ���� ��ġ�� �ִ� ���� �ϳ�, �� ���� �� ������
    //ī�� �ϳ��� ǥ���ϴ� ��츦 ����Ѵ�.
	for (int i=LEN-2; i>=0; i--) {
		if (input[i]=='0') continue;
		dpArray[i] = dpArray[i+1];
		if (twoDigitInt(i)<=34) dpArray[i] += dpArray[i+2];
	} //i loop
	printf("%lld\n", dpArray[0]);
	/*
	for (int i=0; i<LEN; i++) {
		printf("%lld ", dpArray[i]);
	}
	*/
	return 0;
}
