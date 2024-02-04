#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int totalValue;
int numCoinTypes;
//각 동전의 가치와 개수를 보관하는 리스트
vector<pair<int, int>> coins;
//해당 값을 만들기 위해 사용해야 하는 동전의 개수를 보관하는 배열
set<map<int, int>> dpArray[10001]; //해당 값을 만드는 방법에서 중복을 제거하기 위해 vector 대신 set을 사용한다.

int main() {
    scanf("%d", &totalValue);
    scanf("%d", &numCoinTypes);
    for (int i=0; i<numCoinTypes; i++) {
        int value, num;
        scanf("%d %d", &value, &num);
        coins.push_back({value, num});
    }

    map<int, int> zeroMap; //0원을 만들기 위해 사용해야 하는 동전의 개수 정보를 담은 map
    for (int i=0; i<numCoinTypes; i++) {
        zeroMap[coins[i].first] = 0;
    }
    dpArray[0].insert(zeroMap);


    for (int toPrice=1; toPrice<=totalValue; toPrice++) {
        for (pair<int, int> coin:coins) {
            int fromPrice = toPrice-coin.first;
            if (fromPrice<0) continue;
            for (map<int, int> fromPriceMap:dpArray[fromPrice]) { //fromPrice를 만들기 위해 사용해야 하는 동전의 개수 정보를 살핀다.
                if (fromPriceMap[coin.first]>=coin.second) continue; //해당 coin을 전부 다 사용한 경우-
                map<int, int> toPriceMap(fromPriceMap); //fromPriceMap이 담고 있는 정보를 복사하여 새로운 map을 만든다.
                toPriceMap[coin.first]++;
                dpArray[toPrice].insert(toPriceMap);
            } //fromPriceMap loop
        } //coin loop
    } //toPrice loop

    printf("%d", dpArray[totalValue].size());
    return 0;
}


