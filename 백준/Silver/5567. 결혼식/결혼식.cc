#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 501

using namespace std;

int n, m;
vector<int> v1[MAXN];
int visited[MAXN];

struct p{
    int x, cnt;
};

int dfs(){
    int cnt = 0;
    stack<p> st;
    st.push({1, 0});
    visited[1] = 1;
    while(!st.empty()){
        p t = st.top();
        st.pop();
        for(auto temp : v1[t.x]){
            if(!visited[temp] && t.cnt + 1 < 3){
                cnt += 1;
                st.push({temp, t.cnt + 1});
                visited[temp] = 1;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, m){
        pair<int, int> t;
        cin >> t.first >> t.second;
        v1[t.first].push_back(t.second);
        v1[t.second].push_back(t.first);
    }
    cout << dfs();
}