#include <string>
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[1][1] = triangle[0][0];
    dp[2][1] = triangle[0][0] + triangle[1][0];
    dp[2][2] = triangle[0][0] + triangle[1][1];
    
    for(int i = 3; i <= triangle.size(); i++){
        for(int j = 1; j <= i; j++){
            if(j == 1) dp[i][j] = triangle[i - 1][j - 1] + dp[i - 1][j];
            else if(j == i) dp[i][j] = triangle[i - 1][j - 1] + dp[i - 1][j - 1];
            else dp[i][j] = max(triangle[i - 1][j - 1] + dp[i - 1][j], triangle[i - 1][j - 1] + dp[i - 1][j - 1]);
        }
    }
    for(int j = 1; j <= triangle.size(); j++){
        answer = max(answer, dp[triangle.size()][j]);
    }
    return answer;
}