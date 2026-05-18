#include <string>
#include <vector>
#include <cmath>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int min_x = 0;
    int max_y = 0;
    
    for(auto& size : sizes) {
        int tmp_min = min(size[0], size[1]);
        int tmp_max = max(size[0], size[1]);
        
        min_x = max(min_x, tmp_min);
        max_y = max(max_y, tmp_max);
  
    }
    
    
    return min_x * max_y;
}