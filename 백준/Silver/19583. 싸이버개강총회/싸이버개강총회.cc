#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long
#define MAXN 1000001
using namespace std;

string sTime, eTime, qTime, uTime, name;

int cnt;

set<string> s1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sTime >> eTime >> qTime;

    while (!cin.eof()) {
        cin >> uTime >> name;
        if (uTime <= sTime) {
            s1.insert(name);
        }
        if (uTime >= eTime && qTime >= uTime) {
            if (s1.find(name) != s1.end()) {
                cnt++;
                s1.erase(name);
            }
        }
    }
    cout << cnt;
}