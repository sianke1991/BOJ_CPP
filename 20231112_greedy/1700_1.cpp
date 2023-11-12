#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a[105]; // �����ǰ�� ��� ����
bool power[105]; // �ش� �����ǰ�� ��Ƽ�ǿ� ���� �ִ°�?

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) cin >> a[i];
  int ans = 0;
  int cnt = 0; // ��Ƽ�ǿ� ���� �ִ� �����ǰ�� ����
  for (int i = 1; i <= k; i++) {
    int cur = a[i];
    if (power[cur]) continue; // �̹� ���� ������ �Ѿ
    // ��Ƽ�ǿ� �ڸ��� ������ �׳� ����
    if (cnt < n) {
      power[cur] = true;
      cnt++;
    }
    else {
      // ��Ƽ�ǿ� ���� �ִ� �����ǰ �� a���� ������ ���� ���� ���� ��ġ�� �̸��� �Բ� ������
      vector<pair<int, int>> idx;
      for (int x = 1; x <= k; x++) {
        if (!power[x]) continue;
        bool vis = false;
        for (int y = i + 1; y <= k; y++) {
          if (a[y] == x) {
            idx.push_back({y, x});
            vis = true;
            break;
          }
        }
        if (!vis) idx.push_back({k + 1, x}); // a���� ������ ������ k + 1�� ó��
      }
      sort(idx.begin(), idx.end(), greater<pair<int, int>>());
      int target = idx[0].Y; // ���� �ʰ� ����� �����ǰ�� �̰� cur�� ������ ��
      power[target] = false; ans++;
      power[cur] = true;
    }
  }
  cout << ans;
}
