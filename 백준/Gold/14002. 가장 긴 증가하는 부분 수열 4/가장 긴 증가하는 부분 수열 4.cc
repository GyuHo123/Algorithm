#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int maxRes, dp[1001], arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> stk;

    int n, temp, length;
    int index = 1;

    cin >> n;

    dp[1] = 1;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]) {
                maxRes = max(maxRes, dp[j]);
            }
        }
        dp[i] = maxRes + 1;

        if(dp[i-1] < dp[i]){
            index = i;
        }
        maxRes = 0;
    }

    for(int i = 1; i <= n; i++){
        maxRes = max(maxRes, dp[i]);
    }

    for(int i = index; i >= 1; i--){
        if(dp[i] == maxRes){
            stk.push(arr[i]);
            maxRes--;
        }
    }
    cout << stk.size() << endl;
    
    length = stk.size();
    
    for(int i = 0; i < length; i++){
        cout << stk.top() << " ";
        stk.pop();
    }

}