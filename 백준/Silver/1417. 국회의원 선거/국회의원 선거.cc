#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, temp, cnt = 0, max, dasom; vector<int> gook1;

    cin >> n >> dasom;
    if(n == 1) { cout << 0; return 0;}
    for(int i = 0; i < n-1; i++){
        cin >> temp; gook1.push_back(temp);
    }
    sort(gook1.begin(), gook1.end());
    max = gook1.back();
    while(true){
        if(dasom > max) { cout << cnt; return 0;}
        dasom++; cnt++; --gook1.back(); sort(gook1.begin(), gook1.end()); max = gook1.back();
    }
}