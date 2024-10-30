#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 21

using namespace std;

int bfs(vector<int> numbers, int target){
    int cnt = 0;
    queue<int> q; q.push(0);
    loop(i, 0, numbers.size() - 1){
        int size = q.size();
        loop(j, 0, size - 1){
            int t = q.front(); q.pop();
            q.push(t + numbers[i]);
            q.push(t - numbers[i]);
        }
    }
    while(!q.empty()){
        if(q.front() == target) cnt++;
        q.pop();
    }
    return cnt;
}

int solution(vector<int> numbers, int target) {
    return bfs(numbers, target);
}