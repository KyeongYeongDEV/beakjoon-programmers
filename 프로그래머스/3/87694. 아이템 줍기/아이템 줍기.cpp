#include <string>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

struct Point{
  int x, y;  
};

int bfs(Point start, Point target, vector<vector<int>>& graph) {
    vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
    queue<Point> q;
    
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    
    q.push(start);
    visited[start.x][start.y] = 1;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        if(x == target.x && y == target.y) {
            return visited[x][y] / 2;
        }
        
        for(int i = 0; i < 4; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX ) {
                if(graph[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> rectangle, 
             int characterX, int characterY, 
             int itemX, int itemY) {
    
    Point start = {characterX * 2, characterY * 2};
    Point target = {itemX * 2, itemY * 2};
    
    vector<vector<int>> graph(MAX, vector<int>(MAX, 0));
    
    for(auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                if(i > x1 && i < x2 && j > y1 && j < y2) { // 내부
                    graph[i][j] = -1;                    
                } else if(graph[i][j] != -1){ // 테두리
                    graph[i][j] = 1; 
                }

            }
        }
    }
 
    return bfs(start, target, graph);
}