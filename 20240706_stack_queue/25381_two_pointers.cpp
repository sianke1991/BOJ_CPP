#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/**
 ���ڿ��� ���� ���������� AB, BC ���� �����ϴ� ��� - Two Pointer ��� ���
 ���ڿ��� ���� ������ ���� �����Ϸ��� AB ���� �����ϰ� �� �ڿ� BC ���� �����ؾ� �Ѵ�.
 e.g. BABC
 ���ڿ� ���� ���� BC�� ���� �����ϸ� ���� BA�� ������ �� ����.
 ���ڿ� ���� ���� AB�� ���� �����ϸ� ���� BC�� ������ �� �ִ�.
 */
int main() {
	char input[300001];
	scanf("%s", input);
	const int len = strlen(input);
	int result = 0;
	bool used[300001] = {false};
	int leftIndex = len-1, rightIndex = len-1; //leftIndex: ���ڿ� ������ 'A'�� ã�� �ε���, rightIndex: ���ڿ� ������ 'B'�� ã�� �ε���
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
		leftIndex--; //���ڿ� ������ 'B'�� ã�� ���ߴٸ� ������ leftIndex�� �������� �̵����Ѿ� �Ѵ�.
	} //while loop
	leftIndex = len-1, rightIndex = len-1; //leftIndex: ���ڿ� ������ 'B'�� ã�� �ε���, rightIndex: ���ڿ� ������ 'C'�� ã�� �ε���
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
		leftIndex--; //���ڿ� ������ 'C'�� ã�� ���ߴٸ� ������ leftIndex�� �������� �̵����Ѿ� �Ѵ�.
	} //while loop
	printf("%d", result);
	return 0;
}
