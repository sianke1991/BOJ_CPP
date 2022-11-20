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
        if (resultList.size()==0 || resultList[resultList.size()-1]!=lsCase) { //�̹��� ������ ���� ���ڿ��� resultList�� ���ٸ� ���ο� ���� ���ڿ��� resultList�� �ִ´�.
                                                                                 //Note. ���� ���ڿ��� ������������ �����ǹǷ�, �� ���ڿ��� �ߺ��� ������ �� resultList�� ������ ���ڿ��� ���ص� OK
                                                                                 //Note. resultList�� emptyList�� ��� �ߺ� üũ�� ���� �ʾƵ� OK
            resultList.push_back(lsCase);
        }
    } while (next_permutation(numbersSelectable, numbersSelectable+N));

    for (string lsCase:resultList) {
        cout << lsCase << '\n';
    }
    return 0;
}
