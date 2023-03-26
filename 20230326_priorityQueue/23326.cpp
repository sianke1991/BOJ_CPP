#include <bits/stdc++.h>

using namespace std;

/*
특정 구역이 명소인지 아닌지를 저장하는 방법이 여러 가지가 있지만,
(e.g. boolean 배열을 사용하여 특정 인덱스에 해당하는 구역이 명소인지 여부를 저장)
특정 위치에서 가장 가까운 명소를 빠르게 찾기 위해 binary search가 가능한 자료구조를 선택한다.
여기서는 명소만 모아놓은 집합 자료형(TreeSet)을 사용한다.
명소의 집합은 중복을 허용할 필요가 없으므로 MultiSet 대신 Set을 사용한다.
*/

int main() {
    int numAreas, numQueries;
    int currentArea = 0; //도현이가 현재 위치한 곳 (0-base index를 사용한다.)
    set<int> famousAreas; //명소 집합 (이 집합에 값을 넣고 뺌으로써 명소로 지정, 명소를 해제할 수 있다.)
    vector<int> results; //3번 쿼리에 대한 답을 저장하는 벡터

    cin >> numAreas >> numQueries;
    for (int areaIdx=0; areaIdx<numAreas; areaIdx++) {
        int isFamous;
        cin >> isFamous;
        if (isFamous) {
            famousAreas.insert(areaIdx);
        }
    } //areaIdx loop
    for (int queryIdx=0; queryIdx<numQueries; queryIdx++) {
        int query;
        cin >> query;
        switch (query) {
            case 1: { //명소 지정 및 해제
                int areaIdx;
                cin >> areaIdx;
                if (famousAreas.find(areaIdx-1)!=famousAreas.end()) {
                    famousAreas.erase(areaIdx-1);
                } else {
                    famousAreas.insert(areaIdx-1);
                }
                break;
            }
            case 2: { //도현이의 운동
                int numMoves;
                cin >> numMoves;
                currentArea = (currentArea+numMoves)%numAreas;
                break;
            }
            case 3: { //가장 가까운 명소를 가기 위해 움직여야 하는 최소 칸 수 조회
                set<int>::iterator it = famousAreas.lower_bound(currentArea);
                if (it!=famousAreas.end()) {
                    results.push_back((*it)-currentArea);
                    break;
                }
                it = famousAreas.lower_bound(0); //famousAreas.lower_bound(0) 대신에 famousAreas.begin()을 사용해서 명소 집합 중 최소치를 찾을 수 있다.
                if (it!=famousAreas.end()) {
                    results.push_back((*it)+numAreas-currentArea);
                    break;
                } else {
                    results.push_back(-1);
                    break;
                }
            }
        } //switch query
    } //queryIdx loop

    for (int result:results) {
        cout << result << '\n';
    }
    return 0;
}
