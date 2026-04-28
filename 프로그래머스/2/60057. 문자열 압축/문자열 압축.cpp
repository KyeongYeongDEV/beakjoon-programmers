#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    if(s.size() == 1) return 1;
    
    int answer = s.size();
    
    for( int i = 1;  i <= s.size() / 2; i++ ){ // 묶음 단위 설정
        string result = "";
        string prev = s.substr(0,i); // 하나의 압축 단위 만들기
        int count = 1;
        
        for(int j = i; j < s.size(); j+=i){
            string cur = s.substr(j, i);
            
            if(prev == cur) {
                count++;
            } else {
                if(count > 1) {
                    result += to_string(count);
                }
                result += prev;
                
                prev = cur;
                count = 1;
            }
            
        }
        
        if(count > 1) {
            result += to_string(count);
        }
        result += prev;
            
        if(result.size() < answer){
            answer = result.size();
        }
        
    }
    
    return answer;
}