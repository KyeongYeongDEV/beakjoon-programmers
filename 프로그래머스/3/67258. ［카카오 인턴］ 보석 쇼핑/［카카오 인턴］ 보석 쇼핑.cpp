#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> unique_gems(gems.begin(), gems.end());
    int total_gem_types = unique_gems.size();

    vector<int> answer = {0, 0};
    int min_length = gems.size() + 1; 

    int start = 0; // 구간의 시작점
    unordered_map<string, int> gem_counts; // 현재 구간에 포함된 보석의 종류와 개수

    for (int end = 0; end < gems.size(); ++end) {
        gem_counts[gems[end]]++;

        while (gem_counts.size() == total_gem_types) {
            int current_length = end - start + 1;

            if (current_length < min_length) {
                min_length = current_length;
                answer = {start + 1, end + 1}; 
            }

            gem_counts[gems[start]]--;
            if (gem_counts[gems[start]] == 0) {
                gem_counts.erase(gems[start]); 
            }
            start++;
        }
    }

    return answer;
}