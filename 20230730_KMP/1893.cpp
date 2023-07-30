#include <iostream>
#include <string>
#include <vector>

using namespace std;
string characters; //�� �� ��ȣ���� �����ϴ� ���ڸ� ������� ������ ���ڿ�
string plain; //��
string encrypted; //��ȣ�� (��ȣ���� ��ȣȭ �� ����� ���� ��Ȯ�ϰ� �ϳ� �����ؾ� �Ѵ�.)
char decrypted[500001]; //��ȣ�� (��ȣ���� ��ȣȭ �� ���)
int indexOf['z'+1]; //characters �� Ư�� ���ڰ� �����ϴ� ��ġ
vector<int> fVector; //����pat�� �����Լ� ���

//����pat�� �����Լ�
vector<int> failure(string& s) {
    vector<int> f(s.size());

    int j = 0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j]) j = f[j-1];
        if (s[i]==s[j]) f[i] = ++j;
    } //i loop

    return f;
}

/**plain�� decrypted�� �� �� ��Ÿ������ ���θ� ��ȯ�Ѵ�. �� �Լ� ȣ�� �� fVector�� �˸°� ���ŵǾ�� �Ѵ�.*/
bool checkUniqueness() {
    int j = 0;
    int numAppearance = 0; //plain�� decrypted�� ������ Ƚ��
    for (int i=0; i<encrypted.size(); i++) {
        while (j>0 && decrypted[i] != plain[j]) j = fVector[j-1];
        if (decrypted[i] == plain[j]) j++;
        if (j == plain.size()) { //str�� pat�� ����ִٰ� ������ ���-
            numAppearance++;
            if (numAppearance>1) return false; //plain�� decrypted�� �� �� �̻� ������ ��� KMP �˰����� ����� ������ ����.
        }
    } //i loop
    return numAppearance == 1;
}

/**��ȣ���� �Է¹��� shift ������ ��ȣȭ�Ͽ� decrypted�� �����Ѵ�. �� �Լ� ȣ�� �� indexOf�� �˸°� ���ŵǾ�� �Ѵ�.*/
void decrypt(int shift) {
    for (int i=0; i<encrypted.size(); i++) {
        char charBefore = encrypted[i];
        int indexBefore = indexOf[charBefore];
        int indexAfter = indexBefore>=shift ? indexBefore-shift : indexBefore+characters.size()-shift;
        char charAfter = characters[indexAfter];
        decrypted[i] = charAfter;
    } //i loop
}


/**�� �׽�Ʈ ���̽�. �ʿ��� ���ڿ� �� ���� �Է¹޾� �� ����� �� �ٷ� ����Ѵ�.*/
void test() {
    //�ʿ��� ���ڿ� �� ���� �Է¹޴´�.
    cin >> characters >> plain >> encrypted;


    //�Է¹��� characters�� ���� indexOf �迭�� �����ϰ�, �Է¹��� plain�� ���� fVector�� �����Ѵ�.
    for (int i=0; i<characters.size(); i++) {
        indexOf[characters[i]] = i;
    }
    fVector = failure(plain);


    vector<int> possibleShifts; //ī�̻縣 ��ȣ�� ���� �� ��� ������ ����Ʈ ���� ���
    for (int shift=0; shift<characters.size(); shift++) {
        //�� shift���� ���� ��ȣȭ�� �� �� KMP �˰����� �����Ѵ�.
        //��ȣ���� ��ä�� ��ȣȭ �� �� KMP�� ������ ���� ������, KMP ���߿� ��ȣ�� ���ڸ� unshift �ϴ� ����� ����� ���� �ִ�.
        decrypt(shift);
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
