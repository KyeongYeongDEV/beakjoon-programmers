#include <iostream>
#include <deque>
using namespace std;

int main() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    deque<pair<int, int> > dq;
    for (int i = 1; i <= n; i++) {
        int move;
        cin >> move;
        dq.push_back(make_pair(move, i));
    }

    while (!dq.empty()) {
        int cur_move = dq.front().first;
        int cur_idx = dq.front().second;
        dq.pop_front();

        cout << cur_idx << " ";

        if (dq.empty()) break;

        if (cur_move > 0) {
            for (int i = 0; i < cur_move - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < abs(cur_move); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}
