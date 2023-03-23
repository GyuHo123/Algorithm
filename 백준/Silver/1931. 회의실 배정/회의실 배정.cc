#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

struct p{
    int start, end;
};

bool cmp(const p p1, const p p2){
    if (p1.end == p2.end)
        return p1.start < p2.start;
    return p1.end < p2.end;
}

int n, temp1, temp2, cnt = 1;

int main(){
    cin >> n;
    vector<p> v;
    while(n--){
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    sort(v.begin(), v.end(), cmp);
    temp1 = v[0].end;
    loop(i, 1, v.size() - 1){
        if(v[i].start >= temp1){
            temp1 = v[i].end;
            cnt++;
        }
    }
    cout << cnt;
}