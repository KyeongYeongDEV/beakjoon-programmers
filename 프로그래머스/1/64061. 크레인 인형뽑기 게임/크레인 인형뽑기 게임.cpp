#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket; 

    for(int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;
        int doll = 0;          

        for(int j = 0; j < board.size(); j++) {
            if (board[j][col] != 0) {
                doll = board[j][col]; 
                board[j][col] = 0;   
                break; 
            }
        }
        
        if(doll != 0) {
            if(!basket.empty() && basket.top() == doll) {
                basket.pop(); 
                answer += 2;   
            } else {
                basket.push(doll); 
            }
        }
    }
    
    return answer;
}