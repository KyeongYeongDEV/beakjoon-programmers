#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// queries = 회전하는 목록
// 회전에 의해 위치가 바뀐 숫자 중 오름차순으로 배열에 담아 반환
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int> > board(rows, vector<int>(columns));
    
    // 초기화
    int num = 1; 
    for(int i =0 ; i < rows; i++ ){
        for(int j = 0; j < columns; j++){
            board[i][j] = num++;
        }
    }
    
    for(vector<int> querie : queries) {
        int x1 = querie[0] - 1, y1 = querie[1] - 1;
        int x2 = querie[2] - 1, y2 = querie[3] - 1;
        
        int start_num = board[x1][y1];
        int min_val = start_num;
        
        // 좌를 위로
        for(int i = x1; i < x2; i++){
            board[i][y1] = board[i+1][y1];
            min_val = min(min_val, board[i][y1]);
        }
        
        // 아래를 왼으로
        for(int i = y1; i < y2; i++) {
            board[x2][i] = board[x2][i + 1];
            min_val = min(min_val, board[x2][i]);
        }
        
        // 우를 아래로
        for(int i = x2; i > x1; i--) {
            board[i][y2] = board[i-1][y2];
            min_val = min(min_val, board[i][y2]);
        }
        
        // 위를 우로
        for(int i = y2; i > y1; i--) {
            board[x1][i] = board[x1][i-1];
            min_val = min(min_val, board[x1][i]);
        }
        
        
        
        
        
        board[x1][y1+1] = start_num;
        answer.push_back(min_val);
        
    }
    
    
    
    
    return answer;
}
/*
    1. 회전하는 범위가 주어짐 (2, 2, 5, 4)
    2. 범위의 테두리만 회전 - 가운데는 안함
    3. r, c = 2 ~ 100
    4. 아무 회전도 하지 않았을 때, i 행 j 열에 있는 숫자는 ((i-1) x columns + j)
    5. queries의 행의 개수 1 ~ 10,000
    6. 
*/