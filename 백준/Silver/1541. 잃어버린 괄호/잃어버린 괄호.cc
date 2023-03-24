#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int negative = 0, sum = 0;
    string str, str1;
    cin >> str;

    for(auto x : str) {

        if (isdigit(x)) {
            str1 += x;
        } else if (!isdigit(x) || str[str.size() - 1] == x) {
            if (negative) sum += -1 * stoi(str1);
            else sum += stoi(str1);
            str1.clear();
        }
        if (x == '-') negative = 1;

    }
    if(str.empty()){
        cout << str1; exit(0);
    }
    if(negative) cout << sum - stoi(str1);
    else cout << sum + stoi(str1);
}