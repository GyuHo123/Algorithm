#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001
using namespace std;

string n;
int k, l;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

map<string, int> m;
vector<pair<int, string>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l;

    loop(i, 1, l){
        cin >> n;
        m[n] = i;
    }
    for(auto x : m){
        string s = x.first;
        int a = x.second;
        v.push_back({a, s});
    }
    sort(v.begin(), v.end());
    loop(i, 0, v.size()){
        if(i == k) break;
        else{
            cout << v[i].second << endl;
        }
    }
}