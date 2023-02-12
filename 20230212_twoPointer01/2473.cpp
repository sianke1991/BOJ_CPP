#include <iostream>
#include <algorithm>
#include <cstdlib> //for the function abs

using namespace std;

int main() {
	int N; //용액의 개수
	cin >> N;
	long long solutions[N]; //각 용액의 특성값 배열
	for (int i=0; i<N; i++) {
		cin >> solutions[i];
	} //i loop
	sort(solutions, solutions+N);
	
	long long optVal = 9223372036854775807LL;
	long long optCase[3];
	long long currentVal;
	
	int idxChosenOne = 0;
	int idxLeft = idxChosenOne+1;
	int idxRight = N-1;
	for (idxChosenOne=0; idxChosenOne<N-2; idxChosenOne++) { //세 용액을 선택할 때 한 용액은 우선 선택하고 남은 두 용액을 선택할 때 two-pointer을 사용한다.
		idxLeft = idxChosenOne+1;
		idxRight = N-1;
		while (idxRight>idxLeft) {
			currentVal = solutions[idxChosenOne]+solutions[idxLeft]+solutions[idxRight];
			if (abs(currentVal)<abs(optVal)) {
				optVal = currentVal;
				optCase[0] = solutions[idxChosenOne];
				optCase[1] = solutions[idxLeft];
				optCase[2] = solutions[idxRight];
			}
			
			if (currentVal<0) { //용액 합계가 음수인 경우 idxLeft를 증가시킨다.
				idxLeft++;
			} else if (currentVal>0) { //용액 합계가 양수인 경우 idxRight를 감소시킨다.
				idxRight--;
			} else { //용액 합계가 0인 경우 최적을 찾은 것이다.
				cout << optCase[0] << ' ' << optCase[1] << ' ' << optCase[2];
				return 0;
			}
		} //while loop
	} //idxChosenOne loop
	
	cout << optCase[0] << ' ' << optCase[1] << ' ' << optCase[2];
	return 0;
}