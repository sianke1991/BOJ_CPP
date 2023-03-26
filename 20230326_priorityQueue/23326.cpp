#include <bits/stdc++.h>

using namespace std;

/*
Ư�� ������ ������� �ƴ����� �����ϴ� ����� ���� ������ ������,
(e.g. boolean �迭�� ����Ͽ� Ư�� �ε����� �ش��ϴ� ������ ������� ���θ� ����)
Ư�� ��ġ���� ���� ����� ��Ҹ� ������ ã�� ���� binary search�� ������ �ڷᱸ���� �����Ѵ�.
���⼭�� ��Ҹ� ��Ƴ��� ���� �ڷ���(TreeSet)�� ����Ѵ�.
����� ������ �ߺ��� ����� �ʿ䰡 �����Ƿ� MultiSet ��� Set�� ����Ѵ�.
*/

int main() {
    int numAreas, numQueries;
    int currentArea = 0; //�����̰� ���� ��ġ�� �� (0-base index�� ����Ѵ�.)
    set<int> famousAreas; //��� ���� (�� ���տ� ���� �ְ� �����ν� ��ҷ� ����, ��Ҹ� ������ �� �ִ�.)
    vector<int> results; //3�� ������ ���� ���� �����ϴ� ����

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
            case 1: { //��� ���� �� ����
                int areaIdx;
                cin >> areaIdx;
                if (famousAreas.find(areaIdx-1)!=famousAreas.end()) {
                    famousAreas.erase(areaIdx-1);
                } else {
                    famousAreas.insert(areaIdx-1);
                }
                break;
            }
            case 2: { //�������� �
                int numMoves;
                cin >> numMoves;
                currentArea = (currentArea+numMoves)%numAreas;
                break;
            }
            case 3: { //���� ����� ��Ҹ� ���� ���� �������� �ϴ� �ּ� ĭ �� ��ȸ
                set<int>::iterator it = famousAreas.lower_bound(currentArea);
                if (it!=famousAreas.end()) {
                    results.push_back((*it)-currentArea);
                    break;
                }
                it = famousAreas.lower_bound(0); //famousAreas.lower_bound(0) ��ſ� famousAreas.begin()�� ����ؼ� ��� ���� �� �ּ�ġ�� ã�� �� �ִ�.
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
