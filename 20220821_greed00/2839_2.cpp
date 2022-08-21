#include <iostream>

using namespace std;
int dpArray[5001] = {0, 100000, 100000, 1, 100000, 1};
int min(int num0, int num1){
	return num0<num1 ? num0 : num1;
}

int main() {
	int N;
	cin >> N;
	for (int i=6; i<=N; i++){
		dpArray[i] = min(dpArray[i-3], dpArray[i-5])+1;
	}
	if (dpArray[N]>=100000) cout << -1;
	else cout << dpArray[N];
	
	return 0;
}