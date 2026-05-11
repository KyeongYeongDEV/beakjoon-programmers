
#include <vector>
#include <algorithm>

using namespace std;

//people = 사람들 몸무게
// limit = 무게 제한
int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    // 가장 가볍, 무겁 사람 인덱스 
    int light = 0;
    int heavy = people.size() - 1;
    
    while(light <= heavy) {
        // 가장 무거운 사람과 가벼운 사람의 조합이 가능한지
        if(people[light] + people[heavy] <= limit) {
            // 둘 다 태울 수 있으면 가벼운 사람 포인터 이동
            light++;
        }
        //무거운 사람은 무저곤 이번에 타야 함
        heavy--;
        
        answer++;
    }
    
    return answer;
}