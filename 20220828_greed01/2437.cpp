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