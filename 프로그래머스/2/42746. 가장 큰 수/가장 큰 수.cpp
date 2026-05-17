#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 커스텀 정렬 기준: 두 문자열을 서로 다른 순서로 붙여보고 더 큰 쪽을 선택
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;
    
    // 1. 모든 정수를 문자열로 변환하여 저장 (to_string 사용)
    for (int num : numbers) {
        str_numbers.push_back(to_string(num));
    }
    
    // 2. 커스텀 비교 함수를 사용하여 고성능 정렬 수행 (O(N log N))
    sort(str_numbers.begin(), str_numbers.end(), compare);
    
    // 3. 정렬된 문자열들을 순서대로 이어 붙이기
    for (const string& str : str_numbers) {
        answer += str;
    }
    
    // 4. 예외 처리 (Edge Case): 모든 숫자가 0인 경우 (예: [0, 0, 0] -> "000"이 됨)
    // 정렬 결과 맨 앞글자가 '0'이라는 것은 뒤의 모든 숫자도 0이라는 뜻이므로 "0"을 반환
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}