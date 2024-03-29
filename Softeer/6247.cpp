#include <iostream>
#include <map>
#include <algorithm>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 50001

using namespace std;

int n, q, maxn;
map<int, int> m1;
int arr[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    loop(i, 1, n){
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }

    sort(arr, arr + n + 1);

    loop(i, 1, n){
        m1[arr[i]] = i;
    }

    loop(i, 1, q){
        int temp;
        cin >> temp;
        if(!m1[temp]){
            cout << 0 << endl;
            continue;
        }
        cout << (m1[temp] - 1) * (n - m1[temp]) << endl;
    }
}
