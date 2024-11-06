#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());
    if(!citations[0]) return 0;
    loop(i, 0, citations.size() - 1){
        if(citations[i] > i) answer++;
        else break;
    }
    return answer;
    
    return answer;
    
}