#include <iostream>

using namespace std;

int dpArray[301]; //dpArray[i]: i 계단에 오르기까지 얻을 수 있는 점수의 최대치
int scoreArr[301]; //scoreArr[i]: 계단 i를 밟을 때 얻게되는 점수

int main() {
	int N; //계단의 개수
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> scoreArr[i];
	}
	
	//초기값 설정
	dpArray[1] = scoreArr[1];
	dpArray[2] = scoreArr[1] + scoreArr[2];
	dpArray[3] = max(scoreArr[1], scoreArr[2]) + scoreArr[3];
	
	//점화식
	for (int i=4; i<=N; i++) {
		dpArray[i] = max(
							scoreArr[i]+scoreArr[i-1]+dpArray[i-3], //바로 직전의 계단을 밟는 경우
							scoreArr[i]+dpArray[i-2] //바로 직전의 계단을 밟지 않는 경우
		);
	} //i loop
	
	cout << dpArray[N];
	return 0;
}
