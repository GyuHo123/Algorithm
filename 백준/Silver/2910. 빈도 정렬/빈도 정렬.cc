#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

static map<int, int> ind;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) return ind[a.first] < ind[b.first];
    return a.second > b.second;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c; map<int, int> m;

    cin >> n >> c;

    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        m[temp]++;
        if(ind[temp] == 0) ind[temp] = i+1;
    }
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    for(pair<int, int> x : vec){
        for(int i = 0; i < x.second; i++){
            cout << x.first << " ";
        }
    }
}