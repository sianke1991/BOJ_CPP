#include <stdio.h>

int min(int num0, int num1) {
    return num0 < num1 ? num0 : num1;
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    int N;
    int arr[50];
    int S;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &S);
    int _begin = 0;
    while (S && _begin<N) {
        int maxElemIndex = _begin, maxElem = arr[_begin];
        for (int i=_begin; i<=min(_begin+S, N-1); i++) {
            if (arr[i]>maxElem) {
                maxElem = arr[i];
                maxElemIndex = i;
            }
        } //i loop
        //printf("S: %d, _begin: %d, maxElemIndex: %d\n", S, _begin, maxElemIndex);
        /*
        for (int i=0; i<N; i++)
            printf("%d ", arr[i]);
        printf("\n");
        */
        if (maxElemIndex==_begin) {
            _begin++;
            continue;
        }
        for (int i=maxElemIndex; i>_begin; i--) {
            if (S==0) break;
            int tmp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = tmp;
            S--;
        }
    } //S loop
    for (int i=0; i<N; i++)
        printf("%d ", arr[i]);

    return 0;
}
