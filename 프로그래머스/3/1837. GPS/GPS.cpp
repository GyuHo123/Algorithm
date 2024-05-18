#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    int dp[k][n + 1];
    
    loop(i, 0, k - 1){
        loop(j, 0, n){
            dp[i][j] = INT_MAX;
        }
    }
    
    vector<vector<int>> v(n + 1);
    
    for(auto t: edge_list){
        v[t[0]].push_back(t[1]);
        v[t[1]].push_back(t[0]);
    }
    
    dp[0][gps_log[0]] = 0;

    loop(i, 1, k - 1){
        loop(j, 1, n){
            if(dp[i - 1][j] == INT_MAX) continue;
            loop(l, 0, v[j].size() - 1){
                int nx = v[j][l];
                int cnt = 0;
                if(gps_log[i] != nx) cnt++;
                dp[i][nx] = min(dp[i][nx], dp[i - 1][j] + cnt);
            }
        }
    }
    if(dp[k - 1][gps_log[k - 1]] != INT_MAX) return dp[k - 1][gps_log[k - 1]];
    
    return -1;
}