#include <string>
#include <iostream>

using namespace std;

int signum (int num)
{
    return num >=0 ? 1 : -1;
}

int getTotal(int honeyArr[], int posTong, int initPosBee0, int initPosBee1) {
    int result = 0;
    int posBee0 = initPosBee0;
    while (posBee0 != posTong) {
        if (posBee0 != initPosBee0 && posBee0 != initPosBee1)
            result += honeyArr[posBee0];
        posBee0 += signum (posTong-posBee0);
    }
    int posBee1 = initPosBee1;
    while (posBee1 != posTong) {
        if (posBee1 != initPosBee0 && posBee1 != initPosBee1)
            result += honeyArr[posBee1];
        posBee1 += signum (posTong-posBee1);
    }
    result += honeyArr[posTong]*2;
    return result;
}

int main() {

    int N;
    cin >> N;

    int honeyArr[N];
    for (int i=0; i<N; i++) {
        cin >> honeyArr[i];
    }

    int maxTotal = -1;
    for (int i=0; i<N; i++) {
        int posTong = i;
        for (int j=0; j<N; j++) {
            if (j==i) continue;
            int posBee0 = j;
            for (int k=j+1; k<N; k++) {
                if (k==i || k==j) continue;
                int posBee1 = k;

                int liTotal = getTotal(honeyArr, posTong, posBee0, posBee1);
                if (liTotal > maxTotal) maxTotal = liTotal;
            }
        }

    }

    cout << maxTotal;
    return 0;

}
