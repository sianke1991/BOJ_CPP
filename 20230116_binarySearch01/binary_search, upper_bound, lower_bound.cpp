#include <iostream>
#include <algorithm>

using namespace std;

int randNum[] = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};
int len = sizeof(randNum) / sizeof(*randNum);

int lower_idx(int target, int len) { 
	int st = 0; 
	int en = len; 
	while (st < en) { 
		int mid = (st+en)/2; 
		if (randNum[mid] >= target) en = mid; 
		else st = mid+1; 
	} 
	return st; 
} 
int upper_idx(int target, int len) { 
	int st = 0; 
	int en = len; 
	while (st < en) { 
		int mid = (st+en)/2; 
		if (randNum[mid] > target) en = mid; 
		else st = mid+1; 
	} 
	return st; 
}

int main() {
	sort(randNum, randNum+len); //-31983 -30699 -23425 -21475 -18406 -15034 -3231 168 1464 3974 7381 9699 10742 11563 11912 15428 19907 22892 27682 29536
	bool containess0 = binary_search(randNum, randNum+len, -12345);
	bool containess1 = binary_search(randNum, randNum+len, -23425);
	cout << containess0 << '\n'; //0 (false)
	cout << containess1 << '\n'; //1 (true)
	auto upperBound0 = upper_bound(randNum, randNum+len, -21475);
	auto lowerBound0 = lower_bound(randNum, randNum+len, -21475);
	cout << upperBound0-randNum << '\n'; //4 (-21475이하에서 -21475초과로 변하는 공간의 위치)
	cout << lowerBound0-randNum << '\n'; //3 (-21475미만에서 -21475이상으로 변하는 공간의 위치)

	auto upperBound1 = upper_bound(randNum, randNum+len, 123);
	auto lowerBound1 = lower_bound(randNum, randNum+len, 123);
	cout << upperBound1-randNum << '\n'; //7 (123이하에서 123초과로 변하는 공간의 위치)
	cout << lowerBound1-randNum << '\n'; //7 (123미만에서 123이상으로 변하는 공간의 위치)
	
	int lowerIdx0 = lower_idx(-3231, len);
	int upperIdx0 = upper_idx(-3231, len);
	cout << upperIdx0 << '\n'; //7
	cout << lowerIdx0 << '\n'; //6
	
	int lowerIdx1 = lower_idx(123, len);
	int upperIdx1 = upper_idx(123, len);
	cout << upperIdx1 << '\n'; //7
	cout << lowerIdx1 << '\n'; //7	
	return 0;	
}