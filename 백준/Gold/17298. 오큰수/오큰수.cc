#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define ll long long
#define MAXN 1000001
using namespace std;

stack<int> st;

ll arr[MAXN], ans[MAXN], n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = n - 1; i >= 0; i--){
        cin >> arr[i];
    }
    loop(i, 0, n - 1){
        if(st.empty()){
            st.push(arr[i]);
            ans[i] = -1;
        }
        else{
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else if(!st.empty() && st.top() > arr[i]) ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    for(int i = n - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}