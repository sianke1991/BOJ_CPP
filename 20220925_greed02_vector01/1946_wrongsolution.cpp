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
        array<int, 2> bestRank0 = {N+1, N+1}; //최고 서류 지원자
        array<int, 2> bestRank1 = {N+1, N+1}; //최고 면접 지원자
        int numSelected = 0;
        for (int i=0; i<N; i++) {
            int liRank0, liRank1;
            cin >> liRank0 >> liRank1;
            array<int, 2> laTemp;
            laTemp.at(0) = liRank0;
            laTemp.at(1) = liRank1;
            members.push_back(laTemp);
            if (liRank0 == 1) bestRank0 = laTemp; //최고 서류 지원자 선택
            if (liRank1 == 1) bestRank1 = laTemp; //최고 면접 지원자 선택
        } //i loop
        for (int i=0; i<N; i++) {
            array<int, 2> laTemp = members[i];
            if (laTemp.at(1) <= bestRank0.at(1) && laTemp.at(0) <= bestRank1.at(0)) {
                //현재 선택된 사원이 최고 서류 지원자보다 면접을 잘 봤고, 최고 면접 지원자보다 서류가 좋으면 선발됨
                //답이 틀리는 것으로 보아 로직이 잘못된 듯 하다.
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
