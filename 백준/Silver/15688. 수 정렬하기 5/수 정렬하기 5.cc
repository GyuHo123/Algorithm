#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, num1; vector<int> num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num1; num.push_back(num1);
    }
    sort(num.begin(), num.end());

    for(int i = 0; i < n; i++){
        cout << num[i] << endl;
    }
}