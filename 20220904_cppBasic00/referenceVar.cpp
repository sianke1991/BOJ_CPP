#include <iostream>
#include <vector>

void swap1(int* a, int* b) {
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

void swap2(int& a, int& b){ //���۷��� �Լ� (C++ ���� ��� ����)
    int tmp = a;
    a = b;
    b = tmp;
}


void chg1(std::vector <int> &v){ //&�� ���� ������ vector �� ���Ҹ� ������ �� ����.
    v[10] = 7;
}


int main() {

    int arr2[1000];
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // �� �ڿ��� cin�� ����ؾ� �Ѵ�.
    // ����ȭ�� ���´�. (c ǥ�� ����°� c++ ǥ�� �����)
    // endl�� �ð��� ���� �ɸ���.
    std::cout << "hello" << std::endl;
    std::cout << "hello\n" ;

    // c ���� swap1
    /*
    int a=3; int b=5;
    swap1(&a, &b);
    std::cout << a << b;
    */

    // c++ ���� swap2
    /*
    swap2(a, b);
    std::cout << a << b;
    */

    std::vector<int> v(100);

    chg1(v);
    std::cout << v[10];
    v[10]=7;
    std::cout << v[10];

    // ���� ��� for��
    int arr[5] = {1, 2, 3, 4, 5};
    for (int &n:arr){ //���� ��� for���� ����ϴµ� ���۷��� ������ ����� �� �ִ�.
        std::cout << n;
        n++;
    }
    std::cout << std::endl;
    for (int n:arr){
        std::cout << n;
    }


    return 0;
}
