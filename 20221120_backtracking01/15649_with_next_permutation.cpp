#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int M;
    cin >> N >> M;
    int numbersSelectable[N];
    for (int i=0; i<N; i++) {
        numbersSelectable[i] = i+1;
    }
    vector<string> resultList;

    do {
        string lsCase = "";
        for (int i=0; i<M; i++) {
            lsCase += to_string(numbersSelectable[i]) + " ";
        }
        if (resultList.size()==0 || resultList[resultList.size()-1]!=lsCase) { //이번에 생성된 순열 문자열이 resultList에 없다면 새로운 순열 문자열을 resultList에 넣는다.
                                                                                 //Note. 순열 문자열은 오름차순으로 생성되므로, 새 문자열의 중복을 검증할 때 resultList의 마지막 문자열만 비교해도 OK
                                                                                 //Note. resultList가 emptyList인 경우 중복 체크를 하지 않아도 OK
            resultList.push_back(lsCase);
        }
    } while (next_permutation(numbersSelectable, numbersSelectable+N));

    for (string lsCase:resultList) {
        cout << lsCase << '\n';
    }
    return 0;
}
