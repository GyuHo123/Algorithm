#include<bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while (cin >> x) {
        x *= 10000000;
        int n;
        cin >> n;
        vector<int> pieces(n);
        loop(i, 0, n - 1) {
            cin >> pieces[i];
        }
        
        sort(pieces.begin(), pieces.end());

        int start = 0, end = n - 1;
        bool found = false;

        while (start < end) {
            if (pieces[start] + pieces[end] == x) {
                cout << "yes " << pieces[start] << ' ' << pieces[end] << endl;
                found = true;
                break;
            } else if (pieces[start] + pieces[end] < x)
                start++;
            else
                end--;
        }

       if (!found)
           cout << "danger" << endl; 
    }
}
