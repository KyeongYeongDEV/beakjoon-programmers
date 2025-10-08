#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    map<int, pair<int, int> > keypad;
    keypad[1] = {0, 0}; keypad[2] = {0, 1}; keypad[3] = {0, 2};
    keypad[4] = {1, 0}; keypad[5] = {1, 1}; keypad[6] = {1, 2};
    keypad[7] = {2, 0}; keypad[8] = {2, 1}; keypad[9] = {2, 2};
    keypad[10] = {3, 0}; keypad[0] = {3, 1}; keypad[12] = {3, 2};

    int left = 10;
    int right = 12;
    
    for(int i = 0 ; i < numbers.size(); i++) {
        int num = numbers[i];
        
        if(num == 1 || num == 4 || num == 7) {
            answer += 'L';
            left = num; 
        } else if(num == 3 || num == 6 || num == 9) {
            answer += 'R';
            right = num; 
        } else {
            pair<int, int> target = keypad[num];
            pair<int, int> p_left = keypad[left];
            pair<int, int> p_right = keypad[right];
            
            int left_dist = abs(target.first - p_left.first) + abs(target.second - p_left.second);
            int right_dist = abs(target.first - p_right.first) + abs(target.second - p_right.second);
            
            if (left_dist < right_dist) {
                answer += 'L';
                left = num;
            } else if (right_dist < left_dist) {
                answer += 'R';
                right = num;
            } else {
                if (hand == "right") {
                    answer += 'R';
                    right = num; 
                } else { 
                    answer += 'L';
                    left = num; 
                }
            }
        } 
    }
    
    return answer;
}