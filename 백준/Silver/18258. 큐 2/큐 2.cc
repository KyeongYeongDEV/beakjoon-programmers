#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    queue<int> q;

    while(n--) {
        string s;
        cin >> s;

        if (s == "push") {
            int tmp;
            cin >> tmp;
            q.push(tmp);

        } else if (s == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }

        } else if (s == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (s == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
            }
        } else if (s == "empty") {
            cout << (q.empty()? 1 : 0) << "\n";
        } else if (s == "size") {
            cout<< q.size() << "\n";
        }
    }
}