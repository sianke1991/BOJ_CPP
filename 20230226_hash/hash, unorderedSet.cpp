#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    // Ű�� �����Ǵ� ���� �����ϴ� �ڷ� ����
    // Hash Map
    // CRUD�� ���� ��� �ð��̴�. (�ؽ� �浹�� �Ͼ �� ���� ������ ���ϵȴ�.)

    // �ؽ��Լ��� ���� ������ �����͸� ������ ������ �����ͷ� ������Ű�� �Լ��̴�.
    // ���� ��� 16 �ڸ� ī�� ��ȣ�� ���� 4 �ڸ��� ������ ������Ű�� ��

    // �ؽ� �浹
    // ���� �ٸ� Ű�� ���� �ؽ� ���� ���� ���
    // Chaining
        // Value�� ����Ʈ�� �д�. (������ �Ͼ �� unshift�� �Ѵ�.)
    // Open Addressing
        // erase �� �ش� ĭ���� dummy ���� �ִ´�.
        // null �� �ƴ� dummy ���� �������ν� ���Ŀ� ��ȸ �� �ش� ĭ���� ��ȸ�� ������� �ʵ��� ������ش�.
        // erase ���� insert �� dummy ĭ�� insert�� ������ �� �ֵ��� �ؾ� �Ѵ�.
        // Linear Probing: ���� Ž�� (�浹�� �Ͼ�� �� �ٷ� ������ ĭ�� �ִ´�.) (ĳ�� ���߷�? Cache Hit Rate)
        // Quadratic Probing: ���� Ž�� (�浹 �߻� �� ���������� 1ĭ, 3ĭ, 5ĭ �� �̵��ϴ� ���)
        // Double Hashing: �ؽ� �浹 �� ���� �� ĭ�� ������ �� �ٸ� �ؽ÷� ����Ѵ�.

    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); // set�� ���� �ִ´�.
    s.insert(-10); // �̹� �� �ִ� ���� �� ���� �ʴ´�.

    cout << s.erase(100) << '\n'; // erase�� ���տ� ���� �����, �����ٸ� 1�� ������ ���ߴٸ� 0�� ��ȯ�Ѵ�.
    cout << s.erase(20) << '\n';

    if (s.find(15) != s.end()) cout << "15 in s\n"; // find�� ���� ã�Ƽ� iterator�� ��ȯ�ϴµ�, ���� �߰����� ���ߴٸ� end()�� ��ȯ�Ѵ�.
    else cout << "15 not in s\n";
    cout << s.size() <<'\n'; // ������ ũ��
    cout << s.count(50) << '\n'; // ���տ� �� 50�� ����ִ� ���� (���� ������ 1, ���� ������ 0)
    for (auto e:s) cout << e << ' '; // range-based for loop
    cout << '\n';
    return 0;
}
