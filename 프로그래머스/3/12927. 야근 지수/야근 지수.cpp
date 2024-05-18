#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(auto t: works){
        pq.push(t);
    }
    
    while(n){
        int max1 = pq.top();
        pq.pop();
        if(max1 == 0) pq.push(0);
        else{
            max1--;
            pq.push(max1);
        }
        n--;
    }
    
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}