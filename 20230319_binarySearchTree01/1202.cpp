#include <bits/stdc++.h>

using namespace std;

string toString(pair<int, int> gem) {
	return "[" + to_string(gem.first) + ", " + to_string(gem.second) + "]";
}
/*
보석은 가치있는 것부터 담고,
담을 보석에 대해 가방은 용량이 작은 것 부터 사용한다.
*/
int main() {
	int numGems, numBags;
	cin >> numGems >> numBags;
	vector<pair<long long, int>> gems; //보석의 가치를 first 값으로, 보석의 질량을 second 값으로 넣는다.
	multiset<int> bags;
	for (int i=0; i<numGems; i++) {
		int mass;
		long long value;
		cin >> mass >> value;
		gems.push_back({-value, mass}); //가치가 높은 보석이 인덱스가 낮은 위치에 가도록 음의 부호를 붙인다.
	} //i loop
	sort(gems.begin(), gems.end()); //보석의 정렬
	for (int i=0; i<numBags; i++) {
		int capacity;
		cin >> capacity;
		bags.insert(capacity);
	}
	long long sumValues = 0; //int 사용 시 오버플로가 발생할 수 있다.
	for (pair<int, int> gem:gems) {
		set<int>::iterator bag = bags.lower_bound(gem.second);
		if (bag==bags.end()) continue; //해당 보석을 담을 보석을 찾지 못할 경우 해당 보석은 스킵한다.
		sumValues -= gem.first; //현재 보석의 가치는 음수로 되어 있으므로 보석의 가치만큼 빼야 값이 증가한다.
		bags.erase(bag); //가방 더미에서 사용할 가방을 제거한다. (사용할 가방은 다시 사용할 수 없다.)
	} //gem loop
    
    cout << sumValues;
    return 0;
}
