#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, temp;
    string s;

    cin >> m;

    set<int> set1;

    while(m--){
        cin >> s;
        if(s == "all"){
            for(int i = 1; i <= 20; i++) set1.insert(i);
            continue;
        }
        if(s == "empty") {
            set1.clear();
            continue;
        }
        cin >> temp;
        if(s == "add") set1.insert(temp);
        if(s == "check"){
            if(set1.find(temp) == set1.end()) cout << 0 << endl;
            else cout << 1 << endl;
        }
        if(s == "remove") set1.erase(temp);
        if(s == "toggle"){
            if(set1.find(temp) == set1.end()) set1.insert(temp);
            else set1.erase(temp);
        }
    }
}
