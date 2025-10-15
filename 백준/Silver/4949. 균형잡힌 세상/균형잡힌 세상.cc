#include <iostream>
#include <stack>
using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while (1) {
        string str;
        getline(cin, str);

        if (str == ".") {
            break;
        }
        stack<char> st;

        bool check = true;

        for (char ch : str) {
            if (ch == '(' || ch == '[') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.empty() || st.top() != '(') {
                    check = false;
                    break;
                }
                st.pop();
            } else if (ch == ']') {
                if (st.empty() || st.top() != '[') {
                    check = false;
                    break;
                }
                st.pop();
            }
        }

        if (check && st.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
