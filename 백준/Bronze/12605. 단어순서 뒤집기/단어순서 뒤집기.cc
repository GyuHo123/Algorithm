#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string solve(int k, string s){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; string s;

    cin >> n;

    for(int i = 1; i <= n+1; i++){
        getline(cin, s);
        vector<string> str;

        if(i == 1) continue;
        string temp, s1;
        istringstream ss(s);
        vector<string> v;

        while(getline(ss, temp, ' ')){
            v.push_back(temp);
        }

        for(int i = v.size()-1; i >= 0; i--){
            s1 += v[i] + " ";
        }
        cout << "Case #" << i-1 << ": " << s1 << endl;
    }
}