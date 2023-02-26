#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

map<int, string> m;
map<string, int> m1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n, n1, key;

    cin >> n >> n1;

    loop(i, 1, n) {
        cin >> str;
        m[i] += str;
        m1[str] += i;
    }

    loop(i, 1, n1) {
        cin >> str;
        if (isdigit(str[0])) {
            key = stoi(str);
            cout << m[key] << endl;
        } else {
            cout << m1[str] << endl;
        }
    }

}

