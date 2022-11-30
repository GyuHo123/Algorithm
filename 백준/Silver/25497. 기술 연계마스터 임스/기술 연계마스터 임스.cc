#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(string s){
    int cnt = 0, cnt1 = 0, res = 0;
    for(char c : s){
        if(c == 'S'){
            cnt++;
            continue;
        }
        else if(c == 'L'){
            cnt1++;
            continue;
        }
        else if(c == 'R' && cnt1 <= 0){
            break;
        }
        else if(c == 'K' && cnt <= 0){
            break;
        }
        else if(c == 'K') cnt--;
        else if(c == 'R') cnt1--;
        res++;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; string s; cin >> n;

    cin >> s;
    solve(s);
}