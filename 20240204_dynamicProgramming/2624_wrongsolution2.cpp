#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int totalValue;
int numCoinTypes;
//�� ������ ��ġ�� ������ �����ϴ� ����Ʈ
vector<pair<int, int>> coins;
//�ش� ���� ����� ���� ����ؾ� �ϴ� ������ ������ �����ϴ� �迭
set<map<int, int>> dpArray[10001]; //�ش� ���� ����� ������� �ߺ��� �����ϱ� ���� vector ��� set�� ����Ѵ�.

int main() {
    scanf("%d", &totalValue);
    scanf("%d", &numCoinTypes);
    for (int i=0; i<numCoinTypes; i++) {
        int value, num;
        scanf("%d %d", &value, &num);
        coins.push_back({value, num});
    }

    map<int, int> zeroMap; //0���� ����� ���� ����ؾ� �ϴ� ������ ���� ������ ���� map
    for (int i=0; i<numCoinTypes; i++) {
        zeroMap[coins[i].first] = 0;
    }
    dpArray[0].insert(zeroMap);


    for (int toPrice=1; toPrice<=totalValue; toPrice++) {
        for (pair<int, int> coin:coins) {
            int fromPrice = toPrice-coin.first;
            if (fromPrice<0) continue;
            for (map<int, int> fromPriceMap:dpArray[fromPrice]) { //fromPrice�� ����� ���� ����ؾ� �ϴ� ������ ���� ������ ���ɴ�.
                if (fromPriceMap[coin.first]>=coin.second) continue; //�ش� coin�� ���� �� ����� ���-
                map<int, int> toPriceMap(fromPriceMap); //fromPriceMap�� ��� �ִ� ������ �����Ͽ� ���ο� map�� �����.
                toPriceMap[coin.first]++;
                dpArray[toPrice].insert(toPriceMap);
            } //fromPriceMap loop
        } //coin loop
    } //toPrice loop

    printf("%d", dpArray[totalValue].size());
    return 0;
}


