#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int visited[51];
int arr[52];
int res;

struct p{
    string s; int cnt;
};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool exist = 0;
    for(auto t: words){
        if(t == target) exist = 1;
    }
    if(!exist) return 0;
    queue<p> q;
    q.push({begin, 0});
    visited[0] = 1;
    while(!q.empty()){
        p t = q.front(); q.pop();
        if(t.s == target) return t.cnt;
        loop(i, 0, words.size() - 1){
            int cnt = 0;
            if(visited[i + 1]) continue;
            loop(j, 0, words[i].size() - 1){
                if(words[i][j] != t.s[j]) cnt++;
                if(cnt == 2) break;
            }
            if(cnt == 1){
                q.push({words[i], t.cnt + 1});
                visited[i + 1] = 1;
            }
        }
    }
    return 0;
}