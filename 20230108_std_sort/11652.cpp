#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long cards[N];
    for (int i=0; i<N; i++) {
        cin >> cards[i];
    }
    sort(cards, cards+N);
    long long curElem = cards[0];
    int curIdx = 0;
    int curStreak;
    long long maxStreakElem = cards[0];
    int maxStreak = 0;
    while (1) {
        int i;
        for (i=curIdx; i<N; i++) {
            if (cards[i]!=curElem) break;
        } //i loop
        curStreak = i-curIdx;
        if (curStreak > maxStreak) {
            maxStreak = curStreak;
            maxStreakElem = curElem;
        }
        if (i==N) break;
        curIdx = i;
        curElem = cards[curIdx];
    } //while loop
    cout << maxStreakElem;
    return 0;

}
