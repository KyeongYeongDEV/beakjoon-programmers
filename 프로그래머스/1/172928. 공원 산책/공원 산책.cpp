#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    
    // H,W 크기 구하기 
    int H = park.size();
    int W = park[0].size();
    
    int curx = 0;
    int cury = 0;
    
    for(int x = 0; x < H; x++){ 
        for(int y = 0; y < W; y++){
            if(park[x][y] == 'S'){
                curx = x;
                cury = y;
            } 
        }
    }
    
    for (string route : routes) {
        char dir = route[0];
        int dist = route[2] - '0';
        
        int nx = curx;
        int ny = cury;
        int canMove = 1;
        
        for(int i = 0; i < dist; i++){
            if(dir == 'N') nx--;
            else if (dir == 'S') nx++;
            else if (dir == 'W') ny--;
            else if (dir == 'E') ny++;
            
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || park[nx][ny] == 'X') {
                canMove = false;
                break;
            }
        }
        
        if (canMove == 1){
            curx = nx;
            cury = ny;
        }
    }

    
    return {curx, cury};
}
