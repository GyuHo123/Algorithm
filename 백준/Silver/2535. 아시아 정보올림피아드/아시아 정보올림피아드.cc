#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int cnt1[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<tuple<int, int, int>> v;
    tuple<int, int, int> c;
    int prize = 0, n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        c = make_tuple(z, x, y);
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(prize == 3){
            break;
        }
        if(cnt1[get<1>(v[i])] == 2){
            continue;
        }
        cout << get<1>(v[i]) << " " << get<2>(v[i]) << endl;
        cnt1[get<1>(v[i])]++;
        prize++;
    }
}