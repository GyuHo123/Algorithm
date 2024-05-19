#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 500001

using namespace std;

ll k, n, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> t;

    ll arr[n + 1];

    stack<int> smaller; queue<int> bigger;

    loop(i, 1, n){
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    loop(i, 1, n){
        if(arr[i] >= t) bigger.push(arr[i]);
        else smaller.push(arr[i]);
    }
    loop(i, 1, k){
        if(!smaller.empty()){
            t += smaller.top(); smaller.pop();
        }
        while(!bigger.empty() && bigger.front() < t){
            smaller.push(bigger.front());
            bigger.pop();
        }
    }
    cout << t;
}