#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int cnt[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    stack<pair<int, int>> stk;
    pair<int, int> p;
    cin >> n; int arr[n], ans[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for(int i = n - 1; i >= 0; i--){
        p.first = arr[i]; p.second = cnt[p.first];
        if(stk.empty()) {
            stk.push(p);
            ans[i] = -1;
        }
        else{
            while(!stk.empty() && stk.top().second <= p.second){
                stk.pop();
            }
            if(stk.empty()) ans[i] = -1;
            if(!stk.empty() && stk.top().second > p.second){
                ans[i] = stk.top().first;
            }
            stk.push(p);
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}