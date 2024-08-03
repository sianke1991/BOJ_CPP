#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
//거리의 길이: 밝기를 조사할 때 그 위치값은 0 이상 L 이하의 값만이 유효하다.
long long L;
//등의 개수
int N;
//각 등의 위치
long long lights[300000];
//출력해야 할 값의 개수
int K;

int main() {
    scanf("%lld", &L);
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i=0; i<N; i++)
        scanf("%lld", &lights[i]);

    //출력할 값을 보관하는 vector
    vector<long long> results;
    //가로등에서 떨어진 거리
    long long darkness = 0;
    //가장 밝은 지점에서 어두운 지점 순으로 고려할 때 이미 고려한 지점을 담은 set
    set<long long> pointsConsidered;

    while (results.size()<K) {
        for (int i=0; i<N; i++) {
            //각 가로등에 대해서 왼쪽으로 darkness 떨어진 지점, 오른쪽으로 darkness 떨어진 지점을 results에 넣되,
            //이전에 이미 고려한 지점은 넣지 않는다. => 가로등이 설치된 지점 부터 너비우선탐색을 수행한다.

            //i 번째 가로등의 위치
            long long light = lights[i];

            //i 번째 가로등의 위치에서 왼쪽으로 darkness 만큼 떨어진 위치
            long long left = light-darkness;
            //left 값이 경계 밖이 아니고, 이전에 고려한 값이 아닐 경우-
            if (left>=0 && left<=L && pointsConsidered.find(left)==pointsConsidered.end()) {
                results.push_back(darkness);
                pointsConsidered.insert(left);
            }

            //i 번째 가로등의 위치에서 오른쪽으로 darkness 만큼 떨어진 위치
            long long right = light+darkness;
            //right 값이 경계 밖이 아니고, 이전에 고려한 값이 아닐 경우-
            if (right>=0 && right<=L && pointsConsidered.find(right)==pointsConsidered.end()) {
                results.push_back(darkness);
                pointsConsidered.insert(right);
            }
        } //i loop (각 등이 설치된 위치에 대한 루프)
        darkness++;
    } //while loop (results에 K 개 값이 누적될 때 까지 반복한다.)


    //results에는 값이 K 개 "이상" 들어있으므로
    //범위 기반 for-loop 대신 index를 사용하는 for-loop를 사용한다.
    for (int i=0; i<K; i++) {
        printf("%lld\n", results[i]);
    }

    return 0;
}
