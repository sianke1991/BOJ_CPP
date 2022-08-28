#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int height[N];
	for (int i=0; i<N; i++) {
		cin >> height[i];
	}
	
	int localHighest = 0;
	int maxNumHits = 0;
	for (int i=0; i<N; i++) {
		if (localHighest<height[i]){
			localHighest = height[i];
			int localNumHits = 0;
			for (int j=i+1; j<N; j++) {
				if (height[i]<localHighest) localNumHits++;
				else if (height[i]>localHighest) break;
			} //j loop
			if (maxNumHits<localHighest) maxNumHits = localHighest;
		}
	} //i loop
	
	cout << maxNumHits;
	return 0;	
}