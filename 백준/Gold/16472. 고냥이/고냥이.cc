#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    vector<int> count(26, 0);
    int left = 0, right = 0, distinct = 0, max_length = 0;

    while (right < s.size()) {
        if (count[s[right] - 'a'] == 0)
            distinct++;
        count[s[right] - 'a']++;

        while (distinct > n) {
            count[s[left] - 'a']--;
            if (count[s[left] - 'a'] == 0)
                distinct--;
            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length << endl;
}
