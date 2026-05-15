#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
    1. N*N = 정사각형
    2. 가장 아래칸부터 쌓임
    3. 바구니로 옮김
    4. 만약 바구니에 같은 인형이 2개 겹치면 인형 삭제
    5. 인형이 없는 곳을 집을 시 아무일도 없음
    6. N = 5 ~ 30
    7. moves = 1 ~ 1000
*/ 

// 격자의 상태가 담긴 2차원 배열 board
// 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
   
    int N = board.size();
    stack<int> s;
    
    for(int move : moves) {
        int cur = move - 1;
        
        for(int i = 0; i < N; i++ ){
            if(board[i][cur] != 0){
                if( !s.empty() && s.top() == board[i][cur]) {
                    s.pop();
                    answer += 2;
                } else {
                    s.push(board[i][cur]);
                }
                board[i][cur] = 0;
                
                break;
            }
        }
    }
    
    
    
    return answer;
}

