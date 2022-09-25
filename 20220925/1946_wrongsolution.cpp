#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    int T;
    cin >> T;
    int result[T];

    for (int testCase=0; testCase<T; testCase++) {
        int N;
        cin >> N;
        vector <array<int, 2>> members;
        array<int, 2> bestRank0 = {N+1, N+1}; //�ְ� ���� ������
        array<int, 2> bestRank1 = {N+1, N+1}; //�ְ� ���� ������
        int numSelected = 0;
        for (int i=0; i<N; i++) {
            int liRank0, liRank1;
            cin >> liRank0 >> liRank1;
            array<int, 2> laTemp;
            laTemp.at(0) = liRank0;
            laTemp.at(1) = liRank1;
            members.push_back(laTemp);
            if (liRank0 == 1) bestRank0 = laTemp; //�ְ� ���� ������ ����
            if (liRank1 == 1) bestRank1 = laTemp; //�ְ� ���� ������ ����
        } //i loop
        for (int i=0; i<N; i++) {
            array<int, 2> laTemp = members[i];
            if (laTemp.at(1) <= bestRank0.at(1) && laTemp.at(0) <= bestRank1.at(0)) {
                //���� ���õ� ����� �ְ� ���� �����ں��� ������ �� �ð�, �ְ� ���� �����ں��� ������ ������ ���ߵ�
                //���� Ʋ���� ������ ���� ������ �߸��� �� �ϴ�.
                numSelected++;
            }
        }
        result[testCase] = numSelected;
    } //testCase loop

    for (int i=0; i<T; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
