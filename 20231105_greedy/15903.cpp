#include <bits/stdc++.h>

using namespace std;

int main() {
    int numCards, numOperations;
    cin >> numCards >> numOperations;
    priority_queue<long long, vector<long long>, greater<long long>> deck; //최소 힙: 들어있는 원소 중 가장 작은 것이 빠져나온다.
    long long answer = 0; //답을 구하는 과정에서 오버 플로가 일어날 수 있다. //카드를 합하면서 오버 플로가 일어날 수 있으므로 각 카드의 값도 long long으로 담는다.
    for (int i=0; i<numCards; i++) {
        long long card;
        cin >> card;
        answer += card;
        deck.push(card);
    }
    // 매 연산마다
    // 덱에 있는 카드 중 가장 작은 카드 두 개를 뽑아서 합한 뒤 그 값으로 카드를 덮어쓰고,
    // 덮어쓴 카드를 덱에 다시 넣는다.
    // 두 카드의 합 만큼 answer가 증가한다.
    // 덱에서 뽑은 두 카드의 합 만큼 answer가 증가하므로 deck 중 작은 카드 두 개를 뽑아야 answer를 최소로 만들 수 있다.
    for (int operation=0; operation<numOperations; operation++) {
        long long card0 = deck.top();
        deck.pop();
        long long card1 = deck.top();
        deck.pop();
        long long sum = card0+card1;
        answer += sum;
        deck.push(sum);
        deck.push(sum);
    } //operation loop

    cout << answer;
    return 0;
}
