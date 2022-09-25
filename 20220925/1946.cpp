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

        //서류 1위는 무조건 선발된다.
        int numSelected = 1;
        //서류 순위로 정렬한다.
        sort(members.begin(), members.end());
        int cutLine = members[0].second; //서류 1등의 면접 순위가 일단 커트라인이 된다,

        for (int i=1; i<N; i++) {
            pair<int, int> lpMember = members[i];
            if (lpMember.second < cutLine) { //서류 1등보다 면접을 잘 본 경우, 이 사람은 선별이 되고, 다음 사람들은 이 사람보다 면접을 잘 봐야 선별이 된다.
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
