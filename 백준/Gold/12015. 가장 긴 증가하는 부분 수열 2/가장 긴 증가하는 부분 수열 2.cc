#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long

using namespace std;

int n, res, temp;
vector<int> v1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v1.push_back(res);

    loop(i, 1, n){
        cin >> temp;
        if(temp > v1.back()){
            res++;
            v1.push_back(temp);
        }
        else{
            auto it = lower_bound(v1.begin(), v1.end(), temp);
            *it = temp;
        }
    }
    cout << res;
}