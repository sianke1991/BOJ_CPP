#include <bits/stdc++.h>

using namespace std;

int main() {
    int randNum[] = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};
    int len = (int)((sizeof randNum)/(sizeof *randNum));

    //randNum에 -12345가 있는지와 -23425가 있는지 여부를 조사한다.

    //이진탐색을 수행하기 전 배열을 정렬해야 한다.
    sort(randNum, randNum+len);
    cout << binary_search(randNum, randNum+len, -12345) << '\n'; //0 //randNum에 -12345는 없다.
    cout << binary_search(randNum, randNum+len, -23425) << '\n'; //1 //randNum에 -23425는 있다.


    vector<int> randNumVector = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};

    //randNumVector에 -12345가 있는지와 -23425가 있는지 여부를 조사한다.

    //이진탐색을 수행하기 전 vector를 정렬해야 한다.
    sort(randNumVector.begin(), randNumVector.end());
    cout << binary_search(randNumVector.begin(), randNumVector.end(), -12345) << '\n'; //0 //randNumVector에 -12345는 없다
    cout << binary_search(randNumVector.begin(), randNumVector.end(), -23425) << '\n'; //1 //randNumVector에 -23425는 있다.

    return 0;
}
