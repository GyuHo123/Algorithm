#include <iostream>
#include <string>
#define loop(i, s, n) for(int i = s ; i <= n; i++)
using namespace std;

int answer = 0;

void isPalin(string s, int l, int r){
    while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]){
        l--;
        r++;
    }
    answer = max(answer, r - l);
}

int solution(string s)
{
    
    loop(i, 0, s.size() - 1){
        isPalin(s, i, i + 1);
        isPalin(s, i, i);
    }
    
    return answer - 1;
}