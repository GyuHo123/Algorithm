#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1001

using namespace std;

int arr[MAXN];
vector<int> sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    LOOP(i, 0, n) {
        cin >> arr[i];
    }
    
    LOOP(i, 0, n) {
        LOOP(j, i, n) {
            sum.push_back(arr[i] + arr[j]);
        }
    }
    
    sort(arr, arr + n);
    
    sort(sum.begin(), sum.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int a = arr[i] - arr[j];
            bool exist = binary_search(sum.begin(), sum.end(), a);
            if (exist) {
                cout << arr[i] << "\n";
                return 0;
            }
        }
    }
}
