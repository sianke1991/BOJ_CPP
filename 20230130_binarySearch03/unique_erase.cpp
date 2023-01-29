#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string toString(vector<int> vec) {
	string result = "[";
	for (int i=0; i<vec.size()-1; i++) {
		result += to_string(vec[i])+", ";
	}
	result += to_string(vec[vec.size()-1]);
	result += "]";
	return result;
}

int main() {
	vector<int> diceResult = {4,5,6,4,5,6,5,5,1,1,2,1,1,5,6,1,4,4,1,5,2,4,4,6,4,5,6,3,4,6,4,5,4,5,5,1,4,2,2,1,6,6,2,5,3,3,4,4,3,5,4,4,6,4,1,1,4,5,5,4,1,6,4,6,6,6,5,2,5,5,6,5,1,2,5,6,3,3,4,1,1,6,1,6,6,2,2,1,3,5,4,1,2,1,6,3,2,1,4,5};
	sort(diceResult.begin(), diceResult.end()); //unique를 통해 중복을 제거하기 전에 정렬을 수행해야 한다. (정렬을 수행하지 않으면 이상한 값이 나오므로 주의한다.)
	cout << toString(diceResult) << '\n';
	/*
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6]
	*/
	auto uq = unique(diceResult.begin(), diceResult.end()); //중복을 제거한다. 제거한 뒤 남은 공간에는 쓰레기 값을 둔다. 쓰레기 값이 시작하는 위치를 반환한다.
	cout << uq-diceResult.begin() << '\n';
	/*
	6 (쓰레기 값이 시작하는 위치)
	*/
	cout << toString(diceResult) << '\n';
	/*
	[1, 2, 3, 4, 5, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6]
	*/
	diceResult.erase(uq, diceResult.end()); //uq부터 end까지의 원소를 제거한다.
	cout << toString(diceResult) << '\n';
	/*
	[1, 2, 3, 4, 5, 6]
	*/
	return 0;
	
	
	
}