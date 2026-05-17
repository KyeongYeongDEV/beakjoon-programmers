#include <string>
#include <vector>

using namespace std;

void dfs(int cur, int n, vector<vector<int>>& computers, vector<bool>& visited){
    // 방문하지 않은 노드 방문 처리
    visited[cur] = true;
    
    // 모든 노드를 돌며
    for(int i = 0; i < n; i++) {
        // 현재 노드랑 연결되어 있고 방문을 하지 않았다면 
        if(computers[cur][i] == 1 && !visited[i]) {
            // 방문 처리를 위해 재귀를 돌린다
            dfs(i, n, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    // 노드를 돌면서
    for(int i = 0; i < n ; i++) {
        // 해당 노드에 방문을 하지 않았다면
        if(!visited[i]) {
            // 하나의 연결된 그룹이므로 ++;
            answer++;
            // 해당 노드에 연결된 노드들을 방문 처리해준다.
            dfs(i, n, computers, visited);
        }
    }
      
    return answer;
}