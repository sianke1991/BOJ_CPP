#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    // 키에 대응되는 값을 저장하는 자료 구조
    // Hash Map
    // CRUD가 전부 상수 시간이다. (해시 충돌이 일어날 때 마다 성능이 저하된다.)

    // 해시함수는 임의 길이의 데이터를 고정된 길이의 데이터로 대응시키는 함수이다.
    // 예를 들어 16 자리 카드 번호를 뒤의 4 자리의 정수로 대응시키는 것

    // 해시 충돌
    // 서로 다른 키가 같은 해시 값을 갖는 경우
    // Chaining
        // Value로 리스트를 둔다. (삽입이 일어날 때 unshift을 한다.)
    // Open Addressing
        // erase 시 해당 칸에는 dummy 값을 넣는다.
        // null 이 아닌 dummy 값을 넣음으로써 이후에 조회 시 해당 칸에서 조회가 종료되지 않도록 만들어준다.
        // erase 이후 insert 시 dummy 칸에 insert가 가능할 수 있도록 해야 한다.
        // Linear Probing: 선형 탐색 (충돌이 일어났을 때 바로 오른쪽 칸에 넣는다.) (캐시 적중률? Cache Hit Rate)
        // Quadratic Probing: 제곱 탐색 (충돌 발생 시 오른쪽으로 1칸, 3칸, 5칸 씩 이동하는 방식)
        // Double Hashing: 해시 충돌 시 점프 할 칸의 개수를 또 다른 해시로 계산한다.

    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); // set에 값을 넣는다.
    s.insert(-10); // 이미 들어가 있는 값은 더 들어가지 않는다.

    cout << s.erase(100) << '\n'; // erase는 집합에 값을 지우고, 지웠다면 1을 지우지 못했다면 0을 반환한다.
    cout << s.erase(20) << '\n';

    if (s.find(15) != s.end()) cout << "15 in s\n"; // find는 값을 찾아서 iterator를 반환하는데, 값을 발견하지 못했다면 end()를 반환한다.
    else cout << "15 not in s\n";
    cout << s.size() <<'\n'; // 집합의 크기
    cout << s.count(50) << '\n'; // 집합에 값 50이 들어있는 개수 (값이 있으면 1, 값이 없으면 0)
    for (auto e:s) cout << e << ' '; // range-based for loop
    cout << '\n';
    return 0;
}
