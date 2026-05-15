#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) {
    int N = maps.size();
    int M = maps[0].size();
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    
    queue<pair<int,int> > q;
    q.push({0,0});
    int answer = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 목적지 도착
        if(x == N-1 && y == M -1) {
            return maps[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if( nx >= 0 && nx < N && ny >=0 && ny < M ) {
                if(maps[nx][ny] == 1) {
                    maps[nx][ny] = maps[x][y] + 1;
                    q.push({nx,ny});
                }
            }
       
        }
    }
    
    return -1;
}