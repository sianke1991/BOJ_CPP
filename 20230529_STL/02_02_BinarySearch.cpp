#include <bits/stdc++.h>

using namespace std;

int main() {
    int randNum[] = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};
    int len = (int)((sizeof randNum)/(sizeof *randNum));

    //randNum�� -12345�� �ִ����� -23425�� �ִ��� ���θ� �����Ѵ�.

    //����Ž���� �����ϱ� �� �迭�� �����ؾ� �Ѵ�.
    sort(randNum, randNum+len);
    cout << binary_search(randNum, randNum+len, -12345) << '\n'; //0 //randNum�� -12345�� ����.
    cout << binary_search(randNum, randNum+len, -23425) << '\n'; //1 //randNum�� -23425�� �ִ�.


    vector<int> randNumVector = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};

    //randNumVector�� -12345�� �ִ����� -23425�� �ִ��� ���θ� �����Ѵ�.

    //����Ž���� �����ϱ� �� vector�� �����ؾ� �Ѵ�.
    sort(randNumVector.begin(), randNumVector.end());
    cout << binary_search(randNumVector.begin(), randNumVector.end(), -12345) << '\n'; //0 //randNumVector�� -12345�� ����
    cout << binary_search(randNumVector.begin(), randNumVector.end(), -23425) << '\n'; //1 //randNumVector�� -23425�� �ִ�.

    return 0;
}
