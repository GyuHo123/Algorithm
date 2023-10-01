#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long

using namespace std;

int t;
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        if(num < 10){
            cout << 1 << endl;
            continue;
        }
        
        ans.clear();
        
        for(int i = 9; i >= 2; i--){
            while(!(num % i)){
                num /= i;
                ans.push_back(i);
            }
        }
        
        if(num != 1) {
            cout << -1 << endl; 
            continue;
        }
	    cout << ans.size() << endl;
    }
}