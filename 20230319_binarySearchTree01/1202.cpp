#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<pair<int, int>> gems; //���� ���� //first: ������ ����, second: ������ ����
    vector<int> bags; //���� ����
    int numGems, numBags;
    cin >> numGems >> numBags;
    for (int i=0; i<numGems; i++) {
        int mass, value;
        cin >> mass >> value;
        gems.insert({value, mass});
    }
    for (int i=0; i<numBags; i++) {
        int capacity;
        cin >> capacity;
        bags.push_back(capacity);
    }
    sort(bags.begin(), bags.end()); //���� �������� ����
    int sumValues = 0;
    auto bag = bags.end();
    auto gem = gems.end();

    do {


    } while (bag!=bags.begin() && gem!=gems.begin());










    return 0;
}
