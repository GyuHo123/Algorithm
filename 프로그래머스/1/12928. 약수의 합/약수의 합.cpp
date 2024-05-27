#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    set<int> set1;
    
    if(n == 0) return 0;
    
    for(int i = 1; i <= n; i++){
        if(!(n % i)){
            set1.insert(i);
        }
    }
    
    for(auto t: set1){
        answer += t;
    }
    return answer;
}