#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> weights;
	for (int i=0; i<N; i++) {
		int weight;
		cin >> weight;
		weights.push_back(weight);
	}
	
	sort(weights.begin(), weights.end()); //추를 오름차순으로 정렬
	
	int partialSum=1;
	for (int i=0; i<N; i++) {
		if (weights[i] > partialSum) break; // 새로운 추의 질량이 (지금까지 추의 질량의 합 + 1) 보다 크면 그 사이에 측정할 수 없는 간격이 생긴다.
											//(귀납법을 사용하면 증명할 수 있을 것 같으나 아직 증명하지는 않음)
		partialSum += weights[i]; 
	}
	//만약 새로운 추가 (지금까지 추의 질량의 합 + 1) 보다 크지 않는다는 조건을 전부 지키게 되는 경우 partialSum은 (모든 추의 질량의 합 + 1) 이 되고 반복문을 빠져나간다.
	cout << partialSum;
	
	return 0;
}

/*
추 w0, w1, ... wn-1 (wi∈N, wi>0) 에 대해 이 추들을 적절히 조합하여
1, 2, ... , ∑(i∈[0, n-1])wi
의 질량을 측정할 수 있다고 가정하자.
새로운 추 wn=1+∑(i∈[0, n-1])을 사용하여
1, 2, ... , ∑(i∈[0, n])wi 의 질량을 측정할 수 있는가? (즉, 측정할 수 있는 질량의 범위가
[1, ∑(i∈[0, n-1])wi] 에서 [1, ∑(i∈[0, n])wi] 로 확장이 되는가?

=> 새로이 측정할 수 있어야 하는 질량은
wn, wn+1, wn+2, ... , wn+∑(i∈[0, n-1])wi
로 표시할 수 있다.
=> wn짜리 추를 사용할 수 있고, 1, 2, ... , ∑(i∈[0, n-1])wi 는 w0, w1, ... wn-1
짜리 추를 적절히 조합하여 만들 수 있으므로,
wn, wn+1, wn+2, ... , wn+∑(i∈[0, n-1])wi 역시 측정할 수 있다.
*/