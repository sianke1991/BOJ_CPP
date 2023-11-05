#include <bits/stdc++.h>

using namespace std;

string toString(pair<int, int> line) {
    string result = "[";
    result += to_string(line.first);
    result += ", ";
    result += to_string(line.second);
    result += "]";
    return result;
}

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    int numLines;
    cin >> numLines;

    vector<pair<int, int>> lines;
    for (int i=0; i<numLines; i++) {
        int leftEnd, rightEnd;
        cin >> leftEnd >> rightEnd;
        lines.push_back({leftEnd, rightEnd});
    }

    sort(lines.begin(), lines.end());

    int answer = 0, currentLeftEnd = lines[0].first, currentRightEnd = lines[0].second;
    for (int i=1; i<lines.size(); i++) {
        if (lines[i].first>currentRightEnd) { //새 선분이 이전 선분과 연결되지 않는다면 //이전 선분의 길이를 answer에 합하고 새 선분을 고려 대상으로 삼는다.
            answer += currentRightEnd-currentLeftEnd;
            currentLeftEnd = lines[i].first;
            currentRightEnd = lines[i].second;
        } else { //새 선분이 이전 선분과 연결된다면 이전 선분의 오른쪽 끝을 갱신한다.
            currentRightEnd = max(currentRightEnd, lines[i].second);
        }
    } //i loop
    //마지막으로 고려하는 선분의 길이를 answer에 더해준다.
    answer += currentRightEnd-currentLeftEnd;
    cout << answer;
    return 0;
}
