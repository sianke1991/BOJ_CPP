#include <bits/stdc++.h>

using namespace std;

//���� �� �迭 ���� �� ���Ҹ� ������ cmp0�� ȣ�� �� ��� true�� �Ǿ�� �Ѵ�.
//cmp0�� �����Ͽ� ������ ��� ���ڿ��迭�� ������������ ���ĵȴ�. (�迭 ������ �� �����ʿ� �ִ� b�� �迭 ������ �� ���ʿ� �ִ� a���� ���������� �� ���߿� ���;� �Ѵ�.)
bool cmp0(const string& a, const string& b) { //c++������ ���ڷ� �����ڷ����� �޴� ��� ����Ʈ�� deep copy�� �̷������. �̸� �����Ϸ��� reference�� ����Ѵ�.
    return a.compare(b)<0;
}

//cmp1�� �����Ͽ� ������ ��� ���� �迭�� ������������ ���ĵȴ�. (�迭 ������ �� ���ʿ� �ִ� a�� �迭 ������ �� �����ʿ� �ִ� b���� �� ũ��.)
//���ʿ� �ִ� ���Ұ� �� ũ�� �����, ������������ �����ϱ� ���� ����ϴ� �Լ��̴�.)
bool cmp1(int a, int b) {
    return a-b>0;
}

int main() {
    string str0 = "Lorem";
    string str1 = "ipsum";
    string str2 = "dolor";

    cout << str0.compare(str1) << '\n'; //-1 (���������� �������� �� str0�� str1 ���� ���� �����Ƿ� ������ ��ȯ��)
    cout << str1.compare(str2) << '\n'; //1 (���������� �������� �� str1�� str2 ���� ���߿� �����Ƿ� ����� ��ȯ��)

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

    sort(strs, strs+10); //���ڿ� �迭 ����
    for (string str:strs) {
        cout << str << ' '; //Lorem Maecenas adipiscing amet consectetur dolor elit ipsum sit sollicitudin
    }
    cout << '\n';

    sort(strs, strs+10, greater<string>()); //���ڿ� �迭 �������� ����
    for (string str:strs) {
        cout << str << ' '; //sollicitudin sit ipsum elit dolor consectetur amet adipiscing Maecenas Lorem
    }
    cout << '\n';

    sort(strs, strs+10, cmp0); //cmp0�� �����Ͽ� ���ڿ� �迭 ����
    for (string str:strs) {
        cout << str << ' '; //Lorem Maecenas adipiscing amet consectetur dolor elit ipsum sit sollicitudin
    }
    cout << '\n';

    int nums[] = {2, 4, 1, 1, 6, 2, 3, 4, 6, 4};
    sort(nums, nums+10, cmp1); //cmp1�� �����Ͽ� ���� �迭 ����
    for (int elem:nums) {
        cout << elem << ' '; //6 6 4 4 4 3 2 2 1 1
    }
    cout << '\n';

    vector<int> v0 = {2, 4, 1, 1, 6, 2, 3, 4, 6, 4};
    sort(v0.begin(), v0.end(), greater<int>()); //vector�� ������ ���� begin, end �޼��带 ����� �� �ִ�. (���� [vector�� ù ������ �ּ�], [vector�� ������ ������ �ּ��� ���� �ּ�]�� ��ȯ�Ѵ�.)
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
