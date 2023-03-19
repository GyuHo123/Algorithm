#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001
using namespace std;

bool b1;
int n, m, temp;
string str, str1, str2;
map<string, vector<string>> m1;
map<string, string> m2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    loop(i, 1, n){
        vector<string> v;
        cin >> str >> temp;
        loop(i, 1, temp){
            cin >> str1;
            v.push_back(str1);
            loop(j, 1, temp){
                m2[str1] = str;
            }
        }
        m1[str] = v;
    }

    loop(i, 1, m){
        cin >> str;
        cin >> b1;
        if(!b1) {
            sort(m1[str].begin(), m1[str].end());
            loop(i, 0, m1[str].size() - 1){
                cout << m1[str][i] << endl;
            }
        }
        else cout << m2[str] << endl;
    }
}