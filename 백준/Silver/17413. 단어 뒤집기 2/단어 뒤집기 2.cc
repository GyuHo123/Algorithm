#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void pop(stack<char> &s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    stack<char> stk;

    bool brace = false;

    getline(cin, str);

    for (char ch: str) {
        if (ch == '<') {
            pop(stk);
            brace = true;
            cout << ch;
        }
        else if (ch == '>') {
            cout << ch; brace = false;
        }
        else if (ch == ' '){
            pop(stk);
            cout << ch;
        }
        else if(brace) cout << ch;
        else stk.push(ch);
    }
    pop(stk);
    cout << endl;
}