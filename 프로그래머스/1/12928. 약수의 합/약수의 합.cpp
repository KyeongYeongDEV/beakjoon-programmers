#include <string>
#include <vector>

using namespace std;

int sol(int n) {
    int result = 0;
    for(int i = 1; i <= n ; i++){
        if(n % i == 0){
            result += i;
        }
    }
    
    return result;
}

int solution(int n) {
    int answer = sol(n);
    
    return answer;
}

