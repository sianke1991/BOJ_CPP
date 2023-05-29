#include <bits/stdc++.h>

using namespace std;

int main() {
    int randNum[] = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};
    int len = (int)((sizeof randNum)/(sizeof *randNum));
    sort(randNum, randNum+len); //upper_bound �� lower_bound�� �����ϱ� ���� �迭�� �����ؾ� �Ѵ�.

    int* upperBound0 = upper_bound(randNum, randNum+len, -21475);
    int* lowerBound0 = lower_bound(randNum, randNum+len, -21475);
    cout << upperBound0-randNum << '\n'; //4 //-21475���Ͽ��� -21475�ʰ��� ���ϴ� ������ ��ġ
    cout << lowerBound0-randNum << '\n'; //3 //-21475�̸����� -21475�̻����� ���ϴ� ������ ��ġ
    cout << upperBound0-lowerBound0 << '\n'; //1 //randNum���� -21475�� ����
    cout << *upperBound0 << '\n'; //-18406 //-21475 �ʰ��� ������ �ּ�ġ
    cout << *lowerBound0 << '\n'; //-21475 //-21475 �̻��� ������ �ּ�ġ

    int* upperBound1 = upper_bound(randNum, randNum+len, 123);
    int* lowerBound1 = lower_bound(randNum, randNum+len, 123);
    cout << upperBound1-randNum << '\n'; //7 //123���Ͽ��� 123�ʰ��� ���ϴ� ������ ��ġ
    cout << lowerBound1-randNum << '\n'; //7 //123�̸����� 123�̻����� ���ϴ� ������ ��ġ
    cout << upperBound1-lowerBound1 << '\n'; //0 //randNum���� 123�� ����
    cout << *upperBound1 << '\n'; //168 //123 �ʰ��� ������ �ּ�ġ
    cout << *lowerBound1 << '\n'; //186 //123 �̻��� ������ �ּ�ġ


    vector<int> randNumVector = {2, 4, 4, 6, 1, 3, 4, 6, 1, 2};
    sort(randNumVector.begin(), randNumVector.end()); //{1, 1, 2, 2, 3, 4, 4, 4, 6, 6}

    vector<int>::iterator upperBound2 = upper_bound(randNumVector.begin(), randNumVector.end(), 4);
    vector<int>::iterator lowerBound2 = lower_bound(randNumVector.begin(), randNumVector.end(), 4);
    cout << upperBound2-randNumVector.begin() << '\n'; //8 //4���Ͽ��� 4 �ʰ��� ���ϴ� ������ ��ġ
    cout << lowerBound2-randNumVector.begin() << '\n'; //5 //4�̸����� 4 �̻����� ���ϴ� ������ ��ġ
    cout << upperBound2-lowerBound2 << '\n'; //3 //randNumVector���� 4�� ����
    cout << *upperBound2 << '\n'; //6 //4 �ʰ��� ������ �ּ�ġ
    cout << *lowerBound2 << '\n'; //4 //4 �̻��� ������ �ּ�ġ

    vector<int>::iterator upperBound3 = upper_bound(randNumVector.begin(), randNumVector.end(), 7);
    vector<int>::iterator lowerBound3 = lower_bound(randNumVector.begin(), randNumVector.end(), 7);
    cout << upperBound3-randNumVector.begin() << '\n'; //10 //7���Ͽ��� 7 �ʰ��� ���ϴ� ������ ��ġ
    cout << lowerBound3-randNumVector.begin() << '\n'; //10 //7�̸����� 7 �ʰ��� ���ϴ� ������ ��ġ
    cout << upperBound3-lowerBound3 << '\n'; //0 //randNumVector���� 7�� ����

    return 0;
}
