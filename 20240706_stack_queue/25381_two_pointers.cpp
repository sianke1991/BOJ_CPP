#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/**
 문자열의 우측 끝에서부터 AB, BC 쌍을 제거하는 방법 - Two Pointer 방법 사용
 문자열의 우측 끝부터 쌍을 제거하려면 AB 쌍을 제거하고 그 뒤에 BC 쌍을 제거해야 한다.
 e.g. BABC
 문자열 우측 끝의 BC를 먼저 제거하면 남은 BA를 제거할 수 없다.
 문자열 우측 끝의 AB를 먼저 제거하면 남은 BC를 제거할 수 있다.
 */
int main() {
	char input[300001];
	scanf("%s", input);
	const int len = strlen(input);
	int result = 0;
	bool used[300001] = {false};
	int leftIndex = len-1, rightIndex = len-1; //leftIndex: 문자열 내에서 'A'를 찾는 인덱스, rightIndex: 문자열 내에서 'B'를 찾는 인덱스
	while (leftIndex>=0) {
		bool aFound = false, bFound = false;
		for (; leftIndex>=0; leftIndex--) {
			if (input[leftIndex]=='A' && !used[leftIndex]) {
				aFound = true;
				break;
			}
		} //leftIndex loop
		for (; rightIndex>leftIndex; rightIndex--) {
			if (input[rightIndex]=='B' && !used[rightIndex]) {
				bFound = true;
				break;
			}
		} //rightIndex loop
		if (aFound && bFound) {
			result++;
			used[leftIndex] = true;
			used[rightIndex] = true;
		}
		leftIndex--; //문자열 내에서 'B'를 찾지 못했다면 강제로 leftIndex를 왼쪽으로 이동시켜야 한다.
	} //while loop
	leftIndex = len-1, rightIndex = len-1; //leftIndex: 문자열 내에서 'B'를 찾는 인덱스, rightIndex: 문자열 내에서 'C'를 찾는 인덱스
	while (leftIndex>=0) {
		bool bFound = false, cFound = false;
		for (; leftIndex>=0; leftIndex--) {
			if (input[leftIndex]=='B' && !used[leftIndex]) {
				bFound = true;
				break;
			}
		} //leftIndex loop
		for (; rightIndex>leftIndex; rightIndex--) {
			if (input[rightIndex]=='C' && !used[rightIndex]) {
				cFound = true;
				break;
			}
		} //rightIndex loop
		if (bFound && cFound) {
			result++;
			used[leftIndex] = true;
			used[rightIndex] = true;
		}
		leftIndex--; //문자열 내에서 'C'를 찾지 못했다면 강제로 leftIndex를 왼쪽으로 이동시켜야 한다.
	} //while loop
	printf("%d", result);
	return 0;
}
