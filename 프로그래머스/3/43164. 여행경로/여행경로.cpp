#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool dfs(string cur, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer, int count){
    answer.push_back(cur);
    
    if(count == tickets.size()) return true;
    
    for (int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == cur && !visited[i]) {
            visited[i] = true;
            
            if(dfs(tickets[i][1], tickets, visited, answer, count + 1)) return true;
            
            visited[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, visited, answer, 0);
    
    return answer;
    
}
/*
    1. 항상 INC에서 출발
    2. 3-10000
    3. 주어진 항공권은 모두 사용해야 함
    4. 알파벳 순으로 오름차순
    5. 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
*/