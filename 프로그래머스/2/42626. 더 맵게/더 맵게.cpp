#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto t: scoville){
        pq.push(t);        
    }
    
    while(pq.size() > 1 && pq.top() < K){
        int temp = pq.top(); pq.pop();
        int temp2 = pq.top(); pq.pop();
        temp += temp2 * 2;
        pq.push(temp);
        answer++;
    }
    
    if(pq.top() >= K) return answer;
    else return -1;
}