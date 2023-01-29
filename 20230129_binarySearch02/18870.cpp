#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n; //��ǥ ����
vector<int> coordinates;
vector<int> sortedCoordinates;
vector<int> uniqueCoordinates;
vector<int> results;

int main() {
    cin >> n;
    //��ǥ �Է�
    {
        int coor;
        for (int i=0; i<n; i++) {
            cin >> coor;
            coordinates.push_back(coor);
            sortedCoordinates.push_back(coor);
        }
    }
    //���� ����
    sort(sortedCoordinates.begin(), sortedCoordinates.end());
    //�ߺ� ����
    for (int i=0; i<sortedCoordinates.size()-1; i++) {
        if (sortedCoordinates[i]==sortedCoordinates[i+1]) continue;
        uniqueCoordinates.push_back(sortedCoordinates[i]);
    }
    uniqueCoordinates.push_back(sortedCoordinates[sortedCoordinates.size()-1]);

    //STL�� ����� �ߺ� ����
    //sortedCoordinates.erase(unique(sortedCoordinates.begin(), sortedCoordinates.end()), sortedCoordinates.end());
    //unique �Լ��� ���ĵ� �迭, ���͸� �Է¹޾� �ߺ��� �����ϰ�, ������ ��� �Ǵ� ���� ������ ���� �д�.
    //������ ���� �����ϴ� �ε����� ��ȯ�Ѵ�.

    for (int coordinate:coordinates) {
        auto lowerBound = lower_bound(uniqueCoordinates.begin(), uniqueCoordinates.end(), coordinate);
        results.push_back(lowerBound-uniqueCoordinates.begin());
    }

    for (int result:results) {
        cout << result << ' ';
    }
    return 0;
}
