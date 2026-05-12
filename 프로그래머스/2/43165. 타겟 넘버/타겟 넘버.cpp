#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int target, int index, int current_sum) {
    // 종료 조건 = 모든 숫자를 다 확인했는가
    if (index == numbers.size()) {
        // 지금까지의 합이 타켓과 일치하면 정답 카운트 증가
        if(current_sum == target) {
            answer++;
        }
        return ;
    }
    
    dfs(numbers, target, index + 1, current_sum + numbers[index]);
    
    dfs(numbers, target, index + 1, current_sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}