#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

// 하나의 서브트리에 속한 노드의 개수를 세는 BFS 함수
int get_tree_size(int start, int n, const vector<vector<int> >& adj, int v1, int v2) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    int count = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        count++; // 방문한 노드 개수 증가
        
        for(int next : adj[cur]) {
            // 현재 끊어버린 간선 이라면 지나가지 않고 패스
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
    
    // 인접 리스트 생성
    vector<vector<int> > adj(n+1);
    for(auto& wire : wires) {
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }
    
    // 모든 간선을 하니씩 무시하며 완전 탐색
    for(auto& wire  : wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        
        int sub_tree_size = get_tree_size(v1, n, adj, v1, v2);
        int other_tree_size = n - sub_tree_size;
        
        int diff = abs(sub_tree_size - other_tree_size);
        answer = min(answer, diff);
    }
    
    
    return answer;
}