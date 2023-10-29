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
        flower.push_back({sm*100+sd, em*100+ed}); //100*�� + �� ���� ����Ͽ� ��¥�� �ϳ��� int�� ǥ���Ѵ�. (�ް� ���� �ϳ��� int�� ǥ�������ν� �� ��¥�� ���� ���踦 �� ������ �ľ��� �� �ִ�.)
    }

    int t = 301; //���� ��¥
    int ans = 0; //������ ���� ����
    while (t<1201) {
        int ntx_t = t; //�̹��� �߰��� ������ ���� ����� ��¥
        for (int i=0; i<n; i++) {
            if (flower[i].X<=t && flower[i].Y>nxt_t) //���� ��¥�� �Ǿ��ְ�, ���� ������ �ɺ��� �� ���� �����Ǵ� ���� ��� (��, ���� �Ǿ��ִ� �� �� ���� �ñ��� �ִ�ġ�� ���Ѵ�.)
                nxt_t = flower[i].Y;
        } //i loop
        if (nxt_t==t) { //�ð� t���� ������ �Ұ��� (���� �� �����ص� ���� �Ǿ��ִ� ��¥�� �������� ���ϴ� ���)
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans;
    return 0;
}
