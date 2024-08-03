#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/*
    주언이가 가지고 있는 카드 중 수가 작은 카드가 득점할 가능성이 높다.
    (역으로, 수가 작은 카드로도 득점이 안된다면 수가 큰 수로는 득점할 수 없다.)
    따라서 주언이가 가지고 있는 카드를 정렬하여
    작은 카드부터 득점을 하여 과반의 점수를 얻을 수 있는지를 조사한다.
    주언이가 받은 카드가 (오름차순 정렬하여) {a0, a1, a2, a3, a4}이고,
    사장이 받은 카드가 {b0, b1, b2, b3, b4} 일 때
    사장이 받은 카드 중에서-
        a. a0 초과의 최소치를 찾아서 카드에서 제거 (주언이 1점 득점)
        b. a1 초과의 최소치를 찾아서 카드에서 제거 (주언이 1점 득점)
        c. a2 초과의 최소치를 찾아서 카드에서 제거 (주언이 1점 득점)
    이 과정이 가능하면 주언이가 승리할 가능성이 존재하는 것이다.
*/

int main() {
    //카드의 개수
    int N;
    scanf("%d", &N);
    //주언이가 받게 될 카드
    int aCards[100000];
    for (int i=0; i<N; i++)
        scanf("%d", &aCards[i]);
    //주언이가 받게 될 카드를 크기 순으로 정렬한다.
    sort(aCards, aCards+N);
    //사장이 받게 될 카드
    multiset<int> bCards;
    for (int i=0; i<N; i++) {
        int bCard;
        scanf("%d", &bCard);
        bCards.insert(bCard);
    }

    for (int i=0; i<(N+1)/2; i++) {
        //주언이가 낸 카드에 대해 주언이가 간신히 이길 수 있는 사장의 카드(iterator)
        //주언이가 낸 카드에 대해 사장이 이 카드를 내야 주언이가 계속 이길 수 있는 가능성이 높아진다.
        auto it = bCards.upper_bound(aCards[i]);
        //주언이가 카드를 낼 때 득점할 가능성이 없으면-
        if (it==bCards.end()) {
            printf("NO");
            return 0;
        }
        bCards.erase(it);
    }
    printf("YES");
    return 0;
}
