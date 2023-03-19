#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001
using namespace std;

int n;
string name, status;
vector<string> nowIn;

set<string> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> name >> status;
        if (status == "enter") s.insert(name);
        else s.erase(name);
    }
    for(string x : s) nowIn.push_back(x);
    sort(nowIn.begin(), nowIn.end());
    for(int i = s.size() - 1; i >= 0; i--) cout << nowIn[i] << endl;
}