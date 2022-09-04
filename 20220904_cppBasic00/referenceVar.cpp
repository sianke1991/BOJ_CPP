#include <iostream>
#include <vector>

void swap1(int* a, int* b) {
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

void swap2(int& a, int& b){ //레퍼런스 함수 (C++ 에서 사용 가능)
    int tmp = a;
    a = b;
    b = tmp;
}


void chg1(std::vector <int> &v){ //&가 없이 돌리면 vector 내 원소를 변경할 수 없다.
    v[10] = 7;
}


int main() {

    int arr2[1000];
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // 이 뒤에는 cin만 사용해야 한다.
    // 동기화를 끊는다. (c 표준 입출력과 c++ 표준 입출력)
    // endl은 시간이 많이 걸린다.
    std::cout << "hello" << std::endl;
    std::cout << "hello\n" ;

    // c 기준 swap1
    /*
    int a=3; int b=5;
    swap1(&a, &b);
    std::cout << a << b;
    */

    // c++ 기준 swap2
    /*
    swap2(a, b);
    std::cout << a << b;
    */

    std::vector<int> v(100);

    chg1(v);
    std::cout << v[10];
    v[10]=7;
    std::cout << v[10];

    // 범위 기반 for문
    int arr[5] = {1, 2, 3, 4, 5};
    for (int &n:arr){ //범위 기반 for문을 사용하는데 레퍼런스 변수를 사용할 수 있다.
        std::cout << n;
        n++;
    }
    std::cout << std::endl;
    for (int n:arr){
        std::cout << n;
    }


    return 0;
}
