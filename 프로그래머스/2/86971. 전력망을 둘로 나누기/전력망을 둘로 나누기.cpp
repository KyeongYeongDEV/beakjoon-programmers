#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

 // abs()// 절대값
// sqrt() // 제곱근

int bfs(int start, int n, vector<vector<int>>& graph, int v1, int v2)  {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    int count = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        count++;
        
        for(int next : graph[cur]) {
            if((cur == v1 && next == v2) || (cur == v2 && next == v1)) continue;
            
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    return count;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> graph(n+1);
    
    // 그래프 그리기
    for(auto& wire : wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for(auto& wire : wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        
        int tree1 = bfs(v1, n, graph,v1,v2);
        int tree2 = n - tree1;
        
        int result = abs(tree1 - tree2);
        
        answer = min(answer, result);
    }
    
    return answer;
}