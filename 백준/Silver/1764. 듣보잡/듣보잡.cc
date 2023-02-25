#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)

using namespace std;

string str;

map<string, int> map1;

vector<string> v;

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n){
        cin >> str;
        map1[str]++;
    }

    loop(i, 1, m){
        cin >> str;
        ++map1[str];
        if(map1[str] > 1) v.push_back(str);
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    
    LOOP(i, 0, v.size()) cout << v[i] << endl;

}
