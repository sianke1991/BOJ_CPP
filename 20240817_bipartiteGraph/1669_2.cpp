#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    //���� ��ƾ� �� ���� Ű ����
    long long t = y-x;
    long long ans = 0;
    for (long long i=1; t>0; i++) {
        //Ű ���� �����ϸ鼭 ������� Ű ����
        t -= i;
        ans += 1;
        if (t<=0) break;
        //Ű ���� �����ϸ鼭 ������� Ű ����
        t -= i;
        ans += 1;
    } //i loop

    printf("%lld", ans);
    return 0;
}
