#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dpArray[1000][1000]; //두 문자열을 각각 i글자, j글자를 취했을 때 LCS의 길이

int main() {
	string strA, strB;
	cin >> strA >> strB;

	//초기값 설정
	dpArray[0][0] = strA[0]==strB[0];
	for (int i=1; i<strB.length(); i++) { //strA에서는 한 글자만 선택한 경우
		dpArray[0][i] = dpArray[0][i-1] || strA[0]==strB[i];
	} //i loop
	for (int i=1; i<strA.length(); i++) { //strB에서는 한 글자만 선택한 경우
		dpArray[i][0] = dpArray[i-1][0] || strA[i]==strB[0];
	} //i loop
	
	//점화식 설정
	for (int i=1; i<strA.length(); i++) {
		for (int j=1; j<strB.length(); j++) {
			if (strA[i]==strB[j]) dpArray[i][j] = dpArray[i-1][j-1]+1; //새로 조회하는 두 문자가 서로 같으면 그 문자는 LCS에 반드시 포함하게 된다.
			else dpArray[i][j] = max(dpArray[i-1][j], dpArray[i][j-1]);
		} //j loop
	} //i loop
	
	cout << dpArray[strA.length()-1][strB.length()-1];
	return 0;
}