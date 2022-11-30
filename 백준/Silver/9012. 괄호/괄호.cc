#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string solve(string s){
    int cnt = 0;
    for(char c : s){
        if(c == '('){
            cnt++;
        }
        else if(c == ')'){
            cnt--;
        }
        if(cnt < 0) {
            return "NO\n";
        }
    }
    if(cnt == 0) return "YES\n";
    else return "NO\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; string s; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        cout << solve(s);
    }
}