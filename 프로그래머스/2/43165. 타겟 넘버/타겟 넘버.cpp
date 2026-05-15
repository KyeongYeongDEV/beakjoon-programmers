#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, int target, int index, int current_sum) {
    // 종료 조건
    // 끝까지 다 돌았을 때의 합이 target과 같다면
    if(index == numbers.size()){
        if(current_sum == target) answer++;
        return ;
    }
    
    dfs(numbers, target, index + 1, current_sum + numbers[index]);
    dfs(numbers, target, index + 1, current_sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);    
    return answer;
}