#include <iostream>
#include <string>
#include <stack>
#include <vector> 
#include <iomanip>
using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string str;
    cin >> n >> str;

    vector<double> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    stack<double> s;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            s.push(values[c - 'A']);
        } else {
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();

            double result = 0.0;
            if (c == '*') {
                result = op1 * op2;
            } else if (c == '/') {
                result = op1 / op2;
            } else if (c == '+') {
                result = op1 + op2;
            } else if (c == '-') {
                result = op1 - op2;
            }
            s.push(result);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
}