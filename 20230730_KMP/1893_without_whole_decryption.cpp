#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

  1893 ���� ��Ǯ��
  �̹� Ǯ�̿����� ��ȣ�� encrypted�� ���� ��ü�� ��ȣȭ ���� �ʰ�,
  �� plain�� ���ڿ� �񱳸� �ؾ� �ϴ� ���ڵ鸸 ��ȣȭ �ϴ� ����� ����Ѵ�.

*/

string characters; //�� �� ��ȣ���� �����ϴ� ���ڸ� ������� ������ ���ڿ�
string plain; //��
string encrypted; //��ȣ�� (��ȣ���� ��ȣȭ �� ����� ���� ��Ȯ�ϰ� �ϳ� �����ؾ� �Ѵ�.)
char decrypt[128]; //���� ��ȣ (����Ʈ ���� ���� ��ȣ���� ���ڸ� ��ȣȭ �� ���ڸ� ��Ÿ����.) (decrypt[��ȣ�� �� ����] = ��ȣȭ �� ����)
vector<int> fVector; //����pat�� �����Լ� ���

//������ �����Լ�
vector<int> failure(string& s) {
    vector<int> f(s.size());

    int j = 0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j]) j = f[j-1];
        if (s[i]==s[j]) f[i] = ++j;
    } //i loop

    return f;
}

/**plain�� decrypted�� �� �� ��Ÿ������ ���θ� ��ȯ�Ѵ�. �� �Լ� ȣ�� �� decrypt, fVector�� �˸°� ���ŵǾ�� �Ѵ�.*/
bool checkUniqueness() {
    int j = 0;
    int numAppearance = 0; //plain�� decrypted�� ������ Ƚ��
    for (int i=0; i<encrypted.size(); i++) {
        while (j>0 && decrypt[encrypted[i]] != plain[j]) j = fVector[j-1]; //[�� �� ����]�� ���ؾ� �ϴ� ���� [��ȣ�� �� ����]�� �ƴ϶� [��ȣ�� �� ���ڸ� ��ȣȭ �� ��� ����]��.
        if (decrypt[encrypted[i]] == plain[j]) j++;
        if (j == plain.size()) { //str�� pat�� ����ִٰ� ������ ���-
            numAppearance++;
            if (numAppearance>1) return false; //plain�� decrypted�� �� �� �̻� ������ ��� KMP �˰����� ����� ������ ����.
        }
    } //i loop
    return numAppearance == 1;
}

/**�Է¹��� shift ���ڰ��� ���� decrypt �迭�� �����Ѵ�.*/
void setDecrypt(int shift) {
    int j = shift;
    for (int i=0; i<characters.size(); i++) {
        decrypt[characters[j]] = characters[i]; //j��° ���ڸ� unshift �ϸ� i��° ���ڰ� ���´�.
        j = (j+1)%characters.size();
    } //i loop
}

/**�� �׽�Ʈ ���̽�. �ʿ��� ���ڿ� �� ���� �Է¹޾� �� ����� �� �ٷ� ����Ѵ�.*/
void test() {
    //�ʿ��� ���ڿ� �� ���� �Է¹޴´�.
    cin >> characters >> plain >> encrypted;


    //�Է¹��� plain�� ���� fVector�� �����Ѵ�.
    fVector = failure(plain);


    vector<int> possibleShifts; //ī�̻縣 ��ȣ�� ���� �� ��� ������ ����Ʈ ���� ���
    for (int shift=0; shift<characters.size(); shift++) {
        //�� shift���� ���� ��ȣ ��Ģ�� ������ �� (decrypt �迭 ����) KMP �˰����� �����Ѵ�.
        setDecrypt(shift);
        if (checkUniqueness())
            possibleShifts.push_back(shift);
    } //shift loop

    //��� ������ ����Ʈ ���� ������ ���� �� ����� �޸� ����Ѵ�.
    switch (possibleShifts.size()) {
        case 0:
            cout << "no solution\n";
            break;
        case 1:
            cout << "unique: " << possibleShifts[0] << '\n';
            break;
        default:
            cout << "ambiguous:";
            for (int possibleShift:possibleShifts) {
                cout << ' ' << possibleShift;
            }
            cout << '\n';
            break;
    }
}


int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++) {
        test();
    }
    return 0;
}
