#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> s;

    int n, cnt = 0;

    string s1;

    cin >> s1;
    s.push_back(s1);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s1, s.push_back(s1);
    }
    for(int i = 1; i <= n; i++){
        if(s.front() == s[i]){
            cnt++;
        }
    }
    cout << cnt;
}
