#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,y,w,h;

    cin >> x >> y;
    cin >> w >> h;

    int preRes1 = min(x, y);
    int preRes2 = min(w - x, h - y);
    cout << min(preRes1, preRes2);

}