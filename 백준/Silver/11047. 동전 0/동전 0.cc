#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001
using namespace std;

int n, temp, cnt, k;
stack<int> stk;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;

    while(n--){
        cin >> temp;
        if(temp <= k) stk.push(temp);
    }
    while(k > 0){
        if(stk.top() > k){
            stk.pop();
            continue;
        }
        k -= stk.top();
        cnt++;
    }
    cout << cnt;
}