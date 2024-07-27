#include <stdio.h>
#include <vector>
#include <set>
#define ROW first
#define COL second

using namespace std;

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

//������� ��ġ ���
vector<pair<int, int>> fish;
//����Ⱑ ��ġ�ϴ� �� ��ȣ ���
set<int> rows;
//����Ⱑ ��ġ�ϴ� �� ��ȣ ���
set<int> cols;

/**
����Ⱑ ��ġ�ϴ� ��� ����Ⱑ ��ġ�ϴ� ����
�׹��� ��ġ�ϰ� �׹� �ȿ� ���� ������� ������ ��Ƹ���.
=> ����Ⱑ ��ġ�ϴ� ���� �׹��� ��ġ�ϴ� �Ͱ��� �ٸ��� �����Ѵ�.
����Ⱑ ��ġ�ϴ� �� 100 ���� �׹��� ��ġ�ϴ� ���� �ƴ϶�
����Ⱑ ��ġ�ϴ� �� 100 ���� ����Ⱑ ��ġ�ϴ� �� 100 ���� ���� 10000 ����
�׹��� ��ġ�Ͽ� ����� ������ ��Ƹ���,
*/

/**
 * �� r0 �̻� r1 ����, �� c0 �̻� c1 ������ ���� �ȿ� �ִ� ������� ������ ��Ƹ���.
 */
int numFishIn(int r0, int r1, int c0, int c1) {
    int result = 0;
    for (auto f:fish) {
        if (f.ROW>=r0 && f.ROW<=r1 && f.COL>=c0 && f.COL<=c1) result++;
    }
    return result;
}

int main() {
    //�� ������ ũ��
    int N;
    //�׹��� ����
    int L;
    //������� ����
    int M;
    scanf("%d %d %d", &N, &L, &M);

    for (int i=0; i<M; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        fish.push_back({r, c});
        rows.insert(r);
        cols.insert(c);
    } //i loop

    int result = 0;
    //dr: �׹��� ���� ����
    //dc: �׹��� ���� ����
    for (int dr=1; dr<L/2; dr++) {
        int dc = L/2-dr;
        for (int r0:rows) {
            int r1 = r0+dr;
            //if (r1>N) continue;
            for (int c0:cols) {
                int c1 = c0+dc;
                //if (c1>N) continue;
                result = max(result, numFishIn(r0, r1, c0, c1));
            } //c0 loop
        } //r0 loop
    } //dr loop

    printf("%d", result);
    return 0;
}
