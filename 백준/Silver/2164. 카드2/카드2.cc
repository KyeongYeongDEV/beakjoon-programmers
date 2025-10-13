#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    deque<int> q;
    for(int i = 1; i <= n; i++) {
        q.push_back(i);
    }

    while (q.size() > 1) {
        q.pop_front();

        int tmp = q.front();
        q.pop_front();

        q.push_back(tmp);
    }

    cout << q.front() << endl;
}