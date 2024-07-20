#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    //n: 사람의 수
    //k: 선발할 사람의 수
    //x: 한 사람에 대해 파워 수치와 스피드 수치의 합
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    //powerOf[i] := i 번 인원의 파워 수치 (파워 수치를 알면 스피드 수치는 자동으로 구할 수 있다.)
    int powerOf[80];
    int speed_;
    for (int i=0; i<n; i++)
        scanf("%d %d", &powerOf[i], &speed_);

    //dpArray[j][m] := j 명의 인원으로 파워 수치 합 m을 만들 수 있는지 여부
    bool dpArray[90][17000] = {true};

    for (int participantIndex=0; participantIndex<n; participantIndex++) {
        for (int numSelectedParticipants=k-1; numSelectedParticipants>=0; numSelectedParticipants--) {
            for (int sumPower=x*k; sumPower>=0; sumPower--) {
                if (dpArray[numSelectedParticipants][sumPower]) //participantIndex 인원 없이 numSelectedParticipants명으로 sumPower 수치가 가능하다면-
                    dpArray[numSelectedParticipants+1][sumPower+powerOf[participantIndex]] = true; //participantIndex 인원을 선택함으로써 sumPower+powerOf[participantIndex] 파워 수치가 가능하다.
                /*
                    이처럼 점화식에서 dpArray 배열의 아랫 행, 오른쪽 열을 변화시키기 때문에
                    dpArray의 갱신은 우하귀에서 좌상귀 방향으로 이루어져야 한다.
                    만약 dpArray의 갱신이 좌상귀에서 우하귀 방향으로 이루어진다면
                    participantIndex 인원을 선택해야  가능해지는 파워 수치에 다시 한 번 participantIndex 인원을 선택하는,
                    (다시 말해) 한 사람의 파워 수치를 중복해서 계산하는 오류가 발생할 수 있다.
                    participantIndex의 파워 수치가 적용되지 않은 영역만을 읽어 나가기 위해 dpArray의 우하귀에서 좌상귀 방향으로 갱신해 나간다.
                */
            } //sumPower loop (선택된 인원의 파워 수치 합 loop)
        } //numSelectedParticipants loop (선택된 인원 수 loop)
    } //participantIndex loop (각 번호의 인원 loop)

    int result = 0;
    for (int sumPower=0; sumPower<=x*k; sumPower++) {
        if (!dpArray[k][sumPower]) //k 명 인원을 선택하여 sumPower 만큼의 파워 수치를 얻지 못한다면 이 경우는 무시한다.
            continue;
        //k 명 인원을 선택하여 얻을 수 있는 sumPower 수치에 대해-
        result = max(result, sumPower*(x*k-sumPower)); //sumSpeed를 계산하여 팀의 종합 능력치를 구할 수 있다. 팀의 종합 능력치 중 최대치를 구한다.
    }
    printf("%d", result);

    return 0;
}
