#include <bits/stdc++.h>
using namespace std;
int N;

void recursive(int depth) {
    for (int i=0; i<depth; i++) cout << "____"; cout << "\"����Լ��� ������?\"\n";
    for (int i=0; i<depth; i++) cout << "____"; cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for (int i=0; i<depth; i++) cout << "____"; cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for (int i=0; i<depth; i++) cout << "____"; cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    if (depth<N-1) recursive(depth+1);
    for (int i=0; i<depth; i++) cout << "____"; cout << "��� �亯�Ͽ���.\n";
}

int main() {
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursive(0);
    return 0;
}
