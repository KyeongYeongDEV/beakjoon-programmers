#include <string>
#include <vector>
#include <algorithm>

using namespace std;



void calc(vector<int>& answer, vector<int>& answers){
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int one = 0;
    int two = 0;
    int three = 0;

    
    for(int i = 0; i < answers.size(); i++) {
        int tmp1 = i % arr[0].size();
        int tmp2 = i % arr[1].size();
        int tmp3 = i % arr[2].size();
        
        if(answers[i] == arr[0][tmp1]) one++;
        if(answers[i] == arr[1][tmp2]) two++;
        if(answers[i] == arr[2][tmp3]) three++;
    }
    
    
    int max_tmp = max(one, two);
    max_tmp = max(max_tmp, three);
    
    if(max_tmp == one) answer.push_back(1);
    if(max_tmp == two) answer.push_back(2);
    if(max_tmp == three) answer.push_back(3);
    
    
    
    sort(answer.begin(), answer.end());    
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    calc(answer, answers);
    
    return answer;
}