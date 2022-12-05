#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string str[n];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    for(int i = 0; i < n; i++){
        int length = str[i].size();
        char temp[length]; std::reverse_copy(str[i].begin(), str[i].end(), temp);
        string temp1;
        for(int i = 0; i < length; i++){
            temp1 += temp[i];
        }

        if(temp1 == str[i]) {
            cout << str[i].size() << " " << str[i][(str[i].size()-1)/2]; break;
        }
        else for(int j = i+1; j < n; j++){
            if(temp1 == str[j]) {
                cout << str[i].size() << " " << str[i][(str[i].size()-1)/2]; break;
            }
        }
    }
}