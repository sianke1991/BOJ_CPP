#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	//현재 선택할 수 있는 회위 중에서 가장 이른 시각에 끝나는 회의를 선택한다.
	//그래야 그 회의가 끝나고 진행할 수 있는 회의의 수를 최대로 할 수 있다.
	//위와 같은 이유로 입력 받은 회의의 정보를 정렬할 때 종료 시각을 기준으로 잡아야 한다.
	
	int N;
	cin >> N;
	vector<pair<int, int>> vec;
	for (int i=0; i<N; i++) {
		pair<int, int> p;
		cin >> p.second >> p.first; //정렬 시 회의 종료 시각이 더 우선순위가 높아야 하므로 종료 시각이 first가 되도록 데이터를 받는다.
		vec.push_back(p);
	}
	
	sort(vec.begin(), vec.end());

	int currentTime = 0, cnt = 0;
	for (int i=0; i<N; i++) {
		pair<int, int> p = vec[i];
		if (p.second < currentTime) continue; //회의 시작 시각이 현재 시각보다 이전이면 해당 회의는 고려하지 않는다.
											//(현재 시각은 해당 회의를 시작하기에 너무 늦은 것이다.)
		currentTime = p.first; //해당 회의를 선택했으면 해당 회의 종료 시각 부터 다음 회의를 잡을 수 있다.
		cnt++;
	}
	cout << cnt;
	
	return 0;
}