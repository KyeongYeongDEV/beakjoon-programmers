#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(string cur, vector<vector<string>>& tickets, vector<string>& answer, 
         vector<int>& visited, int count ){
    
    answer.push_back(cur);
    
    if(count == tickets.size()) return true;
    
    for( int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == cur && !visited[i]) {
            visited[i] = 1;
            
            if(dfs(tickets[i][1], tickets, answer, visited, count + 1)) return true;
            
            visited[i] = 0;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> visited(tickets.size(), 0);
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, answer, visited, 0);
    
    
    return answer;
}
