#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, time[4] = {4, 6, 4, 10};
    map<string, int> m;
    set<string> s;
    bool b1 = true;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < 4; j++){
            for(int k = 0; k < 7; k++){
                string name; cin >> name;
                if(name == "-") continue;
                s.insert(name);
                m[name] += time[j];
            }
        }
    }
    for(string ss : s){
        for(string sss : s){
            if(abs(m[ss] - m[sss]) > 12) b1 = false;
        }
    }
    if(b1) cout << "Yes"; else cout << "No";
}