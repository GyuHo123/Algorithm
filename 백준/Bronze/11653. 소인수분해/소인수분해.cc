#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> ans;

    while(true) {
        if(n == 1) break;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                n /= i;
                break;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}