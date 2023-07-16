#include <string>
#include <iostream>

using namespace std;


/**
 * ���ڿ� A �ȿ� ���ڿ� B�� ������ �Ǵ��� ���θ� �Ǵ��Ѵ�.
 */
bool find (string& A, string& B) {
    int lenA = A.size(), lenB = B.size();
    if (lenB>lenA) return false;

    for (int i=0; i<=lenA-lenB; i++) {
        if (A.substr(i, lenB)==B) return true; //substr �Լ��� (���� �ε���, �߶� ���ڿ��� ����)�� ���ڷ� �޴´�.
    }
    return false;
}


int main() {

    string A = "ORONDONTISS";
    string B = "NTI";
    cout << find(A, B);
    return 0;

}


