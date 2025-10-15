#include <iostream>
#include <stack>
using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    int result = 0;

    while (n--) {
        string str;
        cin >> str;

        stack<char> st;

        for (char ch : str) {
            if (!st.empty() && ch == st.top()) {
                st.pop();
            }else {
                st.push(ch);
            }
        }

        if (st.empty()) result++;
    }

    cout  << result;
}
