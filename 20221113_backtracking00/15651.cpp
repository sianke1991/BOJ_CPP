#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> resultList;
int N, M;
int selectedNumbers[7];

void recursive(int depth) {
	if (depth==M) {
		string lsCase = "";
		for (int i=0; i<M; i++) {
			lsCase += to_string(selectedNumbers[i])+" ";
		} //i loop
		resultList.push_back(lsCase);
		return;
	}
	
	for (int i=1; i<=N; i++) {
		selectedNumbers[depth] = i;
		recursive(depth+1);
	} //i loop
}

int main() {
	cin >> N >> M;
	recursive(0);
	for (string lsCase:resultList) {
		cout << lsCase << '\n';
	}
	return 0;
}