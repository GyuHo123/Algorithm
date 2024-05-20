#include <iostream>
#include <vector>
#define MAXN 200001
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int dp[MAXN], dp1[MAXN];

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    dp[0] = sticker[0];
    dp[1] = max(sticker[0], sticker[1]);
    loop(i, 2, sticker.size() - 2){
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    dp1[1] = sticker[1];
    dp1[2] = max(sticker[1], sticker[2]);
    loop(i, 3, sticker.size() - 1){
        dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
    }
    
    return max(dp[sticker.size() - 2], dp1[sticker.size() - 1]);
}