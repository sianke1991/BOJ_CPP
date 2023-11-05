#include <bits/stdc++.h>

using namespace std;

int main() {
    int numCards, numOperations;
    cin >> numCards >> numOperations;
    priority_queue<long long, vector<long long>, greater<long long>> deck; //�ּ� ��: ����ִ� ���� �� ���� ���� ���� �������´�.
    long long answer = 0; //���� ���ϴ� �������� ���� �÷ΰ� �Ͼ �� �ִ�. //ī�带 ���ϸ鼭 ���� �÷ΰ� �Ͼ �� �����Ƿ� �� ī���� ���� long long���� ��´�.
    for (int i=0; i<numCards; i++) {
        long long card;
        cin >> card;
        answer += card;
        deck.push(card);
    }
    // �� ���긶��
    // ���� �ִ� ī�� �� ���� ���� ī�� �� ���� �̾Ƽ� ���� �� �� ������ ī�带 �����,
    // ��� ī�带 ���� �ٽ� �ִ´�.
    // �� ī���� �� ��ŭ answer�� �����Ѵ�.
    // ������ ���� �� ī���� �� ��ŭ answer�� �����ϹǷ� deck �� ���� ī�� �� ���� �̾ƾ� answer�� �ּҷ� ���� �� �ִ�.
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
