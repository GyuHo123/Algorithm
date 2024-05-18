#include <bits/stdc++.h>

using namespace std;

int arr[201][201], visited[201][201], cnt;

struct p{
    int x, y;
};

void bfs(int x, int y){
    stack<int> st;
    st.push(y);
    visited[x][y] = 1;
    visited[y][x] = 1;
    while(!st.empty()){
        int t = st.top(); st.pop();
        for(int i = 0; i <= 200; i++){
            if(arr[t][i] && !visited[t][i]){
                int nx = i;
                visited[t][i] = 1;
                visited[i][t] = 1;
                st.push(i);
            }
        }
    }
    cnt++;
    cout << cnt << endl;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<pair<int, int>> s1;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++){
        for(auto t: computers[i]){
            if(t){
                arr[cnt2][cnt1] = 1;
                s1.insert({cnt2, cnt1});
            }
            cnt1++;
        }
        cnt1 = 0;
        cnt2++;
    }
    for(auto t: s1){
        if(!visited[t.first][t.second] && arr[t.first][t.second]) bfs(t.first, t.second);
    }
    answer = cnt;
    return answer;
}