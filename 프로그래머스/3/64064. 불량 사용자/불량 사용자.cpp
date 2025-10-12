#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<set<string>> result_set;
vector<string> g_user_id;
vector<string> g_banned_id;

bool isMatch(const string& user, const string& banned) {
    if (user.length() != banned.length()) {
        return false;
    }
    
    for (int i = 0; i < user.length(); ++i) {
        if (banned[i] != '*' && user[i] != banned[i]) {
            return false; 
        }
    }
    
    return true;
}

void dfs(int banned_idx, set<string>& current_banned_users) {
    if (banned_idx == g_banned_id.size()) {
        result_set.insert(current_banned_users);
        return;
    }

    const string& banned_pattern = g_banned_id[banned_idx];

    for (int i = 0; i < g_user_id.size(); ++i) {
        const string& user = g_user_id[i];

        if (current_banned_users.count(user)) {
            continue;
        }

        if (isMatch(user, banned_pattern)) {
            current_banned_users.insert(user);
            
            dfs(banned_idx + 1, current_banned_users);
            
            current_banned_users.erase(user);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    g_user_id = user_id;
    g_banned_id = banned_id;
    
    set<string> initial_set;
    
    dfs(0, initial_set);
    
    return result_set.size();
}