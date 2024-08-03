#include <bits/stdc++.h>
#include <stdio.h>
#define WIDTH first
#define HEIGHT second

using namespace std;

void printPair(pair<int, int> p) {
    printf("%d %d\n", p.first, p.second);
}

/*
�Է¹��� �����̸� ���ΰ� ��� �ǵ��� ������ ���� ����
���� ���� ������ �������� �����Ѵ�.
���� ���̰� ������ �Ͼ ��� ���� ���̰� �� �� �����̴� �� ª�� ������ ���� �ö� �� ����.
[�� �����̰� �� �Ʒ��� ��ġ�� �� ������ ž�� ������ �ִ�ġ]�� ���� ������ȹ���� �����Ѵ�.
*/

int main() {
    //�������� ����
    int N;
    scanf("%d", &N);
    //papers[i] := i ��° �������� ����, ���� ����
    vector<pair<int, int>> papers;
    for (int i=0; i<N; i++) {
        int w, h;
        scanf("%d %d", &w, &h);
        if (w>h)
            papers.push_back({w, h});
        else
            papers.push_back({h, w});
    } //i loop

    //�����̸� ���� ���� �������� ����
    sort(papers.begin(), papers.end());
    //dpArray[i] := papers[i]�� �� �Ʒ��� ��ġ�� �� ������ ž�� ������ �ִ�ġ
    int dpArray[100];
    //���� ���� �����̰� �� �Ʒ��� ��ġ�� �� ������ ž�� ���̴� 1�̴�.
    dpArray[0] = 1;
    for (int i=1; i<N; i++) {
        int localMaximum = 0;
        for (int j=i-1; j>=0; j--) {
            if (papers[j].HEIGHT>papers[i].HEIGHT) continue; //j ��° ���̰� i ��° ���� ���� �ø��� ���ϴ� ���-
            localMaximum = max(localMaximum, dpArray[j]);
        } //j loop (i ��° ���� ���� �ø� j ��° ������ ����)
        dpArray[i] = localMaximum+1;
    } //i loop (dpArray[i]�� ���ϱ� ���� ����)

    int result = 0;
    for (int i=0; i<N; i++)
        result = max(result, dpArray[ i]);

    printf("%d", result);
    return 0;
}
