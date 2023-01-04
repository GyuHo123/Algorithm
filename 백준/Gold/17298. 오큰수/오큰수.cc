#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;

    stack<long long> stk;

    cin >> n; long long arr[n], ans[n];
    for(int i = n - 1; i >= 0; i--){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(stk.empty()) {
            stk.push(arr[i]);
            ans[i] = -1;
        }
        else{
            while(!stk.empty() && stk.top() <= arr[i]){
                stk.pop();
            }
            if(stk.empty()) ans[i] = -1;
            if(!stk.empty() && stk.top() > arr[i]){
                ans[i] = stk.top();
            }
            stk.push(arr[i]);
        }
    }
    for(int i = n - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}