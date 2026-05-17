#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check_words(string target, vector<string>& words) {
    
    for(int i = 0 ; i < words.size(); i++) {
        if(target == words[i]) return true;
    }
    
    return false;
}

// 하나만 다른지 체크
bool check_num(string cur_word, string word) {
    int count = 0;
    
    for(int i = 0 ; i < cur_word.size(); i++) {
        if(cur_word[i] != word[i]) count++;
        
        if( count >= 2) return false;
    }
    
    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    if(!check_words(target, words)) return 0;
    
    vector<int> visited(words.size(), 0);
    queue<pair<string, int> > q;
    
    q.push({begin,0});
    
    
    
    while(!q.empty()) {
        string cur_word = q.front().first;
        int cur_answer = q.front().second;
        q.pop();
        
        if(cur_word == target) return cur_answer;
        
        for(int i = 0; i < words.size(); i++) {
            if(check_num(cur_word, words[i]) && !visited[i] ) {
                visited[i] = 1;
                q.push({words[i], cur_answer + 1});
            }
        }
    }
    
    
    return 0;
}