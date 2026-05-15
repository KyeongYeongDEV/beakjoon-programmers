#include <string>
#include <vector>
#include <queue>

using namespace std;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int bfs(char target, int startX, int startY, 
        int N, int M, vector<string>& maps) {
    
    queue<pair<int,int> > q;
    vector<vector<int> > visited(N, vector<int>(M, -1));
    
    q.push({startX, startY});
    visited[startX][startY] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        

        if(maps[x][y] == target) {
            return visited[x][y];
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if(nx >= 0 && nx < N 
              && ny >= 0 && ny < M
              && maps[nx][ny] != 'X' && visited[nx][ny] == -1
              ) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx,ny});
            }
            
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    int N = maps.size(); // 세로
    int M = maps[0].size(); // 가로  
    
    int startX = 0;
    int startY = 0;
    
    int leberX = 0;
    int leberY = 0; 
     
    // 시작점 찾기
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(maps[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            
            if(maps[i][j] == 'L') {
                leberX = i;
                leberY = j;
            }
        }
    }
    
    int leverResult = bfs('L', startX, startY, N, M, maps);
    if(leverResult == -1) return -1;
    
    int endResult = bfs('E', leberX, leberY, N, M, maps);
    if(endResult == -1) return -1;
    
    return leverResult + endResult;
}