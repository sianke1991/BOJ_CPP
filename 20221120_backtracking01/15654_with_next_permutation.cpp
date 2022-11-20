#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int numbersSelectable[N];
    for (int i=0; i<N; i++) {
        cin >> numbersSelectable[i];
    } //i loop
    sort(numbersSelectable, numbersSelectable+N);
    vector<string> resultList;

    do {
        string lsCase = "";
        for (int i=0; i<M; i++) {
            lsCase += to_string(numbersSelectable[i])+" ";
        } //i loop

        if (resultList.empty() || resultList[resultList.size()-1]!=lsCase) {
            resultList.push_back(lsCase);
        }
    } while (next_permutation(numbersSelectable, numbersSelectable+N));

    for (string lsCase:resultList) {
        cout << lsCase << '\n';
    }

    return 0;
}
