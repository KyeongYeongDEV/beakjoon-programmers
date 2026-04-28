#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    string str = "AEIOU";
    int arr[5] = {781, 156, 31, 6, 1};
    
    for(int i = 0; i< word.size(); i++){
        char cur = word[i];
        
        for(int j=0; j < 5; j++){
            if(cur == str[j]) {
                answer += (j*arr[i])+1;
                break;
            }
        }
    }
    
    
    return answer;
}