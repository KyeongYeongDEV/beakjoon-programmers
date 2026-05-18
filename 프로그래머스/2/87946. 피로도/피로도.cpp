#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    
}

//["최소 필요 피로도", "소모 피로도"] 
int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    //입장 피로도는 가장 크고, 소모 피로도는 가장 작은 순으로 정렬 후 
    // 피로도 다 쓸 때까지 사용
    
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int tmp_k = k;
        int count = 0;
         for(auto& dungeon : dungeons) {
             if(tmp_k >= dungeon[0] && tmp_k - dungeon[0] >= 0) {
                tmp_k -= dungeon[1];
                 count++;
             } else break;
         }
        
        answer = max(answer, count);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}

/*
최소 피로도 = 던전을 돌기 전에 가지고 있어야 함
소모 피로도 = 던전을 탐험한 후 소모되는 피로도
최소 필요 피로도"가 80, "소모 피로도"가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도는 80 이상 이어야 하며, 
던전을 탐험한 후에는 피로도 20이 소모됩니다
*/