#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K;
    cin >> K;
    stack<int> st;

    for (int i=0; i<K; i++) {
        int elem;
        cin >> elem;
        switch (elem)
        {
            case 0:
                st.pop();
                break;
            default:
                st.push(elem);
                break;
        }
    }

    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result;
    return 0;
}
