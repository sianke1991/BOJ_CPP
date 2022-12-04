#include <stdio.h>

int main (){
    int a[5];
    int N = 0;
    int n = 0;
    int s = 0;

    for (int j=0 ; j <= 4 ; j++){
        scanf("%d",&a[j]);
    }

    for (int j=0 ; j <= 4 ; j++){
        N = a[0];
        if (a[j]>=N)
            N = a[j];

        n = a[0];
        if (a[j]<=n)
            n = a[j];
    }
    for (int j=0 ; j <= 4 ; j++){
            s+=a[j];
    }

    printf("ÃÖ´ñ°ª : %d ÃÖ¼Ú°ª : %d ÃÑ ÇÕ : %d", N, n, s);


}

