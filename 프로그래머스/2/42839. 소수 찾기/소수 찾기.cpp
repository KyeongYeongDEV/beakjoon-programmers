#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set <int> unique_numbers;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 1; i <= numbers.length(); i++) {
            string sub = numbers.substr(0,i);
            unique_numbers.insert(stoi(sub));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    for(int num : unique_numbers) {
        if(isPrime(num)) {
            answer++;
        }
    }
    
    
    return answer;
}