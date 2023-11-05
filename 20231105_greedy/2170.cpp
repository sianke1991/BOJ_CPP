#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

struct Line {
    int leftEnd;
    int rightEnd;
};

/**
 * Line�� �����ϴ� ����: ���������� �� ���� �� ����, �������� �� ���� �� ���� �켱������ ���� ���� ����� ���Ѵ�.
 */
bool cmp(Line line0, Line line1) {
    if (line0.rightEnd != line1.rightEnd)
        return line0.rightEnd > line1.rightEnd;
    else
        return line0.leftEnd < line1.leftEnd;
}

bool contains(Line line, int point) {
    return line.leftEnd<=point && line.rightEnd>=point;
}

string toString(Line line) {
    string result = "[";
    result += to_string(line.leftEnd);
    result += ", ";
    result += to_string(line.rightEnd);
    result += "]";
    return result;
}

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int lengthOf(Line line) {
    return line.rightEnd-line.leftEnd;
}

int main() {
    int numLines;
    scanf("%d", &numLines);
    vector<Line> lines;
    Line beginLine;
    beginLine.leftEnd = 1000000001;
    for (int i=0; i<numLines; i++) {
        int leftEnd, rightEnd;
        scanf("%d %d", &leftEnd, &rightEnd);
        Line* line = new Line();
        line -> leftEnd = leftEnd; line -> rightEnd = rightEnd;
        lines.push_back(*line);
        if (line->leftEnd < beginLine.leftEnd) {
            beginLine.leftEnd = line->leftEnd;
            beginLine.rightEnd = line->rightEnd;
        } else if (line->leftEnd == beginLine.leftEnd) {
            beginLine.rightEnd = max(beginLine.rightEnd, line->rightEnd);
        }
    }

    sort(lines.begin(), lines.end(), cmp);

    int answer = 0;
    Line currentLine = {beginLine.leftEnd, beginLine.rightEnd};
    Line nextLine;
    while (1) {
        int lineIdx;
        for (lineIdx=0; lineIdx<lines.size(); lineIdx++) {
            if (contains(lines[lineIdx], currentLine.rightEnd))
                break;
        }
        nextLine = lines[lineIdx];
        if (nextLine.rightEnd>currentLine.rightEnd) { //���� ����ϴ� ������ �� ����Ǵ� ���-
            currentLine.rightEnd = nextLine.rightEnd;
            continue;
        }
        if (lineIdx==0) { //���� ����ϴ� ������ �� ������� �ʴµ�, �����ʿ� �� �׷����� ������ ���� ���-
            answer += lengthOf(currentLine);
            break;
        }
        //���� ����ϴ� ������ �� ������� ������, �����ʿ� �� �׷����� ������ �ִ� ���-
        answer += lengthOf(currentLine);
        currentLine = {lines[lineIdx-1].leftEnd, lines[lineIdx-1].rightEnd};
    } //while loop

    printf("%d", answer);
    return 0;
}
