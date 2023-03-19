#include <bits/stdc++.h>

using namespace std;
/*
보석은 가치있는 것부터 담고,
담을 보석에 대해 가방은 용량이 작은 것 부터 사용한다.
*/
int main() {
	int numGems, numBags;
	cin >> numGems >> numBags;
	vector<pair<int, int>> gems; //보석의 가치를 first 값으로, 보석의 질량을 second 값으로 넣는다.
	vector<pair<int, bool>> bags; //가방의 사용 가능 여부를 second 값으로 넣는다.
	for (int i=0; i<numGems; i++) {
		int mass, value;
		cin >> mass >> value;
		gems.push_back({-value, mass}); //가치가 높은 보석이 인덱스가 낮은 위치에 가도록 음의 부호를 붙인다.
	} //i loop
	sort(gems.begin(), gems.end()); //보석의 정렬
	for (int i=0; i<numBags; i++) {
		int capacity;
		cin >> capacity;
		bags.push_back({capacity, true});
	}
	sort(bags.begin(), bags.end()); //가방의 정렬 (용량이 작은 가방이 인덱스가 낮은 위치에 간다.)
	int sumValues = 0;
	for (pair<int, int> gem:gems) {
		for (pair<int, bool>& bag:bags) {
			if (bag.second && bag.first>=gem.second) { //해당 보석을 담을 가방을 찾으면-
				sumValues -= (gem.first); //현재 보석의 가치는 음수로 되어 있으므로 보석의 가치만큼 빼야 값이 증가한다.
				bag.second = false; //가방 더미에서 사용할 가방을 제거한다. (사용할 가방은 다시 사용할 수 없다.)
				break; //가방 루프는 더 이상 돌 필요가 없다.
			}
		} //bag loop
	} //gem loop
    
    cout << sumValues;
    return 0;
}
