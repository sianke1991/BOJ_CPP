#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> flower;
    for (int i=0; i<n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm*100+sd, em*100+ed}); //100*달 + 날 식을 사용하여 날짜를 하나의 int로 표현한다. (달과 날을 하나의 int로 표현함으로써 두 날짜의 전후 관계를 더 빠르게 파악할 수 있다.)
    }

    int t = 301; //현재 날짜
    int ans = 0; //선택한 꽃의 개수
    while (t<1201) {
        int ntx_t = t; //이번에 추가할 꽃으로 인해 변경될 날짜
        for (int i=0; i<n; i++) {
            if (flower[i].X<=t && flower[i].Y>nxt_t) //현재 날짜에 피어있고, 현재 선택한 꽃보다 더 오래 유지되는 꽃인 경우 (즉, 현재 피어있는 꽃 중 지는 시기의 최대치를 구한다.)
                nxt_t = flower[i].Y;
        } //i loop
        if (nxt_t==t) { //시간 t에서 전진이 불가능 (꽃을 더 선택해도 꽃이 피어있는 날짜를 연장하지 못하는 경우)
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans;
    return 0;
}
