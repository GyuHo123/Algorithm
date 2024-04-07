#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 100001

using namespace std;

struct p{
    int x, y;
};

int arr[MAXN], n, sum, min1 = INT_MAX;
p ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 0, n - 1){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int start = 0, end = n - 1;

    while(start < end) {
        sum = arr[start] + arr[end];
        if (abs(sum) < min1) {
            min1 = abs(sum);
            ans.x = arr[start], ans.y = arr[end];
            if (!sum) break;
        }
        if (sum < 0) start++;
        else end--;
    }
    cout << ans.x << " " << ans.y;
}