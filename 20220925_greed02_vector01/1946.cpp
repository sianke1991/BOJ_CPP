#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    int T;
    cin >> T;
    int result[T];

    for (int testCase = 0; testCase<T; testCase++) {
        int N;
        cin >> N;
        vector<pair<int, int>> members;
        for (int i=0; i<N; i++) {
            int liRank0, liRank1;
            cin >> liRank0 >> liRank1;
            pair<int, int> lpMember;
            lpMember.first = liRank0; lpMember.second = liRank1;
            members.push_back(lpMember);
        }

        //���� 1���� ������ ���ߵȴ�.
        int numSelected = 1;
        //���� ������ �����Ѵ�.
        sort(members.begin(), members.end());
        int cutLine = members[0].second; //���� 1���� ���� ������ �ϴ� ĿƮ������ �ȴ�,

        for (int i=1; i<N; i++) {
            pair<int, int> lpMember = members[i];
            if (lpMember.second < cutLine) { //���� 1��� ������ �� �� ���, �� ����� ������ �ǰ�, ���� ������� �� ������� ������ �� ���� ������ �ȴ�.
                numSelected++;
                cutLine = lpMember.second;
            }
        } //i loop
        result[testCase] = numSelected;
    } //testCase loop

    for (int i=0; i<T; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}
