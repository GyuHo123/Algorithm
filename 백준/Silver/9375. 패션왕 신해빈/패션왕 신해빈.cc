#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001
using namespace std;

int t, res = 1, sum, n;
string str1, str2;
map<string, int> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        loop(i, 1, n){
            cin >> str1 >> str2;
            m[str2]++;
        }
        for(auto x : m){
            res *= x.second + 1;
        }
        cout << res - 1 << endl;
        m.clear(); res = 1;
    }
}