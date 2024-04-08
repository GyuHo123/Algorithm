#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    int tc = 1;
    while(n--){
        vector<int> v1(3);
        int cnt = 0;
        loop(i, 0, 2){
            cin >> v1[i];
        }
        for(int i = 3; i >= 0, i--;){
            int idx = lower_bound(v1.begin(), v1.end(), v1[i]) - v1.begin();
            if(i == idx && i == 0) continue;
            if(i == idx && v1[i - 1] < v1[i]) continue;
            while(1){
                if(v1[i - 1] < v1[i]) break;
                v1[i - 1] -= 1;
                cnt++;
            }
        }
        if(v1[0] <= 0){
            cout << "#" << tc++ << " " << -1 << endl;
        }
        else{
            cout << "#" << tc++ << " " << cnt << endl;
        }
    }
}