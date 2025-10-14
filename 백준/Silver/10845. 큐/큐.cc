#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;

        if (s == "push") {
            int x;
            cin>>x;
            q.push(x);

        } else  if (s == "pop") {
            if (q.empty()) {
                cout<<"-1"<<endl;
            } else {
                cout<<q.front()<<endl;
                q.pop();
            }
        } else if (s == "size") {
            cout<<q.size()<<endl;
        } else if (s == "empty") {
            cout<<q.empty()<<endl;
        } else if (s == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout<<q.front()<<endl;
            }
        } else if (s == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout<<q.back()<<endl;
            }
        }
    }
}