#include <string>
#include <vector>
#include <queue>

using namespace std;

int dc[] = {0,0,1,-1};
int dr[] = {-1, 1, 0, 0};

bool bfs(int r, int c, const vector<string> &place){
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(r,c),0));
    
    int visited[5][5];
    for(int i =0; i < 5; i++){
        for(int j =0; j < 5; j++){
            visited[i][j] = 0;
        }
    }
    
    visited[r][c] = 1;
    
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(dist >= 2) {
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || visited[nr][nc]){
                continue;
            }
            
            if(place[nr][nc] == 'X') {
                continue;
            }
            
            if(place[nr][nc] == 'P') {
                return false;
            }
            
            if(place[nr][nc] == 'O'){
                visited[nr][nc] = 1;
                q.push(make_pair(make_pair(nr,nc), dist + 1));
            }
        }
    }
    
    return true;
}

bool isDistanced(const vector<string> &place){
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++){
            if(place[r][c] == 'P') {
                if(!bfs(r,c,place)){
                    return false;
                }
            }
        }
    }
    
    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i =0 ; i < 5; i++){
        if(isDistanced(places[i])){
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    return answer;
}

 