#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, pair<int, int>> profiles; //특정 정수가 수열에 들어있는 개수 및 첫 등장하는 위치를 담는 맵
									//value.first: key가 수열에 들어있는 개수
									//value.second: key가 수열에 첫 등장하는 위치

struct FreqNode {
	int freq;
	int idx;
	int elem;
};

string toString(FreqNode freqNode) {
	return "["+to_string(freqNode.freq)+", "+to_string(freqNode.idx)+", "+to_string(freqNode.elem)+"]";
}

vector<FreqNode> freqNodes;

/**
 * FreqNode를 정렬하되 freq로 우선적으로 정렬하고, freq가 같은 경우 idx로 정렬한다.
 */
bool cmp(const FreqNode& freqNodeA, const FreqNode& freqNodeB) {
	if (freqNodeA.freq!=freqNodeB.freq)
		return freqNodeA.freq>freqNodeB.freq;
	return freqNodeA.idx<freqNodeB.idx;
}

int main() {
	int N, C;
	cin >> N >> C;
	for (int i=0; i<N; i++) {
		int key;
		cin >> key;
		pair<int, int> profile = profiles[key];
		if (profile.first) { //profiles에 이미 key가 등록된 경우
			profiles[key] = {profile.first+1, profile.second};
		} else { //profiles에 key가 등록되지 않은 경우 (profiles에 key를 처음으로 등록하는 경우)
			profiles[key] = {1, i};
		}
	} //i loop
	
	for (auto iter:profiles) { //range-based loop for map
		FreqNode freqNode = {iter.second.first, iter.second.second, iter.first};
		freqNodes.push_back(freqNode);
	}
	sort(freqNodes.begin(), freqNodes.end(), cmp); //to sort std::vector
	//cout << "Sorting freqNodes done.\n";
	
	int sorted[N];
	int accumIdx=0;
	int sortedIdx=0;
	for (FreqNode freqNode:freqNodes) {
		for (sortedIdx=accumIdx; sortedIdx<accumIdx+freqNode.freq; sortedIdx++) {
			sorted[sortedIdx] = freqNode.elem;
		}
		accumIdx=sortedIdx;
	}
	for (int elem:sorted) {
		cout << elem << ' ';
	}	
	return 0;
}