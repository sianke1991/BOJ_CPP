#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n; //좌표 개수
vector<int> coordinates;
vector<int> sortedCoordinates;
vector<int> uniqueCoordinates;
vector<int> results;

int main() {
    cin >> n;
    //좌표 입력
    {
        int coor;
        for (int i=0; i<n; i++) {
            cin >> coor;
            coordinates.push_back(coor);
            sortedCoordinates.push_back(coor);
        }
    }
    //정렬 수행
    sort(sortedCoordinates.begin(), sortedCoordinates.end());
    //중복 제거
    for (int i=0; i<sortedCoordinates.size()-1; i++) {
        if (sortedCoordinates[i]==sortedCoordinates[i+1]) continue;
        uniqueCoordinates.push_back(sortedCoordinates[i]);
    }
    uniqueCoordinates.push_back(sortedCoordinates[sortedCoordinates.size()-1]);

    //STL을 사용한 중복 제거
    //sortedCoordinates.erase(unique(sortedCoordinates.begin(), sortedCoordinates.end()), sortedCoordinates.end());
    //unique 함수는 정렬된 배열, 벡터를 입력받아 중복을 제거하고, 뒷쪽의 비게 되는 값은 쓰레기 값을 둔다.
    //쓰레기 값이 시작하는 인덱스를 반환한다.

    for (int coordinate:coordinates) {
        auto lowerBound = lower_bound(uniqueCoordinates.begin(), uniqueCoordinates.end(), coordinate);
        results.push_back(lowerBound-uniqueCoordinates.begin());
    }

    for (int result:results) {
        cout << result << ' ';
    }
    return 0;
}
