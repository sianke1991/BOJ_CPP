#include <bits/stdc++.h>

using namespace std;

//정렬 후 배열 내에 두 원소를 꺼내서 cmp0를 호출 한 경우 true가 되어야 한다.
//cmp0를 적용하여 정렬한 경우 문자열배열은 오름차순으로 정렬된다. (배열 내에서 더 오른쪽에 있는 b가 배열 내에서 더 왼쪽에 있는 a보다 사전순으로 더 나중에 나와야 한다.)
bool cmp0(const string& a, const string& b) { //c++에서는 인자로 참조자료형을 받는 경우 디폴트는 deep copy가 이루어진다. 이를 방지하려면 reference를 사용한다.
    return a.compare(b)<0;
}

//cmp1을 적용하여 정렬한 경우 정수 배열은 내림차순으로 정렬된다. (배열 내에서 더 왼쪽에 있는 a가 배열 내에서 더 오른쪽에 있는 b보다 더 크다.)
//왼쪽에 있는 원소가 더 크게 만드는, 내림차순으로 정렬하기 위해 사용하는 함수이다.)
bool cmp1(int a, int b) {
    return a-b>0;
}

int main() {
    string str0 = "Lorem";
    string str1 = "ipsum";
    string str2 = "dolor";

    cout << str0.compare(str1) << '\n'; //-1 (사전순으로 정렬했을 때 str0이 str1 보다 먼저 나오므로 음수가 반환됨)
    cout << str1.compare(str2) << '\n'; //1 (사전순으로 정렬했을 때 str1이 str2 보다 나중에 나오므로 양수가 반환됨)

    string strs[10];
    strs[0] = "Lorem";
    strs[1] = "ipsum";
    strs[2] = "dolor";
    strs[3] = "sit";
    strs[4] = "amet";
    strs[5] = "consectetur";
    strs[6] = "adipiscing";
    strs[7] = "elit";
    strs[8] = "Maecenas";
    strs[9] = "sollicitudin";

    sort(strs, strs+10); //문자열 배열 정렬
    for (string str:strs) {
        cout << str << ' '; //Lorem Maecenas adipiscing amet consectetur dolor elit ipsum sit sollicitudin
    }
    cout << '\n';

    sort(strs, strs+10, greater<string>()); //문자열 배열 내림차순 정렬
    for (string str:strs) {
        cout << str << ' '; //sollicitudin sit ipsum elit dolor consectetur amet adipiscing Maecenas Lorem
    }
    cout << '\n';

    sort(strs, strs+10, cmp0); //cmp0를 적용하여 문자열 배열 정렬
    for (string str:strs) {
        cout << str << ' '; //Lorem Maecenas adipiscing amet consectetur dolor elit ipsum sit sollicitudin
    }
    cout << '\n';

    int nums[] = {2, 4, 1, 1, 6, 2, 3, 4, 6, 4};
    sort(nums, nums+10, cmp1); //cmp1를 적용하여 정수 배열 정렬
    for (int elem:nums) {
        cout << elem << ' '; //6 6 4 4 4 3 2 2 1 1
    }
    cout << '\n';

    vector<int> v0 = {2, 4, 1, 1, 6, 2, 3, 4, 6, 4};
    sort(v0.begin(), v0.end(), greater<int>()); //vector를 정혈할 때는 begin, end 메서드를 사용할 수 있다. (각각 [vector의 첫 원소의 주소], [vector의 마지막 원소의 주소의 다음 주소]를 반환한다.)
    for (int elem:v0) {
        cout << elem << ' '; //6 6 4 4 4 3 2 2 1 1
    }
    cout << '\n';

    vector<pair<int, int>> v1 = {{1, 3}, {1, 2}, {2, 3}, {3, 1}, {3, 3}, {1, 2}, {2, 5}, {2, 6}, {5, 3}, {2, 4}};
    sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    for (pair<int, int> p:v1) {
        cout << '{' << p.first << ", " << p.second << "} "; //{5, 3} {3, 3} {3, 1} {2, 6} {2, 5} {2, 4} {2, 3} {1, 3} {1, 2} {1, 2}
    }
    cout << '\n';

    vector<tuple<int, int, int>> v2 = {{5, 2, 5}, {2, 4, 6}, {5, 4, 4}, {4, 6, 6}, {3, 6, 3}, {1, 3, 5}, {3, 5, 1}, {2, 6, 3}, {4, 6, 3}, {2, 1, 6}};
    sort(v2.begin(), v2.end(), greater<tuple<int, int, int>>());
    for (tuple<int, int, int> t:v2) {
        cout << '{' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << "} "; //{5, 4, 4} {5, 2, 5} {4, 6, 6} {4, 6, 3} {3, 6, 3} {3, 5, 1} {2, 6, 3} {2, 4, 6} {2, 1, 6} {1, 3, 5}
    }
    cout << '\n';

    return 0;
}
