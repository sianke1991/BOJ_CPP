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
        if (lines[i].first>currentRightEnd) { //�� ������ ���� ���а� ������� �ʴ´ٸ� //���� ������ ���̸� answer�� ���ϰ� �� ������ ��� ������� ��´�.
            answer += currentRightEnd-currentLeftEnd;
            currentLeftEnd = lines[i].first;
            currentRightEnd = lines[i].second;
        } else { //�� ������ ���� ���а� ����ȴٸ� ���� ������ ������ ���� �����Ѵ�.
            currentRightEnd = max(currentRightEnd, lines[i].second);
        }
    } //i loop
    //���������� ����ϴ� ������ ���̸� answer�� �����ش�.
    answer += currentRightEnd-currentLeftEnd;
    cout << answer;
    return 0;
}
