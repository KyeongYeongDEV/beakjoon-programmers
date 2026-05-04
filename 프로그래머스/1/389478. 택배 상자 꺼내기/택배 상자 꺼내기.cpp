#include <string>
#include <vector>

using namespace std;
// n = 총개수
// w = 가로 길이
// num = 찾고자하는 수
int solution(int n, int w, int num) {
    int answer = 0;
    int rows = n/w +(n%w == 0 ? 0 : 1);
    
    // 지도 생성 및 초기화
    vector< vector<int> > map(rows, vector<int>(w,0));
    
    int cnt = 1;
    int target_x, target_y;
    for(int i = 0 ; i < n; i++){
        if(i % 2 == 0){ // 짝수 층
            for(int j = 0 ; j < w; j++){
                if(cnt > n) break;
                
                if(num == cnt) {
                    target_x = i;
                    target_y = j;
                }
                map[i][j] = cnt++;
                
            }  
        } else { // 홀수 층
            for(int j = w-1 ; j >= 0; j--){
                if(cnt > n) break;
                if(num == cnt) {
                    target_x = i;
                    target_y = j;
                }
                map[i][j] = cnt++;
            } 
        }
    }
    
    for (int i = target_x; i < rows; i++){
        if(map[i][target_y] != 0){
            answer++;
        }
    }
    return answer;
}
