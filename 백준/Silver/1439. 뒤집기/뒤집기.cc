#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 201

using namespace std;

string str;
int cnt0, cnt1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    LOOP(i, 0, str.size()){
        if(str[i] == '0' && str[i] != str[i - 1]){
            cnt0++;
        }
        else if(str[i] == '1' && str[i] != str[i - 1]){
            cnt1++;
        }
    }
    cout << min(cnt0, cnt1);
}
