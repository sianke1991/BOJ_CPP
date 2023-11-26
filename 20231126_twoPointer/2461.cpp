#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/**경기 참여자 구조체*/
struct Participant {
    int abilityPoint; //해당 경기 참여자의 능력치
    int classNumber;  //해당 경기 참여자가 속한 학급의 번호
};

/**경기 참여자 배열을 정렬하는 기준: 경기 참여자는 그 능력치에 대해 오름차순 정렬한다.*/
bool cmp(Participant par0, Participant par1) {
    return par0.abilityPoint < par1.abilityPoint;
}

//경기 참여자 vector
vector<Participant> participants;
//경기 참여자 배열의 부분 배열의 프로파일: 각 학급에 따른 학생 수
int subarrayProfile[1001];
//경기 참여자 배열의 부분 배열에 들어간 학급의 개수
int subarrayNumClasses;

/**
 * 경기 참여자 배열의 부분 배열에 경기 참여자를 넣는다.
 */
void add(Participant par) {
    if (subarrayProfile[par.classNumber]==0) {
        subarrayNumClasses++;
    }
    subarrayProfile[par.classNumber]++;
}

/**
 * 경기 참여자 배열의 부분 배열에 경기 참여자를 뺀다.
 */
void remove(Participant par) {
    if (subarrayProfile[par.classNumber]==1) {
        subarrayNumClasses--;
    }
    subarrayProfile[par.classNumber]--;
}

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

string toString(Participant par) {
    string result = "(";
    result += to_string(par.abilityPoint);
    result += ", ";
    result += to_string(par.classNumber);
    result += ")";
    return result;
}


int main() {
    //학급의 개수    //각 학급 당 속한 경기 참여자의 수
    int numClasses, classSize;
    scanf("%d %d", &numClasses, &classSize);

    for (int classNumber=0; classNumber<numClasses; classNumber++) {
        for (int j=0; j<classSize; j++) {
            int abilityPoint;
            scanf("%d", &abilityPoint);
            Participant* participant = new Participant();
            participant->classNumber = classNumber;
            participant->abilityPoint = abilityPoint;
            participants.push_back(*participant);
        }
    } //classNumber loop

    //입력된 참여자들을 그 능력에 대해 정렬한다.
    sort(participants.begin(), participants.end(), cmp);

    int optResult = 2000000000;
    int to=0;
    for (int from=0; from<participants.size(); from++) {
        while (to<participants.size() && subarrayNumClasses<numClasses) {
            add(participants[to]);
            to++;
        } //현재 인덱스 to에 해당하는 참여자는 선택이 안된 것이다.
          //선택된 참여자는 인덱스 from 이상 to 미만이다.
        if (subarrayNumClasses==numClasses) //경기 참여자 배열의 부분 배열이 각 반에 한명씩은 들어있는지 여부를 확인한 뒤 optReulst를 갱신한다.
            optResult = min(optResult, participants[to-1].abilityPoint-participants[from].abilityPoint);
        remove(participants[from]); //from 인덱스 1 증가시키기 전에 해당 참가자를 뺀다.
    }

    printf("%d", optResult);

    return 0;
}
