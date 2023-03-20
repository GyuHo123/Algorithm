#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s, i < n; i++)

using namespace std;

set<string> s;
string str, temp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    loop(i, 0, str.size() - 1){
        loop(j, i, str.size() - 1){
            temp += str[j];
            s.insert(temp);
        }
        temp = "";
    }
    cout << s.size();
}