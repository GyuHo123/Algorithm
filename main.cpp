#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, k;

    string s[2][100], s1;

    char eq;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s[0][i] >> eq >> s[1][i];
    }

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> s1;
            for(int l = 0; l < n; l++)
            if(s1 == s[0][l])
            {
                s1 = s[1][l];
                cout << s1 << " ";
            }
        }
        cout << "\n";
    }
}
