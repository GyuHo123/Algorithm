#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> stk;
    string str;
    int cnt = 0;
    
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stk.push(str[i]);
        } else if (str[i] == ')' and str[i - 1] == '(') {
            stk.pop();
            cnt += stk.size();
        } else {
            cnt++;
            stk.pop();
        }
    }
    cout << cnt << endl;
}