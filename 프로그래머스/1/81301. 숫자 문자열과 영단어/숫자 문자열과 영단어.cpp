#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string result = ""; 
    string tmp = "";    
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9') { 
            result += s[i];
        } 
        else {
            tmp += s[i];
            
            if(tmp == "zero") { result += '0'; tmp = ""; }
            else if(tmp == "one") { result += '1'; tmp = ""; }
            else if(tmp == "two") { result += '2'; tmp = ""; }
            else if(tmp == "three") { result += '3'; tmp = ""; }
            else if(tmp == "four") { result += '4'; tmp = ""; }
            else if(tmp == "five") { result += '5'; tmp = ""; }
            else if(tmp == "six") { result += '6'; tmp = ""; }
            else if(tmp == "seven") { result += '7'; tmp = ""; }
            else if(tmp == "eight") { result += '8'; tmp = ""; }
            else if(tmp == "nine") { result += '9'; tmp = ""; }
        }
    }
    
    
    return stoi(result);
}