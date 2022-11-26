#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n, x;

    cin >> k; vector<vector<int>> num;
    vector<int> num1, gap1;
    vector<vector<int>> gap;

    for(int i = 0; i < k; i++){
        cin >> n;
        num1.clear();
        for(int j = 0; j < n; j++){
            cin >> x; num1.push_back(x);
        }
        num.push_back(num1);
    }

    for(int i = 0; i < k; i++){
        sort(num[i].begin(), num[i].end());
    }

    for(int i = 0; i < k; i++){
        gap1.clear();
        for(int j = 0; j < num[i].size()-1; j++){
            x = num[i][j]-num[i][j+1];
            if(x < 0) x *= -1;
            gap1.push_back(x);
        }
        gap.push_back(gap1);
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < gap[i].size(); j++){
            sort(gap[i].begin(), gap[i].end());
        }
    }

    for(int i = 0; i < k; i++){
        cout << "Class " << i+1 << endl;
        cout << "Max " << num[i][num[i].size()-1] << ", Min " << num[i][0] << ", Largest gap " << gap[i][gap[i].size()-1] << endl;
    }
}