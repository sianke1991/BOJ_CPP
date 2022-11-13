#include <stdio.h>

int main()
{
    int arr_1[100][100];
    int arr_2[100][100];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr_1[i][j]);
        }
    }
    for(int k=0;k<n;k++){
        for(int l=0;l<m;l++){
            scanf("%d",&arr_2[k][l]);
        }
    }
    for(int o=0;o<n;o++){
        for(int e=0;e<m;e++){
            printf("%d",arr_1[o][e]+arr_2[o][e]);
        }
    }





    return 0;
}
