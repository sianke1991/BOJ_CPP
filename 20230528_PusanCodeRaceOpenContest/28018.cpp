#include<stdio.h>
//imos: 입장과 퇴장만 기록하는 방법
int enterExit[1000002]; //입장시 1을 더하고 퇴장시 1을 빼는 배열
int numOccupies[1000002]; //인덱스 1부터 특정 인덱스까지 enterExit의 누적합을 계산하여 특정 시각의 학생수를 계산한 결과를 저장하는 배열
                            //enterExit 배열에 1이 기록되어 있으면 한 명 입장한 것이므로 도서관에 사람이 한 명 증가해야 한다.
                            //반대로 enterExit 배열에 -1이 기록되어 있으면 한 명 퇴장한 것이므로 도서관에 사람이 한 명 감소해야 한다.


int main() {
    int numStudents;
    scanf("%d", &numStudents);
    for (int i=0; i<numStudents; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        enterExit[s]++;
        enterExit[e+1]--; //5시에 퇴장했으면 5시까지 도서관 좌석을 차지하는 것이다.
    }
    for (int i=1; i<=1000000; i++) {
        numOccupies[i] = numOccupies[i-1]+enterExit[i];
    }
    int numQueries;
    scanf("%d", &numQueries);
    int queries[numQueries];
    for (int i=0; i<numQueries; i++) {
        scanf("%d", &queries[i]);
    }
    int results[numQueries];
    for (int i=0; i<numQueries; i++) {
        results[i] = numOccupies[queries[i]];
    }
    for (int result:results) {
        printf("%d\n", result);
    }
    return 0;

}
