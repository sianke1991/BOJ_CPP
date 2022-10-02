#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
const int PUSH_INT = 0;
const int POP_INT = 1;
const int SIZE_INT = 2;
const int EMPTY_INT = 3;
const int TOP_INT = 4;

int commandToNum(string command) {
    if (command=="push") return PUSH_INT;
    if (command=="pop") return POP_INT;
    if (command=="size") return SIZE_INT;
    if (command=="empty") return EMPTY_INT;
    if (command=="top") return TOP_INT;
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> result;
    stack<int> st;
    for (int i=0; i<N; i++) {
        string command;
        int cmdNum;
        cin >> command;
        switch (commandToNum(command))
        {
            case PUSH_INT:
                cin >> cmdNum;
                st.push(cmdNum);
                break;
            case POP_INT:
                if (st.empty()) result.push_back(-1);
                else {
                    result.push_back(st.top());
                    st.pop();
                }
                break;
            case SIZE_INT:
                result.push_back(st.size());
                break;
            case EMPTY_INT:
                result.push_back(st.empty());
                break;
            case TOP_INT:
                if (st.empty()) result.push_back(-1);
                else result.push_back(st.top());
                break;
        }
    }

    for (int i=0; i<result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}
