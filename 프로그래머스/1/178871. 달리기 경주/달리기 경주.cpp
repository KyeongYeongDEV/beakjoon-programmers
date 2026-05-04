#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> player_map;
    for(int i = 0; i < players.size(); i++) {
        player_map[players[i]] = i;
    }
    
    for(string calling : callings) {
        int cur_idx = player_map[calling];
        
        int prev_idx = cur_idx - 1;
        string prev_name = players[prev_idx];
        
        players[prev_idx] = calling;
        players[cur_idx] = prev_name;
        
        player_map[calling] = prev_idx;
        player_map[prev_name] = cur_idx;
        
    }
    
    return players; 
}