#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/**��� ������ ����ü*/
struct Participant {
    int abilityPoint; //�ش� ��� �������� �ɷ�ġ
    int classNumber;  //�ش� ��� �����ڰ� ���� �б��� ��ȣ
};

/**��� ������ �迭�� �����ϴ� ����: ��� �����ڴ� �� �ɷ�ġ�� ���� �������� �����Ѵ�.*/
bool cmp(Participant par0, Participant par1) {
    return par0.abilityPoint < par1.abilityPoint;
}

//��� ������ vector
vector<Participant> participants;
//��� ������ �迭�� �κ� �迭�� ��������: �� �б޿� ���� �л� ��
int subarrayProfile[1001];
//��� ������ �迭�� �κ� �迭�� �� �б��� ����
int subarrayNumClasses;

/**
 * ��� ������ �迭�� �κ� �迭�� ��� �����ڸ� �ִ´�.
 */
void add(Participant par) {
    if (subarrayProfile[par.classNumber]==0) {
        subarrayNumClasses++;
    }
    subarrayProfile[par.classNumber]++;
}

/**
 * ��� ������ �迭�� �κ� �迭�� ��� �����ڸ� ����.
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
    //�б��� ����    //�� �б� �� ���� ��� �������� ��
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

    //�Էµ� �����ڵ��� �� �ɷ¿� ���� �����Ѵ�.
    sort(participants.begin(), participants.end(), cmp);

    int optResult = 2000000000;
    int to=0;
    for (int from=0; from<participants.size(); from++) {
        while (to<participants.size() && subarrayNumClasses<numClasses) {
            add(participants[to]);
            to++;
        } //���� �ε��� to�� �ش��ϴ� �����ڴ� ������ �ȵ� ���̴�.
          //���õ� �����ڴ� �ε��� from �̻� to �̸��̴�.
        if (subarrayNumClasses==numClasses) //��� ������ �迭�� �κ� �迭�� �� �ݿ� �Ѹ��� ����ִ��� ���θ� Ȯ���� �� optReulst�� �����Ѵ�.
            optResult = min(optResult, participants[to-1].abilityPoint-participants[from].abilityPoint);
        remove(participants[from]); //from �ε��� 1 ������Ű�� ���� �ش� �����ڸ� ����.
    }

    printf("%d", optResult);

    return 0;
}
