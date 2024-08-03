#include <bits/stdc++.h>
#include <stdio.h>
#define WIDTH first
#define HEIGHT second

using namespace std;

void printPair(pair<int, int> p) {
    printf("%d %d\n", p.first, p.second);
}

/*
입력받은 색종이를 가로가 길게 되도록 방향을 맞춘 다음
가로 길이 순으로 오름차순 정렬한다.
세로 길이가 역전이 일어난 경우 세로 길이가 더 긴 색종이는 더 짧은 색종이 위에 올라갈 수 없다.
[각 색종이가 맨 아래에 위치할 때 색종이 탑의 높이의 최대치]에 대해 동적계획법을 적용한다.
*/

int main() {
    //색종이의 개수
    int N;
    scanf("%d", &N);
    //papers[i] := i 번째 색종이의 가로, 세로 길이
    vector<pair<int, int>> papers;
    for (int i=0; i<N; i++) {
        int w, h;
        scanf("%d %d", &w, &h);
        if (w>h)
            papers.push_back({w, h});
        else
            papers.push_back({h, w});
    } //i loop

    //색종이를 가로 길이 기준으로 정렬
    sort(papers.begin(), papers.end());
    //dpArray[i] := papers[i]가 맨 아래에 위치할 때 색종이 탑의 높이의 최대치
    int dpArray[100];
    //가장 작은 색종이가 맨 아래에 위치할 때 색종이 탑의 높이는 1이다.
    dpArray[0] = 1;
    for (int i=1; i<N; i++) {
        int localMaximum = 0;
        for (int j=i-1; j>=0; j--) {
            if (papers[j].HEIGHT>papers[i].HEIGHT) continue; //j 번째 종이가 i 번째 종이 위에 올리지 못하는 경우-
            localMaximum = max(localMaximum, dpArray[j]);
        } //j loop (i 번째 종이 위에 올릴 j 번째 종이의 루프)
        dpArray[i] = localMaximum+1;
    } //i loop (dpArray[i]를 구하기 위한 루프)

    int result = 0;
    for (int i=0; i<N; i++)
        result = max(result, dpArray[ i]);

    printf("%d", result);
    return 0;
}
