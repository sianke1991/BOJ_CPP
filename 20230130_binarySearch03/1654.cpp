#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int K; //가지고 있는 랜선의 개수
int N; //필요한 랜선의 개수
vector<int> ownedLines; //가지고 있는 랜선의 길이
int minOwnedLine = 2147483647;
int maxOwnedLine = 0;

// 매개 변수 탐색
// 조건을 만족하는 최소/최대치를 구하는 문제 (최적화 문제)를 결정 문제로 변환하여 이분탐색을 수행하는 방법
// (최적화 문제) N개를 만들 수 있는 랜선의 최대 길이
// (결정 문제) 랜선의 길이가 X일 때 랜선이 N개 이상인가 여부

//랜선의 길이를 입력받아 N개의 랜선을 만들 수 있는지 여부를 반환한다.
bool isConstructable(long long lineLength) {
    long long numLines = 0;
    for (int ownedLine:ownedLines) {
        numLines += ownedLine/lineLength;
    }
    return numLines >= N;
}

int main() {
    {
        cin >> K >> N;
        int ownedLine;
        for (int i=0; i<K; i++) {
            cin >> ownedLine;
            ownedLines.push_back(ownedLine);
            minOwnedLine = min(minOwnedLine, ownedLine);
            maxOwnedLine = max(maxOwnedLine, ownedLine);
        } //i loop
    }
    long long from = 0;
    long long to = maxOwnedLine; //minOwnedLine이 2147483647와 같은 값일 때 (int로 변수를 선언하면) mid를 계산하는 과정에서 오버플로가 발생할 수 있다. 
    long long mid;
    while (from+1<to) {
        mid = (from+to)/2;
        //cout << from << ", " << mid << ", " << to << '\n';
        if (isConstructable(mid)) {
           from = mid;
        } else {
            to = mid;
        }
    }
    if (isConstructable(from+1)) cout << from+1;
    else cout << from;
    return 0;
}
