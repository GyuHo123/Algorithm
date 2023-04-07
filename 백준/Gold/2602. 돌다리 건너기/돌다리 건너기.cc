#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string str, strA, strD;
int dp[21][101][2]; // dp[idx][pos][is_devil] : idx번째 문자가 두루마리 문자열(str)에 있고, pos번째 돌이 현재 다리에 있을 때, 현재 is_devil 상태(악마의 돌다리인 경우 true, 천사의 돌다리인 경우 false)에서 가능한 방법의 수

int findWays(int idx, int pos, bool is_devil) {
    if (idx == str.length()) {
        return 1;
    }
    if (pos == strA.length()) {
        return 0;
    }
    int &result = dp[idx][pos][is_devil];
    if (result != -1) {
        return result;
    }
    result = 0;
    string &current_bridge = is_devil ? strD : strA;
    for (int i = pos; i < current_bridge.length(); i++) {
        if (current_bridge[i] == str[idx]) {
            result += findWays(idx + 1, i + 1, !is_devil);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str >> strD >> strA;
    memset(dp, -1, sizeof(dp));

    int res = findWays(0, 0, true) + findWays(0, 0, false);
    cout << res << endl;

    return 0;
}
