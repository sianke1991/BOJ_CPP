#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int PREDATOR_CD	= 0;
const int PREY_CD		= 1;

vector<int> results;
vector<pair<int, int>> creatures;

bool isPrey(pair<int, int> creature) {
	return creature.second == PREY_CD;
}

int main() {
	int T;
	cin >> T;
	for (int testCase=0; testCase<T; testCase++) {
		int N, M;
		cin >> N >> M;
		for (int i=0; i<N; i++) {
			int predatorSize;
			cin >> predatorSize;
			creatures.push_back({predatorSize, PREDATOR_CD});
		}
		for (int i=0; i<M; i++) {
			int preySize;
			cin >> preySize;
			creatures.push_back({preySize, PREY_CD});
		}
		sort(creatures.begin(), creatures.end()); //to sort std::vector
		
		int result = 0; //성립할 수 있는 포식자-먹이 쌍의 개수
		int localSum = 0; //현재 잡아먹힐 수 있는 먹이의 개수
		for (pair<int, int>creature:creatures) {
			if (isPrey(creature)) {
				localSum++;
			} else {
				result+=localSum;
			}
		} //creature loop
		results.push_back(result);
		creatures.clear();
	} //testCase loop
	
	for (int result:results) {
		cout << result << '\n';
	} //result loop
	return 0;
}