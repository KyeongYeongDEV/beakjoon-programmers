#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    
    for(int h = 3; h <= total; h++){
        if(total % h == 0){
            int w = total / h;
            
            if(w >= h && (h-2) * (w-2) == yellow){
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}