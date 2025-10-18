#include <iostream>
#include <stack>
using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

    while (n--) {
        string s;
        cin>>s;

        stack<char> left_st;
        stack<char> right_st;

        for (char c : s) {
            if (c == '<') {
                if (!left_st.empty()) {
                    right_st.push(left_st.top());
                    left_st.pop();
                }
            } else if (c == '>') {
                if (!right_st.empty()) {
                    left_st.push(right_st.top());
                    right_st.pop();
                }
            } else if (c == '-') {
                if (!left_st.empty()) {
                    left_st.pop();
                }
            } else {
                left_st.push(c);
            }
        }


        while (!left_st.empty()) {
            right_st.push(left_st.top());
            left_st.pop();
        }

        while (!right_st.empty()) {
            cout << right_st.top();
            right_st.pop();
        }
        cout<<endl;
    }
}
