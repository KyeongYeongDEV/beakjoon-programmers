#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;



int solution(vector<vector<int>> rectangle, 
             int characterX, int characterY, 
             int itemX, int itemY) {
    // 이전 테스트 케이스의 데이터가 남지 않도록 초기화
    int board[101][101];
    memset(board, 0, sizeof(board));
    
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    // 모든 사각형을 맵에 그린다. 2배 확장
    for(auto& rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                
                // 사각형의 내부일 경우 '-1'로 마킹
                if(i > x1 && i < x2 && j > y1 && j < y2) { 
                    board[i][j] = -1;
                }
                
                // 사각형의 '테두리'인 경우 '1'로 마킹
                else if(board[i][j] != -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
    
    queue<pair<int, int> > q;
    // 시작점 좌표 2배 확장하여 큐에 삽입
    q.push({characterX * 2, characterY * 2});
    
    // 방문 여부와 거리 기록할 배열(시작점 1로 잡음)
    vector<vector<int> > dist(101, vector<int>(101, 0));
    dist[characterX * 2][characterY * 2] = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == itemX * 2 && y == itemY * 2){
            return (dist[x][y] - 1) / 2;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < 101 && ny >= 0 && ny < 101){
                // 테두리이면서 방문 전인 곳
                if(board[nx][ny] == 1 && dist[nx][ny] == 0) { 
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return 0;
}