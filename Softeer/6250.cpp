#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001
using namespace std;

int n, t;
vector<int> v1, v2(MAXN), arr, v_sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    loop(i, 1, 3) {
        v1.clear();
        loop(j, 1, n) {
            cin >> t;
            v1.push_back(t);
            if(i == 1){
                v2.push_back(t);
            }
            else{
                v2[j + 1] += t;
            }
        }
        arr = v1;
        sort(arr.begin(), arr.end(), greater<int>());
        for (auto t : v1) {
            cout << lower_bound(arr.begin(), arr.end(), t, greater<int>()) - v1.begin() + 1 << " ";
        }
        cout << endl;
    }
    v_sum = v2;
    sort(v_sum.begin(), v_sum.end(), greater<int>());
    loop(i, 1, n) {
        if (t == 0) break;
        cout << lower_bound(v_sum.begin(), v_sum.end(), t, greater<int>()) - v_sum.begin() + 1 << " ";
    }
}
