#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> enteredNames;
	vector<string> leftNames;
	
	string nameInput, actionInput;
	for (int i=0; i<n; i++) {
		cin >> nameInput >> actionInput;
		if (actionInput=="enter") {
			enteredNames.push_back(nameInput);
		} else {
			leftNames.push_back(nameInput);
		}
	} //i loop
	sort(enteredNames.begin(), enteredNames.end()); //출근 사원 이름 정렬
	vector<string> uniqueNames(enteredNames.begin(), enteredNames.end()); //정렬된 출근 사원 이름을 그대로 받아서 새 vector를 만든다.
	sort(leftNames.begin(), leftNames.end()); //퇴근 사원 이름 정렬
	unique(uniqueNames.begin(), uniqueNames.end()); //출근 사원 이름에서 중복 제거
	vector<string> remainingNames;
	for (string name:uniqueNames) {
		//출근 횟수가 퇴근 횟수보다 많은 사원은 아직 회사에 남은 것이다.
		//정렬된 벡터에서 특정 원소의 개수는 다음과 같이 구할 수 있다.
		//upper_bound(vec.begin(), vec.end(), elem) - lower_bound(vec.begin(), vec.end(), elem) 
		if (upper_bound(enteredNames.begin(), enteredNames.end(), name)-lower_bound(enteredNames.begin(), enteredNames.end(), name) > upper_bound(leftNames.begin(), leftNames.end(), name)-lower_bound(leftNames.begin(), leftNames.end(), name)) {
			remainingNames.push_back(name);
		}
	}
	sort(remainingNames.begin(), remainingNames.end(), greater<string>());
	for (string name:remainingNames) {
		cout << name << '\n';
	}		
	return 0;	
}