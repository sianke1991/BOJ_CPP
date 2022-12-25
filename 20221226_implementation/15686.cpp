#include <iostream>
#include <vector>
#include<stdlib.h>

using namespace std;
/**
 * 집을 표현하기 위한 구조체
 */
struct House {
	int row;
	int col;
};

/**
 * 치킨집을 표현하기 위한 구조체
 */
struct Chicken {
	int row;
	int col;
};

vector<House> houses;
vector<Chicken> chickens;
int N; //도시의 크기
int M; //유지시킬 치킨집의 개수
int minChickenDistance = 2147483647;

/**
 * 정수 binary의 idx 위치의 비트가 1인지 여부를 반환한다.<br/>
 * 비트의 위치는 LSB를 0으로 둔다.
 */
bool isBitOnAt(int idx, int binary) {
	return ((1<<idx)&binary)!=0;
}

/**
 * 입력받은 정수에 비트1이 M 개 있는지 여부를 반환한다.
 */
bool areMBitsOn(int binary) {
	int numBits = 0;
	while (binary) {
		numBits+=(binary%2);
		binary>>=1;
	}
	return numBits==M;
}

/**
 * 집과 치킨집 사이의 거리를 계산하여 반환한다.
 */
int distanceBetween(House house, Chicken chicken) {
	return abs(house.row-chicken.row)+abs(house.col-chicken.col);
}

/**
 * 특정 집에서 측정한 치킨거리값을 반환한다. (폐업하지 않고 남기로 선택된 치킨집 정보를 넘겨주어야 한다.)<br/>
 * 0번 치킨집, 2번 치킨집, 3번 치킨집을 유지한다면 13(=0b1101)을 chickenSelected 값으로 넘겨준다.
 */
int distanceFrom(House house, int chickenSelected) {
	int result = 2*N;
	for (int idx=0; idx<13; idx++) {
		if (!isBitOnAt(idx, chickenSelected)) continue; //idx 번째 치킨집을 폐업하기로 한 경우-
		int distance = distanceBetween(house, chickens[idx]);
		if (distance<result) result = distance;
	} //idx loop (각 치킨집 루프)
	return result;
}

/**
 * 폐업시키지 않고 남기기로 한 치킨집 정보를 사용하여 치킨거리 값을 계산 후 반환한다.<br/>
 * 0번 치킨집, 2번 치킨집, 3번 치킨집을 유지한다면 13(=0b1101)을 chickenSelected 값으로 넘겨준다.
 */
int distanceWith(int chickenSelected) {
	int result = 0;
	for (House house:houses) {
		result += distanceFrom(house, chickenSelected);
	} //house loop
	return result;
}

int main() {
	cin >> N >> M;
	for (int row=0; row<N; row++) {
		for (int col=0; col<N; col++) {
			int map; //row행 col열의 정보를 담기 위한 임시 변수
			cin >> map;
			switch (map) {
				case 1: { //해당 위치에 놓여있는 것이 집인 경우 
					House house = {row, col};
					houses.push_back(house);
					break;
				}
				case 2: { //해당 위치에 놓여있는 것이 치킨집인 경우
					Chicken chicken = {row, col};
					chickens.push_back(chicken);
					break;
				}
			} //switch
		} //col loop
	} //row loop
	int numChickens = chickens.size();
	for (int chickenSelected=0; chickenSelected<(1<<numChickens); chickenSelected++) {
		if (!areMBitsOn(chickenSelected)) continue; //치킨집이 M개 선택된 경우가 아니라면-
		int chickenDistance = distanceWith(chickenSelected);
		if (chickenDistance<minChickenDistance) {
//			cout << chickenSelected << '\n';
			minChickenDistance = chickenDistance;
		}
	} //chickenSelected loop
	
	cout << minChickenDistance;
	return 0;
}