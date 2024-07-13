#include <stdio.h>
#include <string.h>

//user input
char input[41];
//각 숫자 위치에 대해서, 해당 숫자를 포함한 우측 부분 문자열을 구성할 수 있는 경우의 수
//char* input = "123"일 때
//dpArray[0] := "123"을 구성할 수 있는 경우의 수
//dpArray[1] := "23"을 구성할 수 있는 경우의 수
//dpArray[2] := "3"을 구성할 수 있는 경우의 수
//숫자 0으로 시작하는 수는 구성할 수 없음에 주의한다.
//해당 숫자 하나를 카드 하나로 표현하는 경우가 있고, 혹은
//해당 숫자 하나와 다음 숫자 하나를 카드 하나로 표현하는 경우가 있다.
long long dpArray[41];

//입력 받은 위치에 있는 숫자와 다음 위치에 있는 숫자를 이어 붙여서
//나오는 정수를 반환한다.
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
    //점화식
    //해당 위치에 있는 숫자가 '0'인 경우 0으로 시작하는 수이고, 이 수는 표현할 수 없다.
    //해당 위치에 있는 숫자 하나를 카드 하나로 표현하는 경우를 일단 고려하고,
    //해당 위치에 있는 숫자 하나와 다음 위치에 있는 숫자 하나, 즉 숫자 두 개리를
    //카드 하나로 표현하는 경우를 고려한다.
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
