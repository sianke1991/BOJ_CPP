#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

/**
 문자열의 좌측 끝에서부터 AB, BC 쌍을 제거하는 방법 - Queue 사용
 문자열의 우측 끝부터 쌍을 제거하려면 BC 쌍을 제거하고 그 뒤에 AB 쌍을 제거해야 한다.
 e.g. ABCB
 문자열 좌측 끝의 AB를 먼저 제거하면 남은 CB를 제거할 수 없다.
 문자열 좌측 끝의 BC를 먼저 제거하면 남은 AB를 제거할 수 있다.
 */
int main() {
	char input[300001];
	scanf("%s", input);
	int result = 0;
	queue<int> aIndices; //문자 'A'의 인덱스를 담는다. (AB 짝을 만드면 해당 인덱스는 큐에서 제거한다.)
	queue<int> bIndices;
	queue<int> cIndices;
	for (int i=0; input[i]!='\0'; i++) {
		switch (input[i]) {
			case 'A': aIndices.push(i); break;
			case 'B': bIndices.push(i); break;
			case 'C': cIndices.push(i); break;
		} //switch-case
	} //i loop

	//remove bc pairs first
	while (!bIndices.empty() && !cIndices.empty()) {
		if (bIndices.front()<cIndices.front()) {
			result++;
			bIndices.pop();
			cIndices.pop();
		} else {
			cIndices.pop(); //c의 인덱스가 b의 인덱스보다 작다면, 해당 c의 인덱스는 문자열에서 제거될 수 없다.
		}
	} //while loop

	//next remove ab pairs
	while (!aIndices.empty() && !bIndices.empty()) {
		if (aIndices.front()<bIndices.front()) {
			result++;
			aIndices.pop();
			bIndices.pop();
		} else {
			bIndices.pop();
		}
	}

	printf("%d", result);
	return 0;
}
