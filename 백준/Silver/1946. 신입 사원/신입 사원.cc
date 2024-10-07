#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001

using namespace std;

struct p{
    int x, y;
};

bool cmp(p t1, p t2){
    return t1.x < t2.x; 
}

int t, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        p t1;
        vector<p> v1;

        cin >> n;

        int cnt = 1;

        loop(i, 1, n){
            cin >> t1.x >> t1.y;
            v1.push_back(t1);
        }

        sort(v1.begin(), v1.end(), cmp);

        int minInterviewRank = v1[0].y;
        
        loop(i, 1, n - 1){
            if(v1[i].y < minInterviewRank){
                cnt++;
                minInterviewRank = v1[i].y;
            }
        }

        cout << cnt << endl;
    }
}