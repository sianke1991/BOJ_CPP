#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    //따라 잡아야 할 남은 키 차이
    long long t = y-x;
    long long ans = 0;
    for (long long i=1; t>0; i++) {
        //키 성장 가속하면서 따라잡는 키 차이
        t -= i;
        ans += 1;
        if (t<=0) break;
        //키 성장 감속하면서 따라잡는 키 차이
        t -= i;
        ans += 1;
    } //i loop

    printf("%lld", ans);
    return 0;
}
